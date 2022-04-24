#include "Book.h"
#include <iostream>
#pragma warning (disable: 4996)

Book::Book(){
	strcpy(title, "title");
	strcpy(author, "author");
	tiraj = 0;
}

Book::Book(const char* title,const char* author, int tiraj){
	strcpy(this->title, title);
	strcpy(this->author, author);
	this->tiraj = tiraj;
}

char* Book::getTitle() const
{
	return (char*)title;
}

char* Book::getAuthor() const
{
	return (char*)author;
}

int Book::getTiraj() const
{
	return tiraj;
}
