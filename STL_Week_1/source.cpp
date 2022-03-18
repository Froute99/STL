/*
 * 2022. 03. 16
 * STL Class
 * Week 3
 * 
 * ���� - C++ �����Ϸ��� ���� �ƴ� ����
 *	1. ������	- constexpr
 *	2. ������	- dynamic allocation
 */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <array>
#include "save.h"

int main() {

	std::ifstream in{ "int 1000��.txt", std::ios::binary };

	int num[1000];

	in.read((char*)&num, sizeof(int) * 1000);
	std::cout << *std::max_element(std::begin(num), std::end(num));

}

