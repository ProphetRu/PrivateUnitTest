#include <print>
#include "C.h"

int main() noexcept
{
	C c{};

	std::println("The answer is: {}", c.GetUniverseAnswer());
	return 0;
}