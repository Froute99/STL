/*
 * 2022. 03. 24
 * STL Class
 * Week 4
 * 
 * ȣ�Ⱑ��Ÿ��(Callable type)
 * 1. �Լ������� - CODE���� �ش��Լ��� ���۹����� ����
 * 2. ����(lambda) - �����Ϸ��� ������ִ� class�̴�. (? class�� ȣ�Ⱑ�� Ÿ��?)
 * 3. ()�� �����ε��� class ()�� �Լ�ȣ�� ������
 * 4. ����Լ�(method) ������
 * 
 * ȣ�Ⱑ���� Ÿ���� ���Ѱ��̴�(���ٶ���)
 * --> ��� ȣ�Ⱑ��Ÿ���� ���ϵ� ������� ǥ���� �� �ִ� Ŭ����, function
 * 
 * �ڿ��� Ȯ���ϴ� ������ Ŭ���� STRING - �����̳�/�ݺ���/�˰���
 */



 // drmemory, makefile
 // ������ ����� class STRING �ۼ� ����(RAII)
 // ����: main()�� �������� ����ǰ� ����
 // ������ �� �ֵ��� special �Լ��� ��¸޽����� �߰��Ѵ�
 // ��ü�� �����ɶ����� ������ȣ�� �ش�



#include <iostream>
#include <functional>
#include "save.h"

class STRING {
public:
	STRING(const char* s) : num(strlen(s)), p{ new char[num] } {
		id = ++gid;
		memcpy(p, s, num);
		// �����޽��� on
		std::cout << "ctor [" << id << "] �ּ�: " << this << std::endl;
	}
	~STRING() {
		// �����޽��� on
		std::cout << "dtor [" << id << "] �ּ�: " << this << std::endl;
		delete[] p;
	}


	friend std::ostream& operator<<(std::ostream& os, const STRING& string);

private:
	int num;
	char* p;
	int id;
	static int gid;
};

std::ostream& operator<<(std::ostream& os, const STRING& string) {

	return os;
}

int STRING::gid{};


int main() {

	STRING a{ "2022 3 24" };
	STRING b{ "STL STRING �ۼ� ����" };
	
	//std::cout << a << std::endl;
	//std::cout << b << std::endl;

	save("source.cpp");
}

