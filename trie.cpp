//
// Created by kiran on 10/10/2025.
//

#include "trie.h"

Trie::Trie() {
    root = nullptr;
}


void Trie::insert(string phrase) {
    Node* curr = root;

    for (int i = 0; i < phrase.length(); i++) {
        char symbol = phrase[i];

        for (Node*& child : curr->children) {
            if (symbol == child->c) {
                curr = child;
            }
        }

        curr = new Node(phrase[i]);
    }
}

bool Trie::find(string phrase) {

}