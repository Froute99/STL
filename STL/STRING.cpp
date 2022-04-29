/**************************************************************************************
 *	File Name		: STRING.cpp
 *	Date			: 2022 03 30
 *	Author			: JH Kim
 *	Instruction		: STL 내부 동작을 관찰하려고 만든 자원을 관리하는 클래스
 *					: std::string 동작 대부분을 직접 구현하며 STL 동작방식을 이해
 **************************************************************************************/

#include <iostream>
#include <format>
#include <algorithm>
#include "STRING.h"

bool isMessageToggle{ false };
int STRING::gid{};

STRING_iterator& STRING_iterator::operator++() {
	++dataPtr;
	return *this;
}

STRING_iterator STRING_iterator::operator++(int) {
	char* oldPtr = dataPtr++;
	return STRING_iterator(oldPtr);
}

STRING_iterator& STRING_iterator::operator--() {
	--dataPtr;
	return *this;
}

STRING_iterator STRING_iterator::operator--(int) {
	char* oldPtr = dataPtr--;
	return STRING_iterator(oldPtr);
}

char& STRING_iterator::operator*() const {
	if (this == nullptr) {
		throw("Invalid pointer");
	}
	return *dataPtr;
}

STRING_iterator STRING_iterator::operator+(difference_type offset) const {
	return STRING_iterator{ dataPtr + offset };
}

STRING_iterator STRING_iterator::operator-(difference_type offset) const {
	return STRING_iterator{ dataPtr - offset };
}

//STRING_iterator STRING_iterator::operator+(int offset) {
//	dataPtr += offset;
//	return *this;
//}
//
//STRING_iterator STRING_iterator::operator-(int offset) {
//	dataPtr -= offset;
//	return *this;
//}

STRING_reverse_iterator& STRING_reverse_iterator::operator++() {
	--dataPtr;
	return*this;
}

char& STRING_reverse_iterator::operator*() const {
	if (this == nullptr) {
		throw("Invalid pointer");
	}

	return *(dataPtr - 1);
}

STRING::STRING()
	: num{}, dataPtr{}, id{ ++gid } {
	if (isMessageToggle) {
		print("디폴트 생성자");
	}
}

STRING::STRING(const char* s)
	: num{ strlen(s) }, id{ ++gid } {
	dataPtr = new char[num];
	memcpy(dataPtr, s, num);

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
		delete[] dataPtr;
	}
}

STRING::STRING(const STRING& other) : num{ other.num }, id{ ++gid } {
	dataPtr = new char[num];
	memcpy(dataPtr, other.dataPtr, num);
	if (isMessageToggle) {
		print("복사생성자");
	}
}

STRING& STRING::operator=(const STRING& other) {
	if (this == &other) {
		return *this;
	}

	if (num) {
		delete[] dataPtr;
	}

	num = other.num;
	dataPtr = new char[num];
	memcpy(dataPtr, other.dataPtr, num);

	if (isMessageToggle) {
		print("할당");
	}
}

STRING::STRING(STRING&& other) noexcept
	: id{ ++gid } {
	num = other.num;
	dataPtr = other.dataPtr;

	other.num = 0;
	other.dataPtr = nullptr;
	if (isMessageToggle) {
		print("이동생성");
	}
}

STRING& STRING::operator=(STRING&& other) noexcept {
	if (this != &other) {
		if (num) {
			delete[] dataPtr;

			num = other.num;
			dataPtr = other.dataPtr;

			other.num = 0;
			other.dataPtr = nullptr;
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
	temp.dataPtr = new char[temp.num];

	memcpy(temp.dataPtr, dataPtr, num);
	memcpy(temp.dataPtr + num, rhs.dataPtr, rhs.num);

	return temp;
}

//bool STRING::operator==(const STRING& other) {
//	if (this->num == other.num) {
//		return *this->p == *other.p;
//	}
//	return false;
//}

void STRING::print(const char* s) const {
	std::cout << std::format("{:<13}", s) << " [" << id << "] 객체: " << this;
	if (num) {
		std::cout << " - 자원: " << num << " 주소: " << (void*)dataPtr;
	}
	else {
		std::cout << " - 자원없음";
	}
	std::cout << std::endl;
}

std::ostream& operator<<(std::ostream& os, const STRING& s) {
	for (size_t i{}; i < s.num; ++i) {
		os << s.dataPtr[i];
	}
	return os;
}

std::istream& operator>>(std::istream& is, STRING& s) {
	std::string str;
	is >> str;
	s = STRING(str.c_str());
	return is;
}
