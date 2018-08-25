#include "prange_isd.h"
#include "prange_file.h"

int main() {
    vector<bitset<N> > h;
    vector<bitset<K> > xvec;
    vector<bitset<K> > g;
    vector<bitset<N> > evec;
    bitset<N> c;
    bitset<N> e;
    bitset<K> tmp;
    int w;

    string h_file = "dat/hamming_N7_K4_h.dat";
    string x_file = "dat/hamming_N7_K4_x.dat";
    string g_file = "dat/hamming_N7_K4_g.dat";
    string e_file = "dat/hamming_N7_K4_e.dat";

    // Hamming(7, 4)
    read_bitsetN_vectors_from_file (h_file, h);
    read_bitsetK_vectors_from_file (x_file, xvec);
    read_bitsetK_vectors_from_file (g_file, g);
    read_bitsetN_vectors_from_file(e_file, evec);

    cout << "TestID\tOutcome\tExpected\tResult" << endl;

    for (int i=0; i<xvec.size(); i++) {
        // c = G * x
        for (int j=0; j<N; j++) {
            tmp = g[j] & xvec[i];
            c[j] = (tmp.count() % 2);
        }

        for (int j=0; j<evec.size(); j++) {
            w = evec[j].count();
            isd (h, c^evec[j], w, e);
            cout << w << "T" << i << "." << j << "\t" << ((e == evec[j]) ? "OK" : "NO ") << "\t" << e << "\t\t" << evec[j] << endl;
        }
    }

    return 0;
}
