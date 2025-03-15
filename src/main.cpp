#include <iostream>
#include "C.h"

int main() noexcept
{
	C c{};

	std::cout << "The answer is: " << c.GetUniverseAnswer() << std::endl;
	return 0;
}