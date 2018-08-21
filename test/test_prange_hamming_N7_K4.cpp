#include <iostream>
#include <vector>
#include <bitset>
#include "prange_isd.h"

using namespace std;

int main() {
    vector<bitset<N> > h;
    int w = 1;
    bitset<N> e;

    // Hamming (7,4)
    // bitsets are rows of the H matrix
    bitset<N> b0 ("1010101");
    bitset<N> b1 ("1100110");
    bitset<N> b2 ("0001111");

    // N-K bitsets (N bits long)
    h.push_back(b0);
    h.push_back(b1);
    h.push_back(b2);

    // Hamming (7,4) error-free words
    bitset<N> y1 ("1010101");
    bitset<N> y2 ("1110000");
    bitset<N> y3 ("0100101");
    bitset<N> y4 ("1101001");
    bitset<N> y5 ("1001100");

    vector<bitset<N> > yvec;
    yvec.push_back(y1);
    yvec.push_back(y2);
    yvec.push_back(y3);
    yvec.push_back(y4);
    yvec.push_back(y5);

    // Weight 1 errors
    bitset<N> e1 ("1000000");
    bitset<N> e2 ("0100000");
    bitset<N> e3 ("0010000");
    bitset<N> e4 ("0001000");
    bitset<N> e5 ("0000100");
    bitset<N> e6 ("0000010");
    bitset<N> e7 ("0000001");

    vector<bitset<N> > evec;
    evec.push_back(e1);
    evec.push_back(e2);
    evec.push_back(e3);
    evec.push_back(e4);
    evec.push_back(e5);
    evec.push_back(e6);
    evec.push_back(e7);


    cout << "Test ID\tOutcome\tExpected\tResult" << endl;

    for (int i=0; i<5; i++) {
        for (int j=0; j<N; j++) {
            isd (h, yvec[i]^evec[j], 1, e);
            cout << "1T" << i << "." << j << "\t" << ((e == evec[j]) ? "OK" : "NO") << "\t" << e << "\t\t" << evec[j] << endl;
        }
    }

    return 0;
}
