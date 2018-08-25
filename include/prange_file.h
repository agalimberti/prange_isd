#ifndef PRANGEREADFILE_H
#define PRANGEREADFILE_H

#include <bitset>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

/*
H matrix file must be structured as:
            col 0   col 1   ... col N-1
row 0
row 1
...
row N-K-1

Codewords/errors file must be structured as:
            bit 0   bit 1   ... bit N-1
codeword 0
codeword 1
...
*/
void read_bitsetN_vectors_from_file(const string file_path, vector<bitset<N> > &dst);

/*
G matrix file must be structured as:
            col 0   col 1   ... col K-1
row 0
row 1
...
row N-1

Words file must be structured as:
            bit 0   bit 1   ... bit K-1
word 0
word 1
...
*/
void read_bitsetK_vectors_from_file(const string file_path, vector<bitset<K> > &dst);

#endif // PRANGEREADFILE_H