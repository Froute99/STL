/*
 * 2022. 03. 30
 * STL Class
 * Week 5
 * 
 * 1. Sequence container
 *		array				- replace []
 *		vector
 *		deque
 *		forward_list
 *		list
 */


 // drmemory, makefile
 // 앞으로 사용할 class STRING 작성 시작(RAII)
 // 문제: main()이 문제없이 실행되게 하자
 // 관찰할 수 있도록 special 함수에 출력메시지를 추가한다
 // 객체가 생성될때마다 고유번호를 준다

// using STRING::value_type = char;


// 시험 fileIO 나옴 fstream

/*
문제 단어를 입력받아
오름차순 정렬한 후
화면에 출력
*/




#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "save.h"

#include "STRING.h"
extern bool printMsg;

int main() {

	std::vector<std::string> v;

	std::string in;
	while (std::cin >> in) {
		v.push_back(in);
	}
	
	sort(v.begin(), v.end());			// 5주 2 과제설명/내림차순

	for (auto x : v) {
		std::cout << x << ' ';
	}

	save("source.cpp");
}

