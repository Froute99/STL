/**************************************************************************************
 *	File Name		: save.cpp
 *	Date			: 2022 03 03
 *	Author			: JH Kim
 *	Instruction		: Save class which helps save files
 **************************************************************************************/

#include <fstream>
#include <filesystem>
#include <chrono>
#include <vector>
#include <algorithm>
#include "save.h"

void save(std::string_view fileName) {
	// ���� ������ ����
	std::ifstream in{ fileName.data() };

	// �� ���ϵ� ����
	std::ofstream out{ "2022�� 1�б� STL 1�� ��������.txt", std::ios::app };

	out << "\n\n";

	// ������ ������ �̸��� ���Ͽ� ���
	out << "�����̸�: " << fileName << "\n";

	// ������ ������ ũ�⸦ ���(C++17 ���)
	out << "����ũ��: " << std::filesystem::file_size(fileName) << "\n";

	// ���� ��¥&�ð� ���
	auto time = floor<std::chrono::seconds>(std::chrono::system_clock::now());
	out << std::chrono::zoned_time("Asia/Seoul", time) << "\n";
	out << "\n";

	// ���� ������ ������ �о� �� ���Ͽ� ���ٿ� ����
	// 1. ������ ������ ����(�����̳�)�� �о�´�
	std::vector<char> v{ std::istreambuf_iterator<char>(in), {} };	// whitespace ���� ����

	// 2. �˰����� ����Ͽ� ���Ϳ� �ִ� ������ ���Ͽ� �����Ѵ�
	copy(v.begin(), v.end(), std::ostream_iterator<char>{out});

}
