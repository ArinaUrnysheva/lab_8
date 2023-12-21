#include <iostream>
#include <vector>
#include <map>
#include <locale.h>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

enum Score
{
    Unsatisfactorily = 2,
    Satisfactorily,
    Good,
    Excellent
};

struct Student
{
    std::string Name;
    int Year;
    map<string, Score> RecordBook;
};

// в качестве ключа - название группы
// в качестве значения - список студентов
using Groups = map<string, vector<Student>>;

void saveToFile(string& filename, Groups& groups) {
    ofstream out(filename);
    if (!out.is_open()) {
        cout << "can't open file" << endl;
    }
    for (auto& elem : groups.at("IU8-14")) {
        out << elem.Name << ' ' << elem.Year << ' ' << elem.RecordBook.at("Math") << std::endl;
    }
    out.close();
    return;
}

void loadFromFile(const std::string& filename, Groups& outGroups) {
    ifstream in(filename);
    if (!in.is_open()) {
        cout << "can't open file" << endl;
        return;
    }
    string str;
    vector <Student> s1;
    while (getline(in, str)) {
        Student student;
        istringstream iss(str);
        string name;
        iss >> name;
        student.Name = name;
        int year;
        iss >> year;
        student.Year = year;
        int score;
        iss >> score;
        student.RecordBook["Math"] = static_cast<Score>(score);
        s1.push_back(student);
    }
    outGroups["IU8-14"] = s1;
    for (const auto& element1 : outGroups) {
        for (int i = 0; i < element1.second.size(); ++i) {
            for (const auto& element2 : element1.second[i].RecordBook) {
                cout << element1.first << ' ' << element1.second[i].Name << ' ' << element1.second[i].Year << ' ' << element2.first << ' ' << element2.second << endl;
            }
        }
    }
    return;
}

int main() {
    Groups group1, group2;
    vector <Student> s3;
    string filename1 = "test.txt";
    string filename = "test1.txt";
    Student s1;
    cin >> s1.Name;
    s1.Year = 18;
    s1.RecordBook["Biology"] = Excellent;
    Student s2;
    cin >> s2.Name;
    s2.Year = 17;
    s2.RecordBook["Math"] = Good;
    s3.push_back(s1);
    s3.push_back(s2);
    group1["IU8-14"] = s3;
    saveToFile(filename, group1);
    loadFromFile(filename, group2);
}