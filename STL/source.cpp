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
 *  reverse iterator -	반드시 class로 만들어야 한다
 *						++연산이 실제로는 왼쪽으로 가야되기 때문
 * 
 * 
 *	5.5 수업
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

	// [문제] 어떤 문자가 입력받은 단어의 몇 번째 문자인지 출력하라

	while (true) {
		std::cout << "문자를 입력하세요: ";
		char c;
		std::cin >> c;

		auto found = my_find(word.begin(), word.end(), c);
		if (found == word.end()) {
			std::cout << "없음" << std::endl;
			continue;
		}
		std::cout << c << "는 " << std::distance(word.begin(), found) + 1
			<< "번째 문자입니다.";
	}
	

	//save("source.cpp", "STL_0428.txt");
}

