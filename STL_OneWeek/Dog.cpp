
#include <ostream>
#include "Dog.h"

//전역함수라서 밖에 선언
std::ostream& operator<<(std::ostream& os, const Dog& dog) {
	//os << dog.number;
	return os << dog.number;
}
