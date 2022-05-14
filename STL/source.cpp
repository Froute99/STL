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
 * 5/25(��) - ������������ȸ(? 2��30)	�������� 5/30 ~ 6/20
 * 6.15 �⸻���
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
	// [����] ���ĺ��� �󵵼��� ȭ�鿡 ����϶�
	// std::map<���ĺ�, ����>

	std::ifstream in{ "Frankenstein.txt" };
	std::vector<std::string> v{ std::istream_iterator<std::string>{in}, {} };
	std::map<char, int> alphaNum;

	for (const auto& word : v)
		for (char letter : word)
			if (isalpha(letter))
				alphaNum[letter]++;


	std::cout << "�ܾ� ���� - " << v.size() << std::endl;

	// [����] �� �Ҽ��� ���� �ܾ�� ������ ����϶�.
	// �տ������� 20���� ����϶�
	// ���� ������������ �����϶�

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

