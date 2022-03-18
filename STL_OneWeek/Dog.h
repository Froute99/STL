#pragma once

class Dog {
public:
	Dog(int number)
		: number(number) {}
	int number;

	// getter setter 안만들려고 friend 선언
	friend std::ostream& operator<<(std::ostream& os, const Dog& dog);
};