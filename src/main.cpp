#include "head.h"
#include <iostream>
#include <unordered_set>
#include <fstream>
#include <string>
#include "header.h"

using namespace std;

void enter() {
ofstream nya;
string testFile = "slava.txt";
nya.open(testFile);
string mur;

getline(cin, mur);
system("CLS");
nya << mur;

nya.close();
}

int main()
{
enter();
string testFile = "slava.txt";
string dictFile = "knuth_words.txt";
string str = "rewrite.txt";

clear(testFile, str);
ReadDictionaryFile(dictFile);
CheckFile(str);
return 0;
}
