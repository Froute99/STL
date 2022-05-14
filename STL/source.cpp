/*
 * 2022. 05. 12
 * STL Class
 *
 * Containers are objects that store other objects.
 * 1. Sequence container
 * 2. Associative container - set/multi_set/map/multi_map
 * 
 *		map<key, value, key_compare>
 *
 * 5/25(수) - 졸업연구설명회(? 2시30)	지도교수 5/30 ~ 6/20
 * 6.15 기말고사
 * 
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include "save.h"

extern bool isMessageToggle;


int main() {
	// [문제] 알파벳과 빈도수를 화면에 출력하라
	// std::map<알파벳, 개수>

	std::ifstream in{ "Frankenstein.txt" };
	std::vector<std::string> v{ std::istream_iterator<std::string>{in}, {} };
	std::map<char, int> alphaNum;

	for (const auto& word : v)
		for (char letter : word)
			if (isalpha(letter))
				alphaNum[letter]++;


	std::cout << "단어 갯수 - " << v.size() << std::endl;

	// [문제] 이 소설에 사용된 단어와 개수를 출력하라.
	// 앞에서부터 20개만 출력하라
	// 개수 오름차순으로 정렬하라

	std::map<std::string, int, std::greater<int>> wordNum;

	for (const std::string& word : v) {
		wordNum[word]++;
	}

	std::vector<std::pair<std::string, int>> civ{ wordNum.begin(), wordNum.end() };
	std::sort(civ.begin(), civ.end(),
		[](const auto& a, const auto& b) {
			return a.second > b.second;
		});

	auto p = wordNum.begin();
	for (int i = 0; i < 1000; ++i, ++p) {
		std::cout << p->first << " - " << p->second << std::endl;
	}


	save("source.cpp", "STL_0512.txt");
}

