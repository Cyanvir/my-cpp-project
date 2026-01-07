#include "student_manager.h"
#include <iostream>
int main() {
	StudentManager manager;
	manager.addStudent(Student(" 张三", "2023001", 85.5));
	manager.addStudent(Student(" 李四", "2023002", 92.0));
	manager.addStudent(Student(" 王五", "2023003", 78.5));
	manager.displayAll();
	manager.saveToFile("data.txt");
	manager.searchByName(" 李四");
	return 0;
}
