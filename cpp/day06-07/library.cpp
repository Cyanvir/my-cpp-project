#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Book {
private:
    string title;
    string author;
    string isbn;
    bool available;

public:
    Book(string t, string a, string i)
        : title(t), author(a), isbn(i), available(true) {
    }
    
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getISBN() const { return isbn; }
    bool isAvailable() const { return available; }
    
    void borrow() {
        if (available) {
            available = false;
            cout << "《" << title << "》借阅成功!" << endl;
        } else {
            cout << "《" << title << "》已被借出，无法借阅!" << endl;
        }
    }
    
    void returnBook() {
        if (!available) {
            available = true;
            cout << "《" << title << "》归还成功!" << endl;
        } else {
            cout << "《" << title << "》未被借出，无需归还!" << endl;
        }
    }
    
    void display() const {
        cout << "书名: " << title << endl;
        cout << "作者: " << author << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "状态: " << (available ? "可借阅" : "已借出") << endl;
        cout << "-------------------------" << endl;
    }
};

class Library {
private:
    vector<Book> books;
    string name;

public:
    Library(string n) : name(n) {}
    
    void addBook(const Book& book) {
        books.push_back(book);
        cout << "图书《" << book.getTitle() << "》已添加到" << name << endl;
    }
    
    void displayAllBooks() const {
        cout << "\n" << name << "的所有图书:" << endl;
        cout << "=========================" << endl;
        for (const auto& book : books) {
            book.display();
        }
    }
    
    Book* findBook(string title) {
        for (auto& book : books) {
            if (book.getTitle() == title) {
                return &book;
            }
        }
        return nullptr;
    }
};

int main() {
    Library library("城市中央图书馆");
    
    Book book1("C++程序设计", "张三", "978-7-302-12345-6");
    Book book2("数据结构", "李四", "978-7-302-67890-1");
    Book book3("算法导论", "王五", "978-7-115-12345-6");
    
    library.addBook(book1);
    library.addBook(book2);
    library.addBook(book3);
    
    library.displayAllBooks();
    
    // 借书和还书操作
    Book* foundBook = library.findBook("C++程序设计");
    if (foundBook) {
        foundBook->borrow();
    } else {
        cout << "未找到该图书!" << endl;
    }
    
    library.displayAllBooks();
    
    foundBook = library.findBook("C++程序设计");
    if (foundBook) {
        foundBook->returnBook();
    }
    
    library.displayAllBooks();
    
    return 0;
}