/**************************************************************************************
 *	File Name		: STRING.h
 *	Date			: 2022 03 30
 *	Author			: JH Kim
 *	Instruction		: STL 내부 동작을 관찰하려고 만든 자원을 관리하는 클래스
 *					: std::string 동작 대부분을 직접 구현하며 STL 동작방식을 이해
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

	// 2022. 4. 28 sort 가능하도록 연산자 추가

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

// 2022. 4. 27 STRING이 제공할 역방향반복자
class STRING_reverse_iterator {
public:
	STRING_reverse_iterator(char* ptr)
		: dataPtr{ ptr } {}

	STRING_reverse_iterator& operator++();

	// 관계연산자는 우주선연산자로 한번에 해결 C++20
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

	// 2022.4.7 이동생성자/이동할당연산자
	STRING(STRING&& other) noexcept;
	STRING& operator=(STRING&& other) noexcept;

	STRING operator+(const STRING& rhs) const;
	
	// 2022. 4. 28 sort를 위해 default < 연산자 제공
	bool operator<(const STRING& rhs) const {
		return std::lexicographical_compare(begin(), end(),
			rhs.begin(), rhs.end());
	}

	// 2022. 5. 18 unordered_set이 요구하는 == 코딩
	bool operator==(const STRING& rhs) const {
		return std::string(begin(), end()) == std::string(rhs.begin(), rhs.end());
	}

	// 2022. 4. 21 begin(), end() 제공
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
	// 2022. 4. 28 추가
	friend std::istream& operator>>(std::istream& is, STRING& s);

private:
	size_t num;							// 관리하는 자원 수
	char* dataPtr;							// 자원의 주소
	int id;								// 생성 시 부여한 고유값
	static int gid;						// 아이디 생성용
};

