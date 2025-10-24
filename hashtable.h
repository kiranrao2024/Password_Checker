//
// Created by kiran on 10/23/2025.
//

#pragma once
#include <string>
#include <vector>
using namespace std;

class Hashtable {
    // private variables
    double loadFactor = 0;
    float threshold = 1.5;
    size_t size = 0;
    size_t capacity = 16;
    vector<vector<string>> table;

    // public functions
public:
    Hashtable(const vector<string>& passwords);
    void insert(const string& phrase);
    bool find(const string& phrase) const;
    void resize();
    size_t generateHash(const string& phrase) const;
    void calculateLoadFactor();
};
