//
// Created by kiran on 10/10/2025.
//

#include "trie.h"

Trie::Trie() {
    root = nullptr;
}


void Trie::insert(string phrase) {
    Node* curr = root;
    Node* prev = nullptr;

    for (int i = 0; i < phrase.length(); i++) {
        char symbol = phrase[i];
        bool found = false;

        for (Node*& child : curr->children) {
            if (symbol == child->c) {
                prev = curr;
                curr = child;
                found = true;

                break;
            }
        }

        if (!found) {
            prev = curr;
            curr = new Node(phrase[i]);

            prev->children.push_back(curr);
        }
    }

    curr->isEnd = true;
}

bool Trie::find(string phrase) {
    Node* curr = root;

    for (int i = 0; i < phrase.length(); i++) {
        char symbol = phrase[i];
        bool found = false;

        for (Node*& child : curr->children) {
            if (symbol == child->c) {
                curr = child;
                found = true;

                break;
            }
        }

        if (!found) {
            return false;
        }
    }

    if (curr->isEnd) {
        return true;
    }

    return false;
}