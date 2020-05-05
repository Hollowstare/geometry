#include "header.h"
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

unordered_set<string> wordDict;

string CreateWordList_SwapAdjChars(string word)
{
    string result;
    for (int i = 0; i < word.size() - 1; i++) {
        string newWord = word;
        swap(newWord[i], newWord[i + 1]);
        if (wordDict.find(newWord) != wordDict.end()) {
            result = result + newWord + " ";
        }
    }
    return result;
}

string s(string word)
{
    string result;
    for (int i = 0; i < word.size(); ++i) {
        string newWord = word;
        newWord = newWord.erase(i, 1);
        if (wordDict.find(newWord) != wordDict.end()) {
            result = result + newWord + " ";
        }
    }
    return result;
}

void CheckFile(string filename)
{
    ifstream fin;
    fin.open(filename);
    if (fin.is_open()) {
        string word;
        while (fin >> word) {
            lowerCase(word);
            cout << word;
            if (wordDict.find(word) != wordDict.end()) {
                cout << " -> correct word" << endl;
            }

            else {
                string altWordList = CreateWordList_SwapAdjChars(word);
                if (altWordList.empty()) {
                    altWordList = s(word);
                    if (altWordList.empty()) {
                        cout << " -> unknown or nonexistent word" << endl;
                    } else {
                        cout << " -> uncorrect word, maybe you mean -->>  ";
                        for (auto altWord : altWordList) {
                            cout << altWord;
                        }
                        cout << endl;
                    }
                } else {
                    cout << " -> uncorrect word, maybe you mean -->> ";
                    for (auto altWord : altWordList) {
                        cout << altWord;
                    }
                    cout << endl;
                }
            }
        }
    } else {
        cout << "Can't open file: " << filename << endl;
    }
}

void ReadDictionaryFile(string filename)
{
    ifstream fin;
    fin.open(filename);
    if (fin.is_open()) {
        string word;
        while (fin >> word) {
            lowerCase(word);
            wordDict.insert(word);
        }
    } else {
        cout << "Can't open file: " << filename << endl;
    }
}
