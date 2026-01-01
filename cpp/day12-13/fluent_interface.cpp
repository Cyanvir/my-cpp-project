//this 指针实现流式接口（Fluent Interface）
//流式接口是一种面向对象的API设计风格
//其目的是通过方法链提高代码的可读性。
//许多现代库如jQuery、Boost和STL中的一些组件都使用了这种模式：
#include <iostream>
#include <string>
using namespace std;
class StringBuilder{
	private:
	string data;
	public:
	StringBuilder():data(""){}
	StringBuilder& append(const string &text){
		data += text;
		return *this;
	}
	StringBuilder& appendLine(const string &text){
		data += text+'\n';
		return *this;
	}
	string toString()const{
		return data;
	}
};
int main(){
	StringBuilder builder;
	string result =builder.append("你好，").append("世界！").appendLine("").append("我来了").toString();
	cout<<result<<endl;
	return 0;
}