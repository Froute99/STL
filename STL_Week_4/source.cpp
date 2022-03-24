/*
 * 2022. 03. 24
 * STL Class
 * Week 4
 * 
 * 호출가능타입(Callable type)
 * 1. 함수포인터 - CODE에서 해당함수의 시작번지를 저장
 * 2. 람다(lambda) - 컴파일러가 만들어주는 class이다. (? class가 호출가능 타입?)
 * 3. ()을 오버로딩한 class ()는 함수호출 연산자
 * 4. 멤버함수(method) 포인터
 * 
 * 호출가능한 타입은 무한개이다(람다때문)
 * --> 모든 호출가능타입을 통일된 방식으로 표현할 수 있는 클래스, function
 * 
 * 자원을 확보하는 관찰용 클래스 STRING - 컨테이너/반복자/알고리즘
 */



 // drmemory, makefile
 // 앞으로 사용할 class STRING 작성 시작(RAII)
 // 문제: main()이 문제없이 실행되게 하자
 // 관찰할 수 있도록 special 함수에 출력메시지를 추가한다
 // 객체가 생성될때마다 고유번호를 준다



#include <iostream>
#include <functional>
#include "save.h"

class STRING {
public:
	STRING(const char* s) : num(strlen(s)), p{ new char[num] } {
		id = ++gid;
		memcpy(p, s, num);
		// 관찰메시지 on
		std::cout << "ctor [" << id << "] 주소: " << this << std::endl;
	}
	~STRING() {
		// 관찰메시지 on
		std::cout << "dtor [" << id << "] 주소: " << this << std::endl;
		delete[] p;
	}


	friend std::ostream& operator<<(std::ostream& os, const STRING& string);

private:
	int num;
	char* p;
	int id;
	static int gid;
};

std::ostream& operator<<(std::ostream& os, const STRING& string) {

	return os;
}

int STRING::gid{};


int main() {

	STRING a{ "2022 3 24" };
	STRING b{ "STL STRING 작성 시작" };
	
	//std::cout << a << std::endl;
	//std::cout << b << std::endl;

	save("source.cpp");
}

