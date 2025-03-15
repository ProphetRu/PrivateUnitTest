#include <iostream>
#include "C.h"

int main() noexcept
{
	C c{};

	std::cout << "The answer is: " << c.GetUniverseAnswer());
	return 0;
}