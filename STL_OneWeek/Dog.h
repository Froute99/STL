#pragma once

class Dog {
public:
	Dog(int number)
		: number(number) {}
	int number;

	// getter setter �ȸ������ friend ����
	friend std::ostream& operator<<(std::ostream& os, const Dog& dog);
};