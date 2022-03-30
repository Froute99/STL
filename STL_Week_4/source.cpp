/*
 * 2022. 03. 30
 * STL Class
 * Week 5
 * 
 * STRING Ŭ���� ���� �и�
 */



 // drmemory, makefile
 // ������ ����� class STRING �ۼ� ����(RAII)
 // ����: main()�� �������� ����ǰ� ����
 // ������ �� �ֵ��� special �Լ��� ��¸޽����� �߰��Ѵ�
 // ��ü�� �����ɶ����� ������ȣ�� �ش�



#include <iostream>
#include <array>
#include <algorithm>
#include "save.h"

#include "STRING.h"
extern bool printMsg;

int main() {
	//printMsg = true;

	std::array<STRING, 3> a{ "2022", "3", "30" };
	
	// ���� ������������ a�� ������ �� ���

	sort(a.begin(), a.end(), [](STRING& a, STRING& b) {
		return a.getNumber() < b.getNumber();
		});

	for (const auto& x : a) {
		std::cout << x;
	}
	
	save("source.cpp");
}

