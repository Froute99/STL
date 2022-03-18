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

// template - �ڷ����� ������� �Լ� �Ǵ� Ŭ������ �ۼ�(�ٽ� Ű����)
//			- generic programming

// [����] ������ ������ ����Ͽ� int 1000����
// "int õ��.txt" ���Ͽ� �����϶�
// �����ð� - �������� �ٽ�
// ���� - ��������� �˾ƺ���

std::random_device rd;
std::default_random_engine gen(rd());


int main() {

	std::uniform_int_distribution<int> dis(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
	// ���蹮���� ���� normal distribution ����

	std::ofstream out{ "int õ��.txt" };

	for (int i = 0; i < 1000; ++i) {
		out << dis(gen) << std::endl;
	}


	Save fileSave;
	fileSave.save("source.cpp");
}

