#include "book.h"
#include <iostream>
#include <string>
using namespace std;


Book::Book(const string& title, const string& author, int year, int pages) {
	Book::title = title;
	Book::author = author;
	Book::year = year;
	Book::pages = pages;

}
string Book::getTitle() const {
	return Book::title;
}
string Book::getAuthor() const {
	return Book::author;
}
int Book::getYear() const {
	return Book::year;
}
int Book::getPages() const {
	return Book::pages;
}
void Book::printInfo() const {
	cout << "Title: "<<getTitle()<<endl;
	cout << "Author: "<<getAuthor()<<endl;
	cout << "Year: "<<getYear()<<endl;
	cout << "Pages: "<<getPages();
}