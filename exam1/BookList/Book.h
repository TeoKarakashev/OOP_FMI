#pragma once
class Book {
	char title[100];
	char author[100];
	int tiraj;

public:
	Book();
	Book(const char* title, const char* author, int tiraj);

	char* getTitle() const;
	char* getAuthor() const;
	int getTiraj() const;


};
