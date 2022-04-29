/**************************************************************************************
 *	File Name		: STRING.cpp
 *	Date			: 2022 03 30
 *	Author			: JH Kim
 *	Instruction		: STL ���� ������ �����Ϸ��� ���� �ڿ��� �����ϴ� Ŭ����
 *					: std::string ���� ��κ��� ���� �����ϸ� STL ���۹���� ����
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
		print("����Ʈ ������");
	}
}

STRING::STRING(const char* s)
	: num{ strlen(s) }, id{ ++gid } {
	dataPtr = new char[num];
	memcpy(dataPtr, s, num);

	// �����޽��� on
	if (isMessageToggle) {
		print("������");
	}
}

STRING::~STRING() {
	if (isMessageToggle) {
		print("�Ҹ���");
	}
	if (num) {
		delete[] dataPtr;
	}
}

STRING::STRING(const STRING& other) : num{ other.num }, id{ ++gid } {
	dataPtr = new char[num];
	memcpy(dataPtr, other.dataPtr, num);
	if (isMessageToggle) {
		print("���������");
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
		print("�Ҵ�");
	}
}

STRING::STRING(STRING&& other) noexcept
	: id{ ++gid } {
	num = other.num;
	dataPtr = other.dataPtr;

	other.num = 0;
	other.dataPtr = nullptr;
	if (isMessageToggle) {
		print("�̵�����");
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
		print("�̵��Ҵ�");
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
	std::cout << std::format("{:<13}", s) << " [" << id << "] ��ü: " << this;
	if (num) {
		std::cout << " - �ڿ�: " << num << " �ּ�: " << (void*)dataPtr;
	}
	else {
		std::cout << " - �ڿ�����";
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
