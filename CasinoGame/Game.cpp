#include "Game.h"
#include "Player.h"
#include <iostream>
#include <stdlib.h>

void Game::generateNumber() {
	srand(time(NULL));
	number = rand() % 100 + 1;
}

bool Game::isPrime() {
	double temp = sqrt(number);
	for (int i = 2; i <= temp; i++)
	{
		if (number % i == 0)
		{
			return false;
		}
	}
	return true;
}

bool Game::isPowerOf2()  {
	while (number != 0) {
		if (number == 1 || number == -2) {
			return true;
		}
		if (number % 2 == 1 || number % 2 == -1) {
			return false;
		}
		number /= 2;
	}
	return false;
}

bool Game::isOdd() {
	return number % 2 == 1;
}

bool Game::isHigerThan(int number) {
	return this->number <= number;
}

bool Game::isEligible(int age) {
	return age > 18;
}

void Game::play(Player& player) {
	char password[15] = { "12345678"};
	std::cout << "Please eneter your password:" << std::endl;
	while (player.isCorrectPassword(password)) {
		std::cout << "Wrong password, try again: " << std::endl;
	}
	if (!isEligible(player.getAge())) {
		std::cout << "Sorry you are not eligible to play you must be at least 18 years old" << std::endl;
		return;
	}
	while (player.getMoney() > 0) {
		std::cout << "Place your bet:" << std::endl;
		double bet = 5;
		this->bet = bet;
		player.setMoney(player.getMoney() - bet);
		generateNumber();
		std::cout << "We have a number, try to guess it:" << std::endl;
		std::cout << "IsEven - E, IsOdd - O, IsPowerOf2 - P, isHigherThan - H, isLowerThan - L, Guess the exact Number - X"<<std::endl;
		char command;
		std::cin >> command;
		switch (command)
		{
		case 'E':
			if (!isOdd()) {
				player.setMoney(bet + 0.2 * bet);
				std::cout << "Congratulations!";
			}
			else {
				std::cout << "Better luck next time, play again!";
			}
			break;
	}
	std::cout << "Looks like you have no money left :(" << std::endl;
	double bet


}