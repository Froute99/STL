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
 *		list
 */

 // 과제 std::vector<Player>

#include <iostream>
#include <vector>
#include <deque>
#include "save.h"
#include "STRING.h"

extern bool isMessageToggle;

class Test {
	char c[1024];
public:
	void Show() const {
		std::cout << this << std::endl;
	}
};

int main() {
	// vector보다 deque가 더 많은 원소를 저장한다고?
	// deque 가 vector 보다 많이 저장


	// [문제] "source.cpp"의 단어를 deque에 저장하라
	// 오름차순 정렬하라
	// 출력하라




	save("source.cpp", "STL 6-2.txt");
}

