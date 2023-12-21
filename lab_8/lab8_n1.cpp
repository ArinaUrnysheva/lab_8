#include <iostream>
#include <vector>
#include <locale.h>
#include <fstream>
#include <string>

using namespace std;

void saveToFile(const string& filename, const vector<string>& data) {

	ofstream out;
	out.open(filename);
	if (out.is_open()) {
		for (int i = 0; i < data.size(); ++i) {
			out << data[i] << endl;
		}
	}

	out.close();
	return;
}

void loadFromFile(const string& filename, vector<string>& outData) {
	string line;
	ifstream in(filename);
	if (in.is_open()) {
		while (getline(in, line)) {
			outData.push_back(line);
		}
	}
	else {
		cout << "file can't open" << endl;
	}

	for (int i = 0; i < outData.size(); ++i) {
		cout << outData[i] << endl;
	}
	in.close();
	return;
}

int main() {
	setlocale(LC_ALL, "Russian");
	vector<string> vec1;
	vector<string> vec2;
	string word, line;
	int n;
	cout << "Введите длину массива: ";
	cin >> n;
	cout << endl;
	for (int i = 0; i < n; ++i) {
		cin >> word;
		vec1.push_back(word);
	}
	saveToFile("test.txt", vec1);
	loadFromFile("test.txt", vec2);
	return 0;
}