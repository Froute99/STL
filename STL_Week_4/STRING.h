/**************************************************************************************
 *	File Name		: STRING.h
 *	Date			: 2022 03 30
 *	Author			: JH Kim
 *	Instruction		: STL ���� ������ �����Ϸ��� ���� �ڿ��� �����ϴ� Ŭ����
 *					: std::string ���� ��κ��� ���� �����ϸ� STL ���۹���� ����
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
	size_t num;							// �����ϴ� �ڿ� ��
	char* p;							// �ڿ��� �ּ�
	int id;								// ���� �� �ο��� ������
	static int gid;						// ���̵� ������
};

