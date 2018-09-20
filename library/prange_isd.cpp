#include "prange_isd.h"

using namespace std;

void fisher_yates_shuffle (const vector<int> &src, vector<int> &dst) {
    // copy src vector to dst vector
    dst = src;

    // compute random permutation of dst vector
    for(int i=dst.size()-1; i>0; i--) {
        int idx = (rand() % (i+1));
        swap(dst[idx], dst[i]);
    }
}

void permute_matrix_columns (const vector<bitset<N> > &src, vector<bitset<N> > &dst, vector<int> &new_pos){
    bitset<N> tmp_b;
    dst.clear();
    // initialize positions vector as (0, 1, 2, ...)
    vector<int> start_pos;
    for (int i=0; i<N; i++)
        start_pos.push_back(i);

    // compute random positions
    fisher_yates_shuffle(start_pos, new_pos);

    // compute new matrix according to new positions
    for (int i=0; i<N-K; i++) {
        for (int j=0; j<N; j++)
            tmp_b[j] = src[i][new_pos[j]];
        dst.push_back(tmp_b);
    }
}

bool gaussian_elimination (const vector<bitset<N> > &h, const bitset<N-K> &s, bitset<N-K> &sigma) {
    vector<bitset<N> > tmp_h;
    tmp_h = h;
    sigma = s;
    bool tmp_b;

    // apply Gaussian elimination
    for (int col=K, row=0; col<N && row<N-K; col++) {
        for (int i=row; i<N-K; ++i)
            if (tmp_h[i][col]) {
                // swap rows
                swap (tmp_h[i], tmp_h[row]);
                // swap corresponding syndrome bits
		        tmp_b = (bool)sigma[row];
                sigma[row] = (bool)sigma[i];
                sigma[i] = tmp_b;
                break;
            }
        if (!tmp_h[row][col])
            continue;
        for (int i=0; i<N-K; ++i)
            if (i != row && tmp_h[i][col]) {
                // xor rows
                tmp_h[i] ^= tmp_h[row];
                // xor corresponding syndrome bits
                if(sigma[row])
                    sigma[i].flip();
            }
        ++row;
    }

    // return true if the resulting matrix has full rank,
    // i.e., it has an identity matrix on the right side,
    // return false otherwise
    for (int col=K, row=0; row<N-K && col<N; col++, row++) {
        if (!tmp_h[row][col])
            return false;
    }
    return true;
}

void randomize (const vector<bitset<N> > &h, const bitset<N-K> &s, vector<int> &p, bitset<N-K> &sigma) {
    vector<bitset<N> > hp;
    bool full_rank = false;
    while (!full_rank) {
        permute_matrix_columns(h, hp, p);
        full_rank = gaussian_elimination(hp, s, sigma);
    }
}

bool search_prange (const bitset<N-K> &sigma, int error_weight, bitset<N> &epsilon) {
    int sigma_weight = sigma.count();
    bool success = (sigma_weight == error_weight);
    epsilon.reset();
    if (success)
        for (int i=0; i<N-K; i++)
            epsilon[K+i] = sigma[i];
    return success;
}

void isd (const vector<bitset<N> > &h, const bitset<N> &y, int w, bitset<N> &e) {
    bitset<N-K> s;
    bitset<N-K> sig;
    bitset<N> eps;
    vector<int> p;
    bool success = false;

    srand(time(NULL));

    // matrix vector multiplication
    bitset<N> tmp;
    for (int i=0; i<N-K; i++) {
        tmp = h[i] & y;
        s[i] = (tmp.count() % 2);
    }

    while (!success) {
        randomize (h, s, p, sig);
        success = search_prange (sig, w, eps);
    }

    // reorder error vector
    for (int i=0; i<N; i++)
        e[p[i]] = eps[i];
}
