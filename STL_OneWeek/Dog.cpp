
#include <ostream>
#include "Dog.h"

//�����Լ��� �ۿ� ����
std::ostream& operator<<(std::ostream& os, const Dog& dog) {
	//os << dog.number;
	return os << dog.number;
}
