/*
 * 2022. 04. 13
 * STL Class
 *
 * 중간시험 확정 - 4.20 수
 * 
 * 
 *  * 1. Sequence container
 *		array			- 유일하게 크기가 고정, [] 대체
 *		vector			- dynamic size array, O(1) - random access
 *						- 중간에 insert하는 동작의 댓가를 알아봤다.
 *		deque		
 *		forward_list
 *		list			- 객체마다 2개 사용하여 삽입삭제 O(1)
 */

 // 과제 std::vector<Player>

#include <iostream>
#include <fstream>
#include <deque>
#include <list>
#include <algorithm>
#include "save.h"
#include "STRING.h"

extern bool isMessageToggle;


int main() {
	// [문제] "연습.txt"의 단어를 읽어 오름차순 정렬 후 출력하라

	std::ifstream in{ "연습.txt" };
	
	std::list<std::string> cont;
	
	std::string s;
	while (in >> s) {
		cont.push_back(s);
	}

	// [문제] 글자수가 5개인것만 출력

	std::copy_if(cont.begin(), cont.end(), std::ostream_iterator<std::string>{std::cout, "\n"},
		[](const std::string& s) {
			return s.size() == 5;
		});
	


	save("source.cpp", "STL 7-1.txt");
}

