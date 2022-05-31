/*
 * 2022. 05. 26
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

