/*
 * 2022. 04. 28
 * STL Class
 *
 * 
 *  1. Sequence container
 *  2. Associative container
 * 
 *  iterator -	iterators are a generalization of pointers
 *				that allow a C++ program to work with differnt data structures
 *				(for example, container sand ranges) in a uniform manner.
 *  reverse iterator -	�ݵ�� class�� ������ �Ѵ�
 *						++������ �����δ� �������� ���ߵǱ� ����
 * 
 * 
 *	5.5 ����
 */


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "save.h"
#include "STRING.h"

extern bool isMessageToggle;

template <class Iter>
void show(Iter xxx) {
	std::cout << typeid(std::iterator_traits<Iter>::iterator_category).name() << std::endl;

}

template <class Iter, class value>
Iter my_find(Iter begin, Iter end, value toFInd) {
	while (begin != end) {
		if (*begin == toFind)
			return begin;
		++begin;
	}
	return end;
}


int main() {


	STRING word;
	std::cin >> word;

	// [����] � ���ڰ� �Է¹��� �ܾ��� �� ��° �������� ����϶�

	while (true) {
		std::cout << "���ڸ� �Է��ϼ���: ";
		char c;
		std::cin >> c;

		auto found = my_find(word.begin(), word.end(), c);
		if (found == word.end()) {
			std::cout << "����" << std::endl;
			continue;
		}
		std::cout << c << "�� " << std::distance(word.begin(), found) + 1
			<< "��° �����Դϴ�.";
	}
	

	//save("source.cpp", "STL_0428.txt");
}

