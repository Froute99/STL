/*
 * 2022. 03. 16
 * STL Class
 * Week 3
 * 
 * 오늘 - C++ 컴파일러가 값을 아는 시점
 *	1. 실행전	- constexpr
 *	2. 실행중	- dynamic allocation
 */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <array>
#include "save.h"

int main() {

	std::ifstream in{ "int 1000개.txt", std::ios::binary };

	int num[1000];

	in.read((char*)&num, sizeof(int) * 1000);
	std::cout << *std::max_element(std::begin(num), std::end(num));

}

