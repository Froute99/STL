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
 // ������ ����� class STRING �ۼ� ����(RAII)
 // ����: main()�� �������� ����ǰ� ����
 // ������ �� �ֵ��� special �Լ��� ��¸޽����� �߰��Ѵ�
 // ��ü�� �����ɶ����� ������ȣ�� �ش�

// using STRING::value_type = char;


// ���� fileIO ���� fstream

/*
���� �ܾ �Է¹޾�
�������� ������ ��
ȭ�鿡 ���
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
	
	sort(v.begin(), v.end());			// 5�� 2 ��������/��������

	for (auto x : v) {
		std::cout << x << ' ';
	}

	save("source.cpp");
}

