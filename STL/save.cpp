/**************************************************************************************
 *	File Name		: save.cpp
 *	Date			: 2022 03 03
 *	Author			: JH Kim
 *	Instruction		: Save function which helps save files
 **************************************************************************************/

#include <fstream>
#include <filesystem>
#include <chrono>
#include <vector>
#include <algorithm>
#include <string_view>
#include "save.h"

void save(std::string_view toRead, std::string toWrite) {
	// ���� ������ ����
	std::ifstream in{ toRead.data() };

	// �� ���ϵ� ����
	std::ofstream out{ toWrite, std::ios::app };

	out << "\n\n";

	// ������ ������ �̸��� ���Ͽ� ���
	out << "�����̸�: " << toRead << "\n";

	// ������ ������ ũ�⸦ ���(C++17 ���)
	out << "����ũ��: " << std::filesystem::file_size(toRead) << "\n";

	// ���� ��¥&�ð� ���
	auto time = floor<std::chrono::seconds>(std::chrono::system_clock::now());
	out << std::chrono::zoned_time("Asia/Seoul", time) << "\n";
	out << "\n";

	// ���� ������ ������ �о� �� ���Ͽ� ���ٿ� ����
	// 1. ������ ������ ����(�����̳�)�� �о�´�
	std::vector<char> v{ std::istreambuf_iterator<char>(in), {} };	// whitespace ���� ����

	// 2. �˰����� ����Ͽ� ���Ϳ� �ִ� ������ ���Ͽ� �����Ѵ�
	copy(v.begin(), v.end(), std::ostream_iterator<char>{out});

	out << "=======================================================\n";

}
