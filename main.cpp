#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include <limits>
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

int getMenuChoice() {
    int choice;

    while (true) {
        if (cin >> choice && (choice == 1 || choice == 2 || choice == 3)) {
            return choice;
        } else {
            cout << "Invalid input, please enter a valid selection (1-3)." << endl;
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

int getSearchType() {
    int choice;
    while (true) {
        if (cin >> choice && (choice == 1 || choice == 2)) {
            return choice;
        } else {
            cout << "Invalid input, please enter a valid selection (1-2)." << endl;
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

int getNumber() {
    int choice;
    while (true) {
        if (cin >> choice && (choice > 0 && choice <= 100000)) {
            return choice;
        } else {
            cout << "Invalid input, please enter a valid selection (1-100000)." << endl;
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

string getInput() {
    string input;
    cin >> input;

    return input;
}

void printMenu() {
    cout << "Welcome to Password Checker!" << endl;
    cout << "----------------------------" << endl;
    cout << "1. View the N most commonly brute forced passwords" << endl;
    cout << "2. Determine if a password is one of the 100,000 most commonly brute forced passwords" << endl;
    cout << "3. Exit Program" << endl;
    cout << endl;
}

void handleInput(int choice, Trie &trie, Hashtable &hashtable, vector<string> &passwords) {
    if (choice == 1) {
        // print top N most frequently brute forced passwords
        cout << "Enter number of top N most frequently brute forced passwords (max of 100000, no commas): ";
        int number = getNumber();


        auto start = chrono::high_resolution_clock::now();
        for (int i = 0; i < number; i++) {
            cout << passwords[i] << endl;
        }
        auto end = chrono::high_resolution_clock::now();

        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
        cout << "\n" << number << " passwords printed in " << elapsed << " nanoseconds." << endl;
        cout << endl;
    } else if (choice == 2) {
        // check if entered password is in list of passwords
        cout << "Enter the password you want to check: ";
        string input = getInput();

        cout << "Press 1 to search using a Trie, Press 2 to search using a Hashmap: ";
        int choice = getSearchType();
        if (choice == 1) {
            // search using trie
            auto start = chrono::high_resolution_clock::now();
            bool found = trie.find(input);
            auto end = chrono::high_resolution_clock::now();

            // calculate time duration
            auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

            if (found) {
                cout << input << " found in " << elapsed << " nanoseconds." << endl;
            } else {
                cout << input << " not found. Searching took " << elapsed << " nanoseconds." << endl;
            }
            cout << endl;
        } else if (choice == 2) {
            // search using hashmap

            auto start = chrono::high_resolution_clock::now();
            bool found = hashtable.find(input);
            auto end = chrono::high_resolution_clock::now();

            // calculate time duration
            auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

            if (found) {
                cout << input << " found in " << elapsed << " nanoseconds." << endl;
            } else {
                cout << input << " not found. Searching took " << elapsed << " nanoseconds." << endl;
            }
            cout << endl;
        }
    } else if (choice == 3) {
        cout << "Thank you for using Password Checker!" << endl;
        exit(0);
    }
}

int main() {
    // create passwords vector and read file into vector
    vector<string> passwords;

    if (!readFile("passwords.txt", passwords)) {
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
        int choice = getMenuChoice();
        handleInput(choice, trie, hashtable, passwords);
    }
}