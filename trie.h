//
// Created by kiran on 10/10/2025.
//
#pragma once;
#include <vector>
#include <string>
using namespace std;

class Trie {
    // Node class
    struct Node {
        // variables
        char c;
        bool isEnd;
        vector<Node*> children;

        // functions
        Node(char value) {
            c = value;
            isEnd = false;
        }
    };

    // variables
    Node* root = new Node('\0');

public:
    // functions
    Trie(vector<string> passwords);
    void insert(string phrase);
    bool find(string phrase);
};

