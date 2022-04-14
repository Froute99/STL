/*
 * 2022. 04. 13
 * STL Class
 *
 * �߰����� Ȯ�� - 4.20 ��
 * 
 * 
 *  * 1. Sequence container
 *		array			- �����ϰ� ũ�Ⱑ ����, [] ��ü
 *		vector			- dynamic size array, O(1) - random access
 *						- �߰��� insert�ϴ� ������ �񰡸� �˾ƺô�.
 *		deque		
 *		forward_list
 *		list			- ��ü���� 2�� ����Ͽ� ���Ի��� O(1)
 */

 // ���� std::vector<Player>

#include <iostream>
#include <fstream>
#include <deque>
#include <list>
#include <algorithm>
#include "save.h"
#include "STRING.h"

extern bool isMessageToggle;


int main() {
	// [����] "����.txt"�� �ܾ �о� �������� ���� �� ����϶�

	std::ifstream in{ "����.txt" };
	
	std::list<std::string> cont;
	
	std::string s;
	while (in >> s) {
		cont.push_back(s);
	}

	// [����] ���ڼ��� 5���ΰ͸� ���

	std::copy_if(cont.begin(), cont.end(), std::ostream_iterator<std::string>{std::cout, "\n"},
		[](const std::string& s) {
			return s.size() == 5;
		});
	


	save("source.cpp", "STL 7-1.txt");
}

