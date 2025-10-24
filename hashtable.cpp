//
// Created by kiran on 10/23/2025.
//

#include "hashtable.h"
using namespace std;

Hashtable::Hashtable(const vector<string>& passwords) : table(capacity) {
    for (auto& password : passwords) {
        insert(password);
    }
}

void Hashtable::insert(const string& phrase) {
    // generate hashcode for phrase
    size_t hashcode = generateHash(phrase);

    // check if already in table
    if (!find(phrase)) {
        // if not, add to table
        table[hashcode].push_back(phrase);
        size++;
        calculateLoadFactor();

        // check if rehashing necessary
        if (loadFactor >= threshold) {
            resize();
        }
    }
}

bool Hashtable::find(const string& phrase) const {
    // generate hashcode for phrase
    size_t hashcode = generateHash(phrase);

    // search hash bucket for phrase, if is there return true
    for (size_t i = 0; i < table[hashcode].size(); i++) {
        if (table[hashcode][i] == phrase) {
            return true;
        }
    }

    // otherwise return false
    return false;
}

void Hashtable::resize() {
    vector<vector<string>> temp = move(table);

    table.clear();
    size = 0;
    capacity *= 2;
    table.resize(capacity);

    for (size_t i = 0; i < temp.size(); i++) {
        for (size_t j = 0; j < temp[i].size(); j++) {
            size_t hashcode = generateHash(temp[i][j]);
            table[hashcode].push_back(temp[i][j]);
            size++;
        }
    }

    calculateLoadFactor();
}

size_t Hashtable::generateHash(const string& phrase) const {
    // generate and return the hash code
    return hash<string>{}(phrase) % capacity;
}

void Hashtable::calculateLoadFactor() {
    loadFactor = double(size) / capacity;
}
