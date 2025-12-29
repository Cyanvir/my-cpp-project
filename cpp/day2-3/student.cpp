//定义一个 Student 类，包含姓名、学号、成绩等属性，提供方法显示学生信息。
#include <iostream>
#include <string>
using namespace std;
//定义Student类
class Student {
	private:
	string name;
	string id;
	double score;
	
	public:
	//构造函数
	Student(string n, string i, double s){
		name=n;
		id=i;
		score=s;
		cout<<"对象创建："<<name<<endl;
	}

	//析构函数
	~Student(){
		cout<<"对象销毁："<<name<<endl;
	}

	//数据展示
	void showInfo(){
		cout<<"姓名："<<name<<endl;
		cout<<"学号："<<id<<endl;
		cout<<"成绩："<<score<<endl;
	}
	//修改成绩
	void setScore(double s){
		if(s<0&&s>100){
			cout<<"无效成绩："<<endl;
		}else{
			score=s;
		}
	}

	//获得成绩
	double getScore(){
		return score;
	}
	
};

//主函数
int main(){
	Student stu1("张三","2023001",85.5);
	stu1.showInfo();

	cout<<"\n修改成绩..."<<endl;
	stu1.setScore(90.0);
	cout<<"新成绩："<<stu1.getScore()<<endl;
	return 0;
}