/*
 * 2022. 03. 23
 * STL Class
 * Week 4
 * 
 * ȣ�Ⱑ��Ÿ��(Callable type) - sort�� ���� �˾ƺ���
 * 
 * �ڿ��� Ȯ���ϴ� ������ Ŭ���� STRING - �����̳�/�ݺ���/�˰���
 */

#include <iostream>
#include "save.h"

//std::random_device rd;
//std::default_random_engine dre(rd());
//std::uniform_int_distribution<int> uid(1, 100);


// �޸� ������ ���� �Ұ�
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

