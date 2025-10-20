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

    // iterate through each character in phrase
    for (int i = 0; i < phrase.length(); i++) {
        char symbol = phrase[i];
        bool found = false;

        // iterate through each child node
        for (Node*& child : curr->children) {
            // check if node already exists
            if (symbol == child->c) {
                prev = curr;
                curr = child;
                found = true;

                break;
            }
        }

        // if not, make a new node and add it to the vector just used
        if (!found) {
            prev = curr;
            curr = new Node(phrase[i]);

            prev->children.push_back(curr);
        }
    }

    // set the last node as the end of a phrase
    curr->isEnd = true;
}

bool Trie::find(string phrase) {
    Node* curr = root;

    // iterate through each character in the phrase
    for (int i = 0; i < phrase.length(); i++) {
        char symbol = phrase[i];
        bool found = false;

        // iterate through each child node
        for (Node*& child : curr->children) {
            // check to see if character exists among children already
            if (symbol == child->c) {
                curr = child;
                found = true;

                break;
            }
        }

        // if not, return false
        if (!found) {
            return false;
        }
    }

    // if final character is the end of a word, return found (true), otherwise false
    if (curr->isEnd) {
        return true;
    }

    return false;
}