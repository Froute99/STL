/*
 * 2022. 03. 16
 * STL Class
 * Week 3
 * 
 * ���� - C++ �����Ϸ��� ���� �ƴ� ����
 *	1. ������	- constexpr
 *	2. ������	- dynamic allocation
 */

// c++ paradigm
// object oriented, procedural, generic, meta, functional

// constexpr �˾ƺ���	int õ�� ����ϴ°� �� �ȵǴ��� ã�ƺ���

#include <iostream>
#include <fstream>
#include <cctype>
#include "save.h"

// [����] "source.cpp" �� �о
// �ҹ��ڸ� �빮�ڷ� �ٲ㼭
// source_capital.cpp"�� ����


int main() {

	std::ifstream in{ "source.cpp",  };

	char c;

	while (in.read(&c, sizeof(char))) {
		std::cout << std::tolower(c);
	}
	
	

	std::ofstream out("source_capital.cpp");

	save("source.cpp");
}

