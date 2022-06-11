/*
 * 2022. 06. 09
 * STL Class
 * JH Kim
 *
 *
 * 14�� ���� - Anagram
 *
 *
 *		6.15 �⸻���
 *		6.16 ���� �� - �� �б� ���Ǹ� ���� å �Ұ�
 *		6.20 ���� ���� �繫�� ��
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

	std::ifstream in{ "�ܾ��.txt" };

	std::vector<WP> v{ std::istream_iterator<std::string>{in}, {} };	// operator<<
	std::cout << "�ܾ� ���� - " << v.size() << std::endl;				// 369882

	std::ranges::sort(v, {}, &WP::first);

	//std::sort(v.begin(), v.end(),
	//	[](const auto& wp1, const auto& wp2) {
	//		return wp1.first < wp2.first;
	//	});


	// [����] ��ü anagram ���� ȭ�鿡 ����϶�
	auto b = v.cbegin();
	//int cnt{};

	std::ofstream out{ "�ֳʱ׷���.txt" };

	// [����] ���� ������ ���� �ֳʱ׷��� �� ��?
	// [����] �ֳʱ׷� ���� ������ ����϶�
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
		// [i, j)�� �ֳʱ׷� �����̴�.
		std::list<std::string> ls;
		for (auto p = i; p < j; ++p)
		{
			ls.push_back(p->second);
		}
		vs.push_back(ls);

		b = j;
	}

	// vs�� ���� ������������ ����
	std::sort(vs.begin(), vs.end(),
		[](const std::list<std::string>& a, const std::list<std::string>& b) {
			return a.size() > b.size();
		});

	std::cout << "���� ���� �ֳʱ׷� - " << vs.begin()->size() << std::endl;

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

