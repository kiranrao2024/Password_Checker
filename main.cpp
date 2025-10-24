#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "hashtable.h"
#include "trie.h"
using namespace std;

bool readFile(const string& path, vector<string>& v) {
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

int getChoice() {
    int choice;
    cin >> choice;

    return choice;
}

string getInput() {
    string input;
    cin >> input;

    return input;;
}

void printMenu() {
    cout << "Welcome to password checker!" << endl;
    cout << "-----" << endl;
    cout << "1. View the N most commonly brute forced passwords" << endl;
    cout << "2. Determine if a password is one of the 100,000 most commonly brute forced passwords" << endl;
    cout << "3. Exit Program" << endl;
    cout << endl;
}

void handleInput(int choice, Trie &trie, Hashtable &hashtable) {
    if (choice == 1) {
        // print top N most frequently brute forced passwords

    } else if (choice == 2) {
        // check if entered password is in list of passwords
        cout << "Enter the password you want to check: ";
        string input = getInput();

        cout << "Press 1 to search using a trie, Press 2 to search using a hashmap: ";
        int choice = getChoice();
        if (choice == 1) {
            // search using trie
            bool found = trie.find(input);
            if (found) {
                cout << "found" << endl;
            } else {
                cout << "not found" << endl;
            }
        } else if (choice == 2) {
            // search using hashmap
            bool found = hashtable.find(input);
            if (found) {
                cout << "found" << endl;
            } else {
                cout << "not found" << endl;
            }
        } else {
            // reloop if input is invalid
            cout << "Invalid Input. Please try again!" << endl;
        }
    } else if (choice == 3) {
        // exit program
        cout << "Thank you for using Password Checker!" << endl;
        exit(0);
    } else {
        // reloop if input is invalid
        cout << "Invalid Input. Please try again!" << endl;
    }
}

int main() {
    // create passwords vector and read file into vector
    vector<string> passwords;

    if (!readFile("../passwords.txt", passwords)) {
        cerr << "file couldn't be opened" << endl;
        return 1;
    }

    // create trie and hashmap
    Trie trie = Trie(passwords);
    Hashtable hashtable = Hashtable(passwords);

    // main processing loop
    while (true) {
        printMenu();

        cout << "Enter your selection: ";
        int choice = getChoice();
        handleInput(choice, trie, hashtable);
    }
}