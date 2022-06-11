/*
 * 2022. 06. 09
 * STL Class
 * JH Kim
 *
 *
 * 14주 강의 - Anagram
 *
 *
 *		6.15 기말고사
 *		6.16 강의 끝 - 한 학기 강의를 정리 책 소개
 *		6.20 점수 공개 사무실 앞
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>
#include <ranges>
#include "save.h"
#include "STRING.h"


struct WP : public std::pair<std::string, std::string> {
	WP(const std::string& s) : std::pair<std::string, std::string>{ s, s } {
		std::sort(first.begin(), first.end());
	}
};



int main()
{
	save("source.cpp", "STL_0609.txt");

	std::ifstream in{ "단어들.txt" };

	std::vector<WP> v{ std::istream_iterator<std::string>{in}, {} };	// operator<<
	std::cout << "단어 개수 - " << v.size() << std::endl;				// 369882

	std::ranges::sort(v, {}, &WP::first);

	//std::sort(v.begin(), v.end(),
	//	[](const auto& wp1, const auto& wp2) {
	//		return wp1.first < wp2.first;
	//	});


	// [문제] 전체 anagram 쌍을 화면에 출력하라
	auto b = v.cbegin();
	//int cnt{};

	std::ofstream out{ "애너그램들.txt" };

	// [문제] 가장 갯수가 많은 애너그램은 몇 개?
	// [문제] 애너그램 갯수 순으로 출력하라
	std::vector<std::list<std::string>> vs;
	vs.reserve(31000);

	while (true)
	{
		auto i = std::adjacent_find(b, v.cend(),
			[](const WP& a, const WP& b) {
				return a.first == b.first;
			});
		if (i == v.cend())
		{
			break;
		}
		auto j = std::find_if_not(i + 1, v.cend(),
			[i](const WP& a) {
				return a.first == i->first;
			});
		// [i, j)는 애너그램 구간이다.
		std::list<std::string> ls;
		for (auto p = i; p < j; ++p)
		{
			ls.push_back(p->second);
		}
		vs.push_back(ls);

		b = j;
	}

	// vs를 개수 내림차순으로 정렬
	std::sort(vs.begin(), vs.end(),
		[](const std::list<std::string>& a, const std::list<std::string>& b) {
			return a.size() > b.size();
		});

	std::cout << "가장 많은 애너그램 - " << vs.begin()->size() << std::endl;

	for (const std::list<std::string>& ls : vs 
		| std::views::drop(100)
		| std::views::take(100))
	{
		for (const std::string& s : ls)
		{
			std::cout << s << "  ";
		}
		std::cout << std::endl;
	}


}

