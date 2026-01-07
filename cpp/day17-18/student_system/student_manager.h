// student_manager.h
#ifndef STUDENT_MANAGER_H
#define STUDENT_MANAGER_H
#include "student.h"
#include <vector>
#include <string>
class StudentManager {
	private:
	vector<Student> students;
	public:
	void addStudent(const Student& stu);
	void displayAll() const;
	bool saveToFile(const string& filename);
	bool loadFromFile(const string& filename);
	void searchByName(const string& name) const;
};
#endif // STUDENT_MANAGER_H