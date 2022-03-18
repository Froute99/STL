/**************************************************************************************
 *	File Name		: source.cpp
 *	Date			: 2022 03 02
 *	Author			: JH Kim
 *	Instruction		: main function
 **************************************************************************************/


// c++ paradigm
// object oriented, procedural, generic, meta, functional

#include <iostream>
#include <random>
#include <fstream>
#include "save.h"

// template - 자료형과 관계없는 함수 또는 클래스를 작성(핵심 키워드)
//			- generic programming

// [문제] 엔진과 분포를 사용하여 int 1000개를
// "int 천개.txt" 파일에 저장하라
// 다음시간 - 파일저장 다시
// 숙제 - 파일입출력 알아보기

std::random_device rd;
std::default_random_engine gen(rd());


int main() {

	std::uniform_int_distribution<int> dis(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
	// 시험문제로 보통 normal distribution 출제

	std::ofstream out{ "int 천개.txt" };

	for (int i = 0; i < 1000; ++i) {
		out << dis(gen) << std::endl;
	}


	Save fileSave;
	fileSave.save("source.cpp");
}

