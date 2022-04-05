#pragma once



class Player {
	char* name = nullptr;
	char* password = nullptr;
	int age;
	double money;

	void free();
	void copyFrom(const Player& other);

public:
	
	Player();
	Player(const char* name, const char* password, int age, double money);
	Player(const Player& other);
	Player& operator=(const Player& other);
	~Player();
	int getAge() const;
	char* getPassword() const;

	void changeName(const char* name);
};
