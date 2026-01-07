//实现一个 Book 类，包含书名、作者、价格，并实现拷贝构造函数。
#include <iostream>
#include <string>
using namespace std;

class Book{
	private:
	string title;
	string author;
	double price;
	int* pages;

	public:

	Book():title("未知"),author("未知"),price(0.0){
		pages= new int(0);
		cout<<"调用默认构造函数"<<endl;
	}

	Book(string t, string a, double p, int pg):title(t),author(a),price(p){
		pages = new int(pg);
		cout<<"创建书籍："<<title<<endl;
	}

	Book(const Book& other){
		title = other.title;
		author = other.author;
		price = other.price;
		//pages = other.pages; // 浅拷贝：只拷贝指针地址，不拷贝内存
		// 关键：给新对象的pages分配新内存，再拷贝值（深拷贝）
		pages = new int(*other.pages); 
		cout<<"拷贝构造："<<title<<endl;
	}

	~Book(){
		delete pages;
		cout<<"销毁书籍："<<title<<endl;
	}

	void showInfo() const{
		cout<<"《"<<title<<"》"<<endl;
		cout<<"作者："<<author<<endl;
		cout<<"价格：￥"<<price<<endl;
		cout<<"页数："<<*pages<<endl;
	}
};

int main(){
	Book book1("C++ Primer","Stanley B. Lippman",99.0,850);
	book1.showInfo();

	cout<<"\n创建副本..."<<endl;
	Book book2=book1;
	book2.showInfo();
	return 0;
}