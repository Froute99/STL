/**************************************************************************************
 *	File Name		: STRING.h
 *	Date			: 2022 03 30
 *	Author			: JH Kim
 *	Instruction		: STL 내부 동작을 관찰하려고 만든 자원을 관리하는 클래스
 *					: std::string 동작 대부분을 직접 구현하며 STL 동작방식을 이해
 **************************************************************************************/

#pragma once

class STRING {
public:
	STRING();
	STRING(const char* s);

	~STRING();

	STRING(const STRING& other);

	STRING& operator=(const STRING& other);
	STRING operator+(const STRING& rhs) const;

	//char operator[](const int index);
	//bool operator==(const STRING& other);
	
	size_t getNumber() const { return num; }

	void print(const char* s) const;

	friend std::ostream& operator<<(std::ostream& os, const STRING& string);

private:
	size_t num;							// 관리하는 자원 수
	char* p;							// 자원의 주소
	int id;								// 생성 시 부여한 고유값
	static int gid;						// 아이디 생성용
};

