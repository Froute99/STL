/*
 * 2022. 05. 11
 * STL Class
 *
 * 
 * map<key, value, key_compare>
 *
 * 5/25(수) - 졸업연구설명회(? 2시30)
 * 5/30 ~ 6/20
 *
 */

#include <iostream>
#include <vector>
#include <map>
#include "save.h"
#include "STRING.h"

extern bool isMessageToggle;


int main() {
	std::map<std::string, std::vector<std::string>> gameCompany{ {"넥슨", {"바람의 나라", "메이플스토리"}} };

	std::pair<std::string, std::vector<std::string>> p{ "엔씨", {"리니지"} };
	gameCompany.insert(p);
	gameCompany.insert(std::make_pair("펄어비스", std::vector<std::string>{ "검은사막" }));

	// 리스트 전체 출력
	
	for (const auto& [회사, 게임들] : gameCompany) {
		std::cout << 회사 << " - ";
		for (const auto& 게임 : 게임들) {
			std::cout << 게임 << " ";
		}
		std::cout << std::endl;
	}

	std::string company;
	// [문제] 사용자가 입력한 회사의 게임을 출력
	while (true) {
		std::cout << "찾을 회사는? ";
		std::cin >> company;

		// 있으면 출력
		// 없으면 없다고 출력
	}
	

	//save("source.cpp", "STL_0511.txt");
}

