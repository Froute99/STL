/**************************************************************************************
 *	File Name		: STRING.cpp
 *	Date			: 2022 03 30
 *	Author			: JH Kim
 *	Instruction		: STL 내부 동작을 관찰하려고 만든 자원을 관리하는 클래스
 *					: std::string 동작 대부분을 직접 구현하며 STL 동작방식을 이해
 **************************************************************************************/

#include <iostream>
#include <format>
#include "STRING.h"

bool isMessageToggle{ false };
int STRING::gid{};

STRING::STRING()
	: num{}, p{}, id{ ++gid } {
	if (isMessageToggle) {
		print("디폴트 생성자");
	}
}

STRING::STRING(const char* s)
	: num{ strlen(s) }, id{ ++gid } {
	p = new char[num];
	memcpy(p, s, num);

	// 관찰메시지 on
	if (isMessageToggle) {
		print("생성자");
	}
}

STRING::~STRING() {
	if (isMessageToggle) {
		print("소멸자");
	}
	if (num) {
		delete[] p;
	}
}

STRING::STRING(const STRING& other) : num{ other.num }, id{ ++gid } {
	p = new char[num];
	memcpy(p, other.p, num);
	if (isMessageToggle) {
		print("복사생성자");
	}
}

STRING& STRING::operator=(const STRING& other) {
	if (this == &other) {
		return *this;
	}

	if (num) {
		delete[] p;
	}

	num = other.num;
	p = new char[num];
	memcpy(p, other.p, num);

	if (isMessageToggle) {
		print("할당");
	}
}

STRING::STRING(STRING&& other) noexcept
	: id{ ++gid } {
	num = other.num;
	p = other.p;

	other.num = 0;
	other.p = nullptr;
	if (isMessageToggle) {
		print("이동생성");
	}
}

STRING& STRING::operator=(STRING&& other) noexcept {
	if (this != &other) {
		if (num) {
			delete[] p;

			num = other.num;
			p = other.p;

			other.num = 0;
			other.p = nullptr;
		}
	}

	if (isMessageToggle) {
		print("이동할당");
	}
	
	return *this;
}

STRING STRING::operator+(const STRING& rhs) const {
	STRING temp;
	temp.num = num + rhs.num;
	temp.p = new char[temp.num];

	memcpy(temp.p, p, num);
	memcpy(temp.p + num, rhs.p, rhs.num);

	return temp;
}

bool STRING::operator==(const STRING& other) {
	if (this->num == other.num) {
		return *this->p == *other.p;
	}
	return false;
}

void STRING::print(const char* s) const {
	std::cout << std::format("{:<13}", s) << " [" << id << "] 객체: " << this;
	if (num) {
		std::cout << " - 자원: " << num << " 주소: " << (void*)p;
	}
	else {
		std::cout << " - 자원없음";
	}
	std::cout << std::endl;
}

std::ostream& operator<<(std::ostream& os, const STRING& string) {
	for (size_t i{}; i < string.num; ++i) {
		os << string.p[i];
	}
	return os;
}

