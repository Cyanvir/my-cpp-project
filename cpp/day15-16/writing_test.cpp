#include <fstream>
#include <iostream>
using namespace std;
 
int main() {
    
   char data[100];
 
   // 以写模式打开文件
   ofstream outfile;
   // 解释：ofstream（output file stream）是专门用于**向文件写入数据**的类，实例化对象后才能操作文件
   outfile.open("afile.dat");
 
   cout << "Writing to the file" << endl;
   cout << "Enter your name: "; 
   cin.getline(data, 100);
   // 解释：cin.getline(数组名, 长度) 用于读取**带空格的整行输入**
   // 向文件写入用户输入的数据
   outfile << data << endl;
   // 解释：和cout<<用法类似，只是输出目标从控制台变成了文件；endl会写入换行符，让姓名和年龄分行存储
   cout << "Enter your age: "; 
   cin >> data;
   cin.ignore();
   
   // 再次向文件写入用户输入的数据
   outfile << data << endl;
 
   // 关闭打开的文件
   outfile.close();
 
   // 以读模式打开文件
   ifstream infile; 
   infile.open("afile.dat"); 
 
   cout << "Reading from the file" << endl; 
   infile >> data; 
 
   // 在屏幕上写入数据
   cout << data << endl;
   
   // 再次从文件读取数据，并显示它
   infile >> data; 
   cout << data << endl; 
 
   // 关闭打开的文件
   infile.close();
 
   return 0;
}