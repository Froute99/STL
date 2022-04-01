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
	// 읽을 파일을 연다
	std::ifstream in{ toRead.data() };

	// 쓸 파일도 연다
	std::ofstream out{ toWrite, std::ios::app };

	out << "\n\n";

	// 저장할 파일의 이름을 파일에 출력
	out << "파일이름: " << toRead << "\n";

	// 저장할 파일의 크기를 출력(C++17 기능)
	out << "파일크기: " << std::filesystem::file_size(toRead) << "\n";

	// 현재 날짜&시간 출력
	auto time = floor<std::chrono::seconds>(std::chrono::system_clock::now());
	out << std::chrono::zoned_time("Asia/Seoul", time) << "\n";
	out << "\n";

	// 읽을 파일의 정보를 읽어 쓸 파일에 덧붙여 쓴다
	// 1. 파일의 내용을 벡터(컨테이너)로 읽어온다
	std::vector<char> v{ std::istreambuf_iterator<char>(in), {} };	// whitespace 까지 포함

	// 2. 알고리즘을 사용하여 벡터에 있는 내용을 파일에 복사한다
	copy(v.begin(), v.end(), std::ostream_iterator<char>{out});

	out << "=======================================================\n";

}
