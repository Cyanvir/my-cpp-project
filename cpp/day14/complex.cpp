//为 Complex 复数类重载加法、减法和输出运算符。
#include <iostream>
using namespace std;
class Complex {
	private:
	double real;
	double imag;
	public:
	Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}
	// 运算符重载（成员函数形式）
	Complex operator+(const Complex& other) const {
		return Complex(real + other.real, imag + other.imag);
	}
	Complex operator-(const Complex& other) const {
		return Complex(real - other.real, imag - other.imag);
	}
	Complex operator*(const Complex& other) const {
		return Complex(
			real * other.real - imag * other.imag,
			real * other.imag + imag * other.real
		);
}
bool operator==(const Complex& other) const {
	return (real == other.real) && (imag == other.imag);
}
// 友元函数：输出运算符重载,因为输入习惯导致必须作为全局函数使用
friend ostream& operator<<(ostream& os, const Complex& c);
// 友元函数：输入运算符重载
friend istream& operator>>(istream& is, Complex& c);
};
// 友元函数实现
ostream& operator<<(ostream& os, const Complex& c) {
	os << c.real;
	if (c.imag >= 0) {
	os << " + " << c.imag << "i";
	} else {
	os << " ‐ " << -c.imag << "i";
	}
	return os;
}
istream& operator>>(istream& is, Complex& c) {
	cout << " 请输入实部: ";
	is >> c.real;
	cout << " 请输入虚部: ";
	is >> c.imag;
	return is;
}
int main() {
	Complex c1(3.0, 4.0);
	Complex c2(1.0, 2.0);
	cout << "c1 = " << c1 << endl;
	cout << "c2 = " << c2 << endl;
	Complex c3 = c1 + c2;
	cout << "c1 + c2 = " << c3 << endl;
	Complex c4 = c1 - c2;
	cout << "c1 ‐ c2 = " << c4 << endl;
	Complex c5 = c1 * c2;
	cout << "c1 * c2 = " << c5 << endl;
	if (c1 == c2) {
		cout << "c1 == c2" << endl;
	} else {
		cout << "c1 != c2" << endl;
	}
	cout << "\n输入一个复数：" << endl;
	Complex c6;
	cin >> c6;
	cout << " 你输入的复数是: " << c6 << endl;
	return 0;
}