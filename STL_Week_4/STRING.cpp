

#include <iostream>
#include "STRING.h"


bool printMsg{ false };
int STRING::gid{};


STRING::STRING() : num{}, p{}, id{ ++gid } {
	if (printMsg) {
		print("디폴트 생성자");
	}
}

STRING::STRING(const char* s) : num{ strlen(s) }, id{ ++gid } {
	p = new char[num];
	memcpy(p, s, num);

	// 관찰메시지 on
	if (printMsg) {
		print("생성자");
	}
}

STRING::~STRING() {
	if (printMsg) {
		print("소멸자");
	}
	if (num) {
		delete[] p;
	}
}

STRING::STRING(const STRING& other) : num{ other.num }, id{ ++gid } {
	p = new char[num];
	memcpy(p, other.p, num);
	if (printMsg) {
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

	if (printMsg) {
		print("할당");
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
	std::cout << s << " [" << id << "] 객체: " << this;
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

