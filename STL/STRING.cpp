/**************************************************************************************
 *	File Name		: STRING.cpp
 *	Date			: 2022 03 30
 *	Author			: JH Kim
 *	Instruction		: STL ���� ������ �����Ϸ��� ���� �ڿ��� �����ϴ� Ŭ����
 *					: std::string ���� ��κ��� ���� �����ϸ� STL ���۹���� ����
 **************************************************************************************/

#include <iostream>
#include <format>
#include "STRING.h"

bool isMessageToggle{ false };
int STRING::gid{};

STRING::STRING()
	: num{}, p{}, id{ ++gid } {
	if (isMessageToggle) {
		print("����Ʈ ������");
	}
}

STRING::STRING(const char* s)
	: num{ strlen(s) }, id{ ++gid } {
	p = new char[num];
	memcpy(p, s, num);

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
		delete[] p;
	}
}

STRING::STRING(const STRING& other) : num{ other.num }, id{ ++gid } {
	p = new char[num];
	memcpy(p, other.p, num);
	if (isMessageToggle) {
		print("���������");
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
		print("�Ҵ�");
	}
}

STRING::STRING(STRING&& other) noexcept
	: id{ ++gid } {
	num = other.num;
	p = other.p;

	other.num = 0;
	other.p = nullptr;
	if (isMessageToggle) {
		print("�̵�����");
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
		print("�̵��Ҵ�");
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
	std::cout << std::format("{:<13}", s) << " [" << id << "] ��ü: " << this;
	if (num) {
		std::cout << " - �ڿ�: " << num << " �ּ�: " << (void*)p;
	}
	else {
		std::cout << " - �ڿ�����";
	}
	std::cout << std::endl;
}

std::ostream& operator<<(std::ostream& os, const STRING& string) {
	for (size_t i{}; i < string.num; ++i) {
		os << string.p[i];
	}
	return os;
}

