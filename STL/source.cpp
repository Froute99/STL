/*
 * 2022. 05. 11
 * STL Class
 *
 * 
 * map<key, value, key_compare>
 *
 * 5/25(��) - ������������ȸ(? 2��30)
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
	std::map<std::string, std::vector<std::string>> gameCompany{ {"�ؽ�", {"�ٶ��� ����", "�����ý��丮"}} };

	std::pair<std::string, std::vector<std::string>> p{ "����", {"������"} };
	gameCompany.insert(p);
	gameCompany.insert(std::make_pair("�޾��", std::vector<std::string>{ "�����縷" }));

	// ����Ʈ ��ü ���
	
	for (const auto& [ȸ��, ���ӵ�] : gameCompany) {
		std::cout << ȸ�� << " - ";
		for (const auto& ���� : ���ӵ�) {
			std::cout << ���� << " ";
		}
		std::cout << std::endl;
	}

	std::string company;
	// [����] ����ڰ� �Է��� ȸ���� ������ ���
	while (true) {
		std::cout << "ã�� ȸ���? ";
		std::cin >> company;

		// ������ ���
		// ������ ���ٰ� ���
	}
	

	//save("source.cpp", "STL_0511.txt");
}

