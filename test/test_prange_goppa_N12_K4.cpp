#include <iostream>
#include <vector>
#include <bitset>
#include "prange_isd.h"

using namespace std;

int main() {
    vector<bitset<N> > h;
    vector<bitset<K> > g;
    int w = 1;
    bitset<N> e;

    // Goppa[12, 4, ≥5]
    // bitsets are rows of the H matrix
    bitset<N> b0 ("100000010100");
    bitset<N> b1 ("000100001110");
    bitset<N> b2 ("111010110000");
    bitset<N> b3 ("000011100011");
    bitset<N> b4 ("111101001111");
    bitset<N> b5 ("011100000100");
    bitset<N> b6 ("101010000010");
    bitset<N> b7 ("100111011110");

    // N-K bitsets (N bits long)
    h.push_back(b0);
    h.push_back(b1);
    h.push_back(b2);
    h.push_back(b3);
    h.push_back(b4);
    h.push_back(b5);
    h.push_back(b6);
    h.push_back(b7);

    // K-bit words
    bitset<K> x1 ("0101");
    bitset<K> x2 ("1100");
    bitset<K> x3 ("1111");
    bitset<K> x4 ("0000");
    bitset<K> x5 ("0010");

    vector<bitset<K> > xvec;
    xvec.push_back(x1);
    xvec.push_back(x2);
    xvec.push_back(x3);
    xvec.push_back(x4);
    xvec.push_back(x5);

    // bitsets are columns of the G matrix
    bitset<K> ba ("1100");
    bitset<K> bb ("1111");
    bitset<K> bc ("1011");
    bitset<K> bd ("0110");
    bitset<K> be ("1111"); 
    bitset<K> bf ("1000");
    bitset<K> bg ("0001");
    bitset<K> bh ("1010");
    bitset<K> bi ("0010");
    bitset<K> bj ("0001");
    bitset<K> bk ("1000"); 
    bitset<K> bl ("0100");

    // N bitsets (K bits long)
    g.push_back(ba);
    g.push_back(bb);
    g.push_back(bc);
    g.push_back(bd);
    g.push_back(be);
    g.push_back(bf);
    g.push_back(bg);
    g.push_back(bh);
    g.push_back(bi);
    g.push_back(bj);
    g.push_back(bk);
    g.push_back(bl);

    // Weight 1 errors
    bitset<N> e1 ("100000000000");
    bitset<N> e2 ("010000000000");
    bitset<N> e3 ("001000000000");
    bitset<N> e4 ("000100000000");
    bitset<N> e5 ("000010000000");
    bitset<N> e6 ("000001000000");
    bitset<N> e7 ("000000100000");
    bitset<N> e8 ("000000010000");
    bitset<N> e9 ("000000001000");
    bitset<N> ea ("000000000100");
    bitset<N> eb ("000000000010");
    bitset<N> ec ("000000000001");

    vector<bitset<N> > e1vec;
    e1vec.push_back(e1);
    e1vec.push_back(e2);
    e1vec.push_back(e3);
    e1vec.push_back(e4);
    e1vec.push_back(e5);
    e1vec.push_back(e6);
    e1vec.push_back(e7);
    e1vec.push_back(e8);
    e1vec.push_back(e9);
    e1vec.push_back(ea);
    e1vec.push_back(eb);
    e1vec.push_back(ec);

    cout << "Test ID\tOutcome\tExpected\tResult" << endl;

    bitset<N> y;
    bitset<K> tmp;
    for (int i=0; i<4; i++) {
        // y = x * G
        bitset<N> y;
        for (int c=0; c<N; c++) {
            tmp = g[c] & xvec[i];
            y[c] = (tmp.count() % 2);
        }

        for (int j=0; j<N; j++) {
            isd (h, y^e1vec[j], 1, e);
            cout << "1T" << i << "." << j << "\t" << ((e == e1vec[j]) ? "OK" : "NO ") << "\t" << e << "\t" << e1vec[j] << endl;
        }
    }

    // Weight 2 errors
    bitset<N> ex ("1001000");
    bitset<N> ey ("0000110");
    bitset<N> ez ("0010010");
    bitset<N> ew ("0100001");

    vector<bitset<N> > e2vec;
    e2vec.push_back(ex);
    e2vec.push_back(ey);
    e2vec.push_back(ez);
    e2vec.push_back(ew);

    for (int i=0; i<4; i++) {
        // y = x * G
        bitset<N> y;
        for (int c=0; c<N; c++) {
            tmp = g[c] & xvec[i];
            y[c] = (tmp.count() % 2);
        }

        for (int j=0; j<4; j++) {
            isd (h, y^e2vec[j], 2, e);
            cout << "2T" << i << "." << j << "\t" << ((e == e2vec[j]) ? "OK" : "NO") << "\t" << e << "\t" << e2vec[j] << endl;
        }
    }

    return 0;
}
