#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Person{
	protected:
	string name;
	int age;

	public:
	Person(string n,int a):name(n),age(a){}

	virtual ~Person(){
		cout<<"~Person()"<<endl;
	}

	virtual void showInfo() const{
		cout<<"姓名："<<name<<"，年龄："<<age<<endl;
	}

	virtual void getRole() const{
		cout<<"角色：普通人"<<endl;
	}
};

class Teacher :public Person{
	private:
	string subject;

	public:
	Teacher(string n,int a,string s):Person(n,a),subject(s){}

	~Teacher() override{
		cout<<"~Teacher()"<<endl;
	}

	void showInfo() const override{
		Person::showInfo();
		cout<<"任教科目："<<subject<<endl;
	}

	void getRole() const override{
		cout<<"角色：教师"<<endl;
	}
};

class Student :public Person{
	private:
	string studentId;

	public:
	Student(string n,int a,string id):Person(n,a),studentId(id){}

	~Student() override{
		cout<<"~Student()"<<endl;
	}

	void showInfo() const override{
		Person::showInfo();
		cout<<"学号："<<studentId<<endl;
	}

	void getRole() const override{
		cout<<"角色：学生"<<endl;
	}
};

void printPersonInfo(const Person& p){
	p.getRole();
	p.showInfo();
	cout<<"--------------------"<<endl;
}

int main(){
	Teacher teacher(" 李老师", 40, " 物理");
	Student student(" 王小明", 19, "2023002");
	Person person(" 路人甲", 25);
	cout << "========== 使用多态 ==========" << endl;
	printPersonInfo(teacher);
	printPersonInfo(student);
	printPersonInfo(person);
	cout << "\n========== 使用基类指针 ==========" << endl;
	Person *p1=&teacher;
	Person *p2=&student;
	p1->showInfo();
	cout<<endl;
	p2->showInfo();
	return 0;
}