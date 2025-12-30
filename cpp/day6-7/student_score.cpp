//创建 Score 类和 Student 类，Student 包含多个 Score 对象
#include <iostream>
#include <string>
using namespace std;

class Score{
	private:
	string subject;
	double value;

	public:
	Score(string s="未知科目",double v=0.0):subject(s),value(v){
		cout<<"创建成绩对象："<<subject<<endl;
	}

	~Score(){
		cout<<"销毁成绩对象："<<subject<<endl;
	}

	void setScore(double v){
		if(v>=0&&v<=100){
			value=v;
		}
	}

	void showScore() const{
		cout<<subject<<"："<<value<<"分"<<endl;
	}
};

class Student{
	string name;
	string id;
	Score mathScore;
	Score englishScore;
	Score cppScore;

	public:
	Student(string n,string i,double math,double eng,double cpp):name(n),id(i),mathScore("数学",math),englishScore("英语",eng),cppScore("C++",cpp){
		cout<<"创建学生对象："<<name<<endl;
	}

	~Student(){
		cout<<"销毁学生对象："<<name<<endl;
	}

	void showInfo() const{
		cout<<"\n========== 学生信息 ==========" << endl;
		cout << " 姓名: " << name << endl;
		cout << " 学号: " << id << endl;
		cout << " 成绩信息:" << endl;
		mathScore.showScore();
		englishScore.showScore();
		cppScore.showScore();
		cout<<"============================\n" << endl;
	}
};

int main(){
	Student stu("李四","2023002",88.0,92.0,95.0);
	stu.showInfo();
	return 0;
}