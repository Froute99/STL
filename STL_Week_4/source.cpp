/*
 * 2022. 03. 30
 * STL Class
 * Week 5
 * 
 * STRING 클래스 파일 분리
 */



 // drmemory, makefile
 // 앞으로 사용할 class STRING 작성 시작(RAII)
 // 문제: main()이 문제없이 실행되게 하자
 // 관찰할 수 있도록 special 함수에 출력메시지를 추가한다
 // 객체가 생성될때마다 고유번호를 준다



#include <iostream>
#include <array>
#include <algorithm>
#include "save.h"

#include "STRING.h"
extern bool printMsg;

int main() {
	//printMsg = true;

	std::array<STRING, 3> a{ "2022", "3", "30" };
	
	// 길이 오름차순으로 a를 정렬한 후 출력

	sort(a.begin(), a.end(), [](STRING& a, STRING& b) {
		return a.getNumber() < b.getNumber();
		});

	for (const auto& x : a) {
		std::cout << x;
	}
	
	save("source.cpp");
}

