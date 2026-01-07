#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <fstream>
using namespace std;
class Student {
	private:
	string name;
	string id;
	double score;
	public:
	Student(string n = "", string i = "", double s = 0.0);
	void display() const;
	void saveToFile(ofstream& ofs) const;
	void loadFromFile(ifstream& ifs);
	string getName() const { return name; }
	string getId() const { return id; }
	double getScore() const { return score; }
};
#endif // STUDENT_H