#include "head.h"
#include "header.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void enter()
{
    ofstream nya;
    string testFile = "slava.txt";
    nya.open(testFile);
    string mur;

    getline(cin, mur);
    nya << mur;

    nya.close();
}

int main()
{
    cout << "Введите текст" << endl;
    enter();
    string testFile = "slava.txt";
    string dictFile = "knuth_words.txt";
    string str = "rewrite.txt";

    clear(testFile, str);
    ReadDictionaryFile(dictFile);
    CheckFile(str);
    return 0;
}
