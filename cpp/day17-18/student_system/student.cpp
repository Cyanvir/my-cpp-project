#include "student.h"
#include <iostream>
Student::Student(string n, string i, double s)
: name(n), id(i), score(s) {}
void Student::display() const {
	cout << " 姓名: " << name << ", 学号: " << id
	<< ", 成绩: " << score << endl;
}
void Student::saveToFile(ofstream& ofs) const {
	ofs << name << endl;
	ofs << id << endl;
	ofs << score << endl;
}
void Student::loadFromFile(ifstream& ifs) {
	getline(ifs, name);
	getline(ifs, id);
	ifs >> score;
	ifs.ignore();
}
