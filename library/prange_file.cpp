#include "prange_file.h"

using namespace std;

void read_bitsetN_vectors_from_file(const string file_path, vector<bitset<N> > &dst) {
    ifstream file;
    string line;
    file.open(file_path);
    if (file.is_open()) {
        while (getline (file,line)) {
            reverse(line.begin(), line.end());
            bitset<N> bst (line);
            dst.push_back(bst);
        }
        file.close();
    }
    else
        cout << "Unable to open" << file_path << "file";
}

void read_bitsetK_vectors_from_file(const string file_path, vector<bitset<K> > &dst) {
    ifstream file;
    string line;
    file.open(file_path);
    if (file.is_open()) {
        while (getline (file,line)) {
            reverse(line.begin(), line.end());
            bitset<K> bst (line);
            dst.push_back(bst);
        }
        file.close();
    }
    else
        cout << "Unable to open" << file_path << "file";
}
