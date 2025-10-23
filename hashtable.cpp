//
// Created by kiran on 10/23/2025.
//

#include "hashtable.h"
using namespace std;

Hashtable::Hashtable(vector<string> passwords) {

}

void Hashtable::insert(string phrase) {
    // generate hashcode for phrase
    size_t hashcode = hash(phrase);

    // check if already in table
    if (!find(phrase)) {
        // if not, add to table
        table[hashcode].push_back(phrase);

        // TODO: check if rehashing necessary
    }
}

bool Hashtable::find(string phrase) {
    // generate hashcode for phrase
    size_t hashcode = hash(phrase);

    // search hash bucket for phrase, if is there return true
    for (int i = 0; i < table[hashcode].size(); i++) {
        if (table[hashcode][i] == phrase) {
            return true;
        }
    }

    // otherwise return false
    return false;
}

void Hashtable::resize() {

}

size_t Hashtable::hash(const string& phrase) {
    size_t hashcode = 0;

    // generate the hash code
    for (unsigned char c : phrase) {
        hashcode = (hashcode * 37 + int(c)) % capacity;
    }

    return hashcode;
}