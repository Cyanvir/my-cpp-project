#include "student_manager.h"
#include <iostream>
void StudentManager::addStudent(const Student& stu) {
	students.push_back(stu);
}
void StudentManager::displayAll() const {
	cout << "\n========== 所有学生信息 ==========" << endl;
	for (const auto& stu : students) {
		stu.display();
	}
	cout << "================================\n" << endl;
}
bool StudentManager::saveToFile(const string& filename) {
	ofstream ofs(filename);
	if (!ofs) {
		cout << " 文件打开失败！" << endl;
		return false;
	}
	ofs << students.size() << endl;
	for (const auto& stu : students) {
		stu.saveToFile(ofs);
	}
	ofs.close();
	cout << " 数据已保存到: " << filename << endl;
	return true;
}
bool StudentManager::loadFromFile(const string& filename) {
	ifstream ifs(filename);
	if (!ifs) {
		cout << " 文件打开失败！" << endl;
		return false;
	}
	students.clear();
	size_t count;
	ifs >> count;
	ifs.ignore();
	for (size_t i = 0; i < count; i++) {
		Student stu;
		stu.loadFromFile(ifs);
		students.push_back(stu);
	}
	ifs.close();
	cout << " 数据已加载" << endl;
	return true;
}
void StudentManager::searchByName(const string& name) const {
	cout << "\n搜索结果：" << endl;
	bool found = false;
	for (const auto& stu : students) {
		if (stu.getName() == name) {
			stu.display();
			found = true;
		}
	}
	if (!found) {
		cout << " 未找到学生：" << name << endl;
	}
}