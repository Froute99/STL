/*
 * 2022. 05. 26
 * STL Class
 * JH Kim
 *
 * 
 * C++20�� �ٽ�
 * concepts
 * range/view
 *		coroutine	- 
 *		module		- ixx
 * 
 * 
 * type traits
 * 
 * 
 *		6.15 �⸻���
 *		6.16 ���� �� - �� �б� ���Ǹ� ���� å �Ұ�
 *		6.20 ���� ���� �繫�� ��
 */

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <concepts>
#include <ranges>
#include "save.h"
#include "STRING.h"

extern bool isMessageToggle;


int main() {

	std::vector<int> v{ 1,2,3,4,5 };

	std::ranges::sort(v, std::greater<int>(), {});

	for (int n : v) {
		std::cout << n << " ";
	}
	std::cout << std::endl;

	save("source.cpp", "STL_0526.txt");
}

