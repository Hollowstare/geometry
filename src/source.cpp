#include <iostream>
#include <string>
#include <unordered_set>
#include <fstream>

using namespace std;

void lowerCase(string& str) {
	for (auto& ch : str) {
		ch = tolower(ch);
	}
}

void clear(string filename, string filename2) {
	ifstream bir;
	ofstream mur;
	bir.open(filename);
	mur.open(filename2);

	string buf;
	while (bir >> buf) {
		cout << buf << " ";
		while (buf.rfind(",") != 4294967295 && buf.rfind(",") == buf.length() - 1) {
			buf = buf.erase(buf.rfind(","), 1);
		}
		mur << buf << " ";

	}
	cout << endl << endl;
	mur.close();
}
