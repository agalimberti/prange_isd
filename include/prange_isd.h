#ifndef PRANGEISD_H
#define PRANGEISD_H

#include <iostream>
#include <vector>
#include <bitset>
#include <ctime>

using namespace std;

void fisher_yates_shuffle (const vector<int> &src, vector<int> &dst);

void permute_matrix_columns (const vector<bitset<N> > &src, vector<bitset<N> > &dst, vector<int> &new_pos);

bool gaussian_elimination (const vector<bitset<N> > &h, const bitset<N-K> &s, bitset<N-K> &sigma);

void randomize (const vector<bitset<N> > &h, const bitset<N-K> &s, vector<int> &p, bitset<N-K> &sigma);

bool search_prange (const bitset<N-K> &sigma, int error_weight, bitset<N> &epsilon);

void isd (const vector<bitset<N> > &h, const bitset<N> &y, int w, bitset<N> &e);

#endif // PRANGEISD_H