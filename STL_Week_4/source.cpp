/*
 * 2022. 04. 13
 * STL Class
 *
 * �߰����� Ȯ�� - 4.20 ��
 * 
 * 
 *  * 1. Sequence container
 *		array			- �����ϰ� ũ�Ⱑ ����, [] ��ü
 *		vector			- dynamic size array, O(1) - random access
 *						- �߰��� insert�ϴ� ������ �񰡸� �˾ƺô�.
 *		deque		
 *		forward_list
 *		list
 */

 // ���� std::vector<Player>

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
	// vector���� deque�� �� ���� ���Ҹ� �����Ѵٰ�?
	// deque �� vector ���� ���� ����


	// [����] "source.cpp"�� �ܾ deque�� �����϶�
	// �������� �����϶�
	// ����϶�




	save("source.cpp", "STL 6-2.txt");
}

