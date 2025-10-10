#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

bool readFile(string path, vector<string>& v) {
    ifstream file(path);

    if (!file) {
        return false;
    }

    string line;
    while (getline(file, line)) {
        v.push_back(line);
    }

    return true;
}

int main() {
    vector<string> passwords;

    if (!readFile("../passwords.txt", passwords)) {
        cerr << "file couldn't be opened" << endl;
        return 1;
    }

    return 0;
}