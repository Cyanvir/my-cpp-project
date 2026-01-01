//设计一个 Shape 抽象类接口，派生 Circle 和 Rectangle 类。
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
// 抽象基类（接口）
class Shape {
	protected:
	string name;
	public:
	Shape(string n) : name(n) {}
	virtual ~Shape() {}
	// 纯虚函数
	virtual double getArea() const = 0;
	virtual double getPerimeter() const = 0;
	virtual void display() const = 0;

	string getName() const {
		return name;
	}
};
// 派生类：圆形
class Circle : public Shape {
	private:
	double radius;
	public:
	Circle(double r) : Shape(" 圆形"), radius(r) {}
	double getArea() const override {
		return M_PI * radius * radius;
	}
	double getPerimeter() const override {
		return 2 * M_PI * radius;
	}
	void display() const override {
		cout << " 形状: " << name << endl;
		cout << " 半径: " << radius << endl;
		cout << " 面积: " << getArea() << endl;
		cout << " 周长: " << getPerimeter() << endl;
	}
};
// 派生类：矩形
class Rectangle : public Shape {
	private:
	double width;
	double height;
	public:
	Rectangle(double w, double h)
	: Shape(" 矩形"), width(w), height(h) {}
	double getArea() const override {
		return width * height;
	}
	double getPerimeter() const override {
		return 2 * (width + height);
	}
	void display() const override {
		cout << " 形状: " << name << endl;
		cout << " 宽度: " << width << ", 高度: " << height << endl;
		cout << " 面积: " << getArea() << endl;
		cout << " 周长: " << getPerimeter() << endl;
	}
};
// 派生类：三角形
class Triangle : public Shape {
	private:
	double a, b, c;
	public:
	Triangle(double side_a, double side_b, double side_c)
	: Shape(" 三角形"), a(side_a), b(side_b), c(side_c) {}
	double getArea() const override {
	// 使用海伦公式
		double s = (a + b + c) / 2;
		return sqrt(s * (s - a) * (s - b) * (s - c));
	}
	double getPerimeter() const override {
		return a + b + c;
	}
	void display() const override {
		cout << " 形状: " << name << endl;
		cout << " 三边: " << a << ", " << b << ", " << c << endl;
		cout << " 面积: " << getArea() << endl;
		cout << " 周长: " << getPerimeter() << endl;
	}
};
int main() {
	// 无法实例化抽象类
	// Shape shape(" 测试"); // 错误！
	vector<Shape*> shapes;
	shapes.push_back(new Circle(5.0));
	shapes.push_back(new Rectangle(4.0, 6.0));
	shapes.push_back(new Triangle(3.0, 4.0, 5.0));
	cout << "========== 所有图形信息 ==========" << endl;
	for (size_t i = 0; i < shapes.size(); i++) {
		shapes[i]->display();
		cout << "‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐" << endl;
	}
	// 清理内存
	for (Shape* s : shapes) {
		delete s;
	}
	return 0;
}