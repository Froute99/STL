

#include <iostream>
#include "STRING.h"


bool printMsg{ false };
int STRING::gid{};


STRING::STRING() : num{}, p{}, id{ ++gid } {
	if (printMsg) {
		print("����Ʈ ������");
	}
}

STRING::STRING(const char* s) : num{ strlen(s) }, id{ ++gid } {
	p = new char[num];
	memcpy(p, s, num);

	// �����޽��� on
	if (printMsg) {
		print("������");
	}
}

STRING::~STRING() {
	if (printMsg) {
		print("�Ҹ���");
	}
	if (num) {
		delete[] p;
	}
}

STRING::STRING(const STRING& other) : num{ other.num }, id{ ++gid } {
	p = new char[num];
	memcpy(p, other.p, num);
	if (printMsg) {
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

	if (printMsg) {
		print("�Ҵ�");
	}
}

STRING STRING::operator+(const STRING& rhs) const {
	STRING temp;
	temp.num = num + rhs.num;
	temp.p = new char[temp.num];

	memcpy(temp.p, p, num);
	memcpy(temp.p + num, rhs.p, rhs.num);

	return temp;
}

void STRING::print(const char* s) const {
	std::cout << s << " [" << id << "] ��ü: " << this;
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

