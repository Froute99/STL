/*
 * 2022. 06. 02
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
#include <ranges>
#include <format>
#include "save.h"
#include "STRING.h"


int main()
{
	// [����] 10000���� �����ϴ� ���Ѱ��� �ڿ����� �����ϰ� Ȧ�� 2000���� �������� ����϶�
	auto odd = [](int n) { return n % 2; };
	for (int n : std::views::iota(10000) | std::views::reverse
										 | std::views::filter(odd)
										 | std::views::take(2000)
										 )
		std::cout << std::format("{:8}", n);
	std::cout << std::endl;

	save("source.cpp", "STL_0602.txt");
}

