/**************************************************************************************
 *	File Name		: STRING.h
 *	Date			: 2022 03 30
 *	Author			: JH Kim
 *	Instruction		: STL ���� ������ �����Ϸ��� ���� �ڿ��� �����ϴ� Ŭ����
 *					: std::string ���� ��κ��� ���� �����ϸ� STL ���۹���� ����
 **************************************************************************************/

#pragma once

class STRING_iterator {
public:
	using iterator_category = std::random_access_iterator_tag;
	using value_type = char;
	using difference_type = ptrdiff_t;
	using pointer = char*;
	using reference = char&;


	STRING_iterator(char* dataPtr)
		: dataPtr{ dataPtr } {}

	difference_type operator-(const STRING_iterator& rhs) const {
		return dataPtr - rhs.dataPtr;
	}

	// 2022. 4. 28 sort �����ϵ��� ������ �߰�

	auto operator<=>(const STRING_iterator& rhs) const = default;
	
	STRING_iterator& operator++();		// Pre increment
	STRING_iterator operator++(int);	// Post increment
	STRING_iterator& operator--();		// Pre decrement
	STRING_iterator operator--(int);	// Post decrement

	char& operator*() const;

	STRING_iterator operator+(difference_type offset) const;
	STRING_iterator operator-(difference_type offset) const;

private:
	char* dataPtr;
};

// 2022. 4. 27 STRING�� ������ ������ݺ���
class STRING_reverse_iterator {
public:
	STRING_reverse_iterator(char* ptr)
		: dataPtr{ ptr } {}

	STRING_reverse_iterator& operator++();

	// ���迬���ڴ� ���ּ������ڷ� �ѹ��� �ذ� C++20
	// spaceship operator(three-way comparison operator)
	auto operator<=>(const STRING_reverse_iterator& rhs) const = default;
	char& operator*() const;
private:
	char* dataPtr;
};


class STRING {
public:
	using iterator = STRING_iterator;
	using reverse_iterator = STRING_reverse_iterator;



	STRING();
	STRING(const char* s);

	~STRING();

	STRING(const STRING& other);

	STRING& operator=(const STRING& other);

	// 2022.4.7 �̵�������/�̵��Ҵ翬����
	STRING(STRING&& other) noexcept;
	STRING& operator=(STRING&& other) noexcept;

	STRING operator+(const STRING& rhs) const;
	
	// 2022. 4. 28 sort�� ���� default < ������ ����
	bool operator<(const STRING& rhs) const {
		return std::lexicographical_compare(begin(), end(),
			rhs.begin(), rhs.end());
	}

	// 2022. 5. 18 unordered_set�� �䱸�ϴ� == �ڵ�
	bool operator==(const STRING& rhs) const {
		return std::string(begin(), end()) == std::string(rhs.begin(), rhs.end());
	}

	// 2022. 4. 21 begin(), end() ����
	iterator begin() const { return iterator{ dataPtr }; }
	iterator end() const { return iterator{ dataPtr + num }; };

	reverse_iterator rbegin() {
		return reverse_iterator(dataPtr + num);
	}
	reverse_iterator rend() {
		return reverse_iterator(dataPtr);
	}

	size_t GetNum() const { return num; }
	char* GetName() const { return dataPtr; }

	void print(const char* s) const;

	friend std::ostream& operator<<(std::ostream& os, const STRING& s);
	// 2022. 4. 28 �߰�
	friend std::istream& operator>>(std::istream& is, STRING& s);

private:
	size_t num;							// �����ϴ� �ڿ� ��
	char* dataPtr;							// �ڿ��� �ּ�
	int id;								// ���� �� �ο��� ������
	static int gid;						// ���̵� ������
};

