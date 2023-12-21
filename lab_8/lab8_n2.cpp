#include <iostream>
#include <vector>
#include <locale.h>
#include <fstream>
#include <string>

using namespace std;

struct Book {
	string Author;
	string Title;
	int Year;
};

void saveToFile(const string& filename, const vector<Book>& data) {
	ofstream out;
	out.open(filename);
	if (out.is_open()) {
		for (int i = 0; i < data.size(); ++i) {
			out << data[i].Author << ' ' << data[i].Title << ' ' << data[i].Year << endl;
		}
	}
	else {
		cout << "file can't open";
	}
	out.close();
	return;
}
void loadFromFile(const std::string& filename, std::vector<string>& outData) {
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
	vector<Book> vec1;
	vector<string> vec2;
	string a, t, line;
	int n, y;
	cout << "Введите количество книг: ";
	cin >> n;
	cout << endl;
	Book book1 = {"писатель1", "название1", 1};
	Book book2 = { "писатель2", "название2", 2 };
	for (int i = 0; i < n; ++i) {
		Book b;
		cout << "Введите автора, название и год издания книги в строчку: ";
		cin >> b.Author >> b.Title >> b.Year;
		vec1.push_back(b);
	}
	saveToFile("test2.txt", vec1);
	loadFromFile("test2.txt", vec2);

	return 0;
}