#include "Player.h"
#include <iostream>

#pragma warning(disable: 4996)

Player::Player() {
	name = new char[10];
	strcpy(name,"Uknown");
	password = new char[10];
	strcpy(password, "123");
	age = 18;
	money = 100;
}

void Player::copyFrom(const Player& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
	password = new char[strlen(other.password) + 1];
	strcpy(password, other.password);
}

void Player::free() {
	delete[] name;
	delete[] password;
}

int Player::getAge() const {
	return age;
}

char* Player::getPassword() const {
	return password;
}

Player::Player(const char* name, const char* password, int age, double money) {
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->password = new char[strlen(password) + 1];
	strcpy(this->password, name);
	this->age = age;
	this->money = money;
}
Player::Player(const Player& other) {
	copyFrom(other);
}
Player& Player::operator=(const Player & other) {
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}
Player::~Player() {
	free();
}

void Player::changeName(const char* name) {
	if (this->name == nullptr) {
		this->name = new char[strlen(name) + 1];
	}
	strcpy(this->name, name);
	
}