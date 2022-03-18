/*
 * 2022. 03. 16
 * STL Class
 * Week 3
 * 
 * 오늘 - C++ 컴파일러가 값을 아는 시점
 *	1. 실행전	- constexpr
 *	2. 실행중	- dynamic allocation
 */

// c++ paradigm
// object oriented, procedural, generic, meta, functional

// constexpr 알아보기	int 천개 출력하는거 왜 안되는지 찾아보기

#include <iostream>
#include <fstream>
#include <cctype>
#include "save.h"

// [문제] "source.cpp" 를 읽어서
// 소문자를 대문자로 바꿔서
// source_capital.cpp"로 저장


int main() {

	std::ifstream in{ "source.cpp",  };

	char c;

	while (in.read(&c, sizeof(char))) {
		std::cout << std::tolower(c);
	}
	
	

	std::ofstream out("source_capital.cpp");

	save("source.cpp");
}

