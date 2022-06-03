/*
 * 2022. 06. 02
 * STL Class
 * JH Kim
 *
 *
 * C++20의 핵심
 * concepts
 * range/view
 *		coroutine	-
 *		module		- ixx
 *
 *
 * type traits
 *
 *
 *		6.15 기말고사
 *		6.16 강의 끝 - 한 학기 강의를 정리 책 소개
 *		6.20 점수 공개 사무실 앞
 */

#include <iostream>
#include <ranges>
#include <format>
#include "save.h"
#include "STRING.h"


int main()
{
	// [문제] 10000부터 시작하는 무한개의 자연수를 생성하고 홀수 2000개만 역순으로 출력하라
	auto odd = [](int n) { return n % 2; };
	for (int n : std::views::iota(10000) | std::views::reverse
										 | std::views::filter(odd)
										 | std::views::take(2000)
										 )
		std::cout << std::format("{:8}", n);
	std::cout << std::endl;

	save("source.cpp", "STL_0602.txt");
}

