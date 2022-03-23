/*
 * 2022. 03. 23
 * STL Class
 * Week 4
 * 
 * 호출가능타입(Callable type) - sort를 통해 알아본다
 * 
 * 자원을 확보하는 관찰용 클래스 STRING - 컨테이너/반복자/알고리즘
 */

#include <iostream>
#include "save.h"

//std::random_device rd;
//std::default_random_engine dre(rd());
//std::uniform_int_distribution<int> uid(1, 100);


// 메모리 마지막 동네 소개
//
//

void f() {
	std::cout << "f" << std::endl;
}

int main() {
	void(*const ptr)(void) = f;

	(*ptr)();

	std::cout << std::addressof(f) << std::endl;
	std::cout << std::addressof(main) << std::endl;
	std::cout << std::addressof(save) << std::endl;

	save("source.cpp");
}

