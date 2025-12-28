#include <iostream>
using namespace std;
int main() {
	string name;
	int age;
	cout << " 请输入你的名字: ";
	cin >> name;
	cout << " 请输入你的年龄: ";
	cin >> age;
	cout << " 你好，" << name << "！你今年 " << age << " 岁。" << endl;
	return 0;
}