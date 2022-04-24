#include <iostream>
#include <fstream>
#include "Book.h"
#include "BookList.h"
#pragma warning (disable: 4996)
int main() {

	Book book("book1", "aut1", 550);
	Book book2("book2", "aut2", 1000);
	Book book3("book3", "aut3", 1500);
	BookList list;
	list.add(book);
	list.add(book2);
	list.add(book3);
	list.writeInFIle("popular.txt");
}