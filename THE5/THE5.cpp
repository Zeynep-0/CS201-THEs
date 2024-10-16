#include <iostream>
#include <string>
using namespace std;
#include<fstream>
#include <vector>
#include"book.h";
void sortBooks(vector<Book>& a, int size) {
	int k, loc;
	for (k = 1; k < size; k++) {
		string hold = a[k].getAuthor();
		loc = k;
		while (0 < loc && hold < a[loc - 1].getAuthor()) {
			Book all = a[loc];
			a[loc] = a[loc - 1];
			a[loc - 1] = all;
			loc--;
		}
		a[loc].getAuthor() = hold;
	}

}
int main() {
	cout << "Menu:" << endl <<
		"1. Add a new book" << endl <<
		"2. Display all books" << endl <<
		"3. Search for a book by title" << endl <<
		"4. Exit" << endl;
	cout << "Enter your choice: ";
	int opt;
	cin >> opt;
	vector<Book> books;
	while (opt != 4 && opt != 1) {
		cout << "The book collection is currently empty. Please add some books first." << endl;
		cout << "Menu:" << endl <<
			"1. Add a new book" << endl <<
			"2. Display all books" << endl <<
			"3. Search for a book by title" << endl <<
			"4. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> opt;
	}
	while (opt != 4) {
		if (opt == 1) {
			string title, author;
			int year, pages;
			cout << "Enter title: ";
			cin.ignore();
			getline(cin, title);
			cout << "Enter author: ";
			getline(cin, author);
			cout << "Enter year: ";
			cin >> year;
			cin.ignore();
			cout << "Enter pages: ";
			cin >> pages;
			cin.ignore();
			books.push_back(Book(title, author, year, pages));
			if (books.size() > 1) {
				sortBooks(books, books.size());

			}
		}
		else if (opt == 2) {
			for (int i = 0; i < books.size(); i++) {
				books[i].printInfo();
				cout << endl << "-------------------" << endl;
			}
		}
		else if (opt == 3) {
			string searchtitle;
			cout << "Enter the title to search: ";
			cin.ignore();
			getline(cin, searchtitle);
			int pt = 0;
			for (int i = 0; i < books.size(); i++) {
				if (books[i].getTitle() == searchtitle) {
					books[i].printInfo();
					cout << endl;
					pt = 1;
					break;
				}
			}if (pt != 1) {
				cout << "Book not found!" << endl;
			}
		}
		cout << "Menu:" << endl <<
			"1. Add a new book" << endl <<
			"2. Display all books" << endl <<
			"3. Search for a book by title" << endl <<
			"4. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> opt;
	}
	cout << "Exiting...";
	return 0;
}
