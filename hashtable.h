//
// Created by kiran on 10/23/2025.
//

#pragma once
#include <string>
#include <vector>
using namespace std;

class Hashtable {
    // private variables
    float loadFactor;
    float threshold;
    size_t size;
    size_t capacity;
    vector<vector<string>> table;

    // public functions
public:
    Hashtable(vector<string> passwords);
    void insert(string phrase);
    bool find(string phrase);
    void resize();
    size_t hash(const string& phrase);
};
