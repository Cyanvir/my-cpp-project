//创建 Person 基类，派生出 Teacher 和 Student 子类。
#include <iostream>
#include <string>
using namespace std;

class Person{
	protected:
	string name;
	int age;
	public:
	Person(string n,int a):name(n),age(a){
		cout<<"Person 构造函数："<<name<<endl;
	}

	~Person(){
		cout<<"Person 析构函数："<<name<<endl;
	}

	void showBasicInfo() const{
		cout<<"姓名："<<name<<endl;
		cout<<"年龄："<<age<<endl;
	}
};

class Teacher : public Person{
	private:
	string subject;
	int workYears;

	public:
	Teacher(string n,int a,string s,int y):Person(n,a),subject(s),workYears(y){
		cout<<"Teacher 构造函数："<<name<<endl;
	}

	~Teacher(){
		cout<<"Teacher 析构函数："<<name<<endl;
	}

	void showInfo() const{
		showBasicInfo();
		cout<<"任教科目："<<subject<<endl;
		cout<<"工作年限："<<workYears<<endl;
	}
};

class Student : public Person{
	private:
	string studentId;
	double gpa;

	public:
	Student(string n,int a,string id,double g):Person(n,a),studentId(id),gpa(g){
		cout<<"Student 构造函数："<<name<<endl;
	}

	~Student(){
		cout<<"Student 析构函数："<<name<<endl;
	}

	void showInfo() const{
		showBasicInfo();
		cout<<"学号："<<studentId<<endl;
		cout<<"GPA："<<gpa<<endl;
	}
};

int main(){
	cout << "========== 创建教师对象 ==========" << endl;
	Teacher teacher(" 王老师", 35, " 数学", 10);
	teacher.showInfo();
	cout << "\n========== 创建学生对象 ==========" << endl;
	Student student(" 张三", 20, "2023001", 3.8);
	student.showInfo();
	cout << "\n========== 对象销毁 ==========" << endl;
	return 0;
}
