#include <fstream>
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

void lowerCase(string& str)
{
    for (auto& ch : str) {
        ch = tolower(ch);
    }
}

void clear(string filename, string filename2)
{
    ifstream bir;
    ofstream mur;
    bir.open(filename);
    mur.open(filename2);

    string buf;
    while (bir >> buf) {
        cout << buf << " ";
        string mas = ".()-:!?";
        while (buf.rfind(",") != 4294967295
               && buf.rfind(",") == buf.length() - 1) {
            buf = buf.erase(buf.rfind(","), 1);
        }
        for (int i = 0; i < 7; i++) {
            while (buf.rfind(mas[i]) != 4294967295) {
                buf = buf.erase(buf.rfind(mas[i]), 1);
            }
        }

        mur << buf << " ";
    }
    cout << endl << endl;
    mur.close();
}
