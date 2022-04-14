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

	// 2022.4.7 �̵�������/�̵��Ҵ翬����
	STRING(STRING&& other) noexcept;
	STRING& operator=(STRING&& other) noexcept;

	STRING operator+(const STRING& rhs) const;

	bool operator==(const STRING& other);
	
	size_t getNumber() const { return num; }
	char* GetName() const { return p; }

	void print(const char* s) const;

	friend std::ostream& operator<<(std::ostream& os, const STRING& string);

private:
	size_t num;							// �����ϴ� �ڿ� ��
	char* p;							// �ڿ��� �ּ�
	int id;								// ���� �� �ο��� ������
	static int gid;						// ���̵� ������
};

