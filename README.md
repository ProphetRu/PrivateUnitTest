# Private Unit Test
PrivateUnitTest - The project demonstrates unit-testing of private methods.

## Dependencies
* [googletest](https://github.com/google/googletest)

## How to use
### In project
For the class under test, add an include only for the test mode:
```cpp
#ifdef UNIT_TESTING
#include <gtest/gtest_prod.h> 
#endif // UNIT_TESTING
```

Inside the class under test, add a macro for test mode only:
```cpp
#ifdef UNIT_TESTING
	FRIEND_TEST(test_case_name, test_name);
#endif // UNIT_TESTING
```

### In test
Include the testing class with test macro:
```cpp
#define UNIT_TESTING
#include "TestClass.h"
#include "TestClass.cpp" // the linking error without this #include
#undef UNIT_TESTING
```

Add unit-test:
```cpp
TEST(test_case_name, test_name)
{
    // here you can access to private methods of the class under test
}
```


## Build local Windows/Linux
```shell
vcpkg install gtest
vcpkg integrate install

cd PrivateUnitTest
mkdir build && cd build

cmake .. -DCMAKE_TOOLCHAIN_FILE="path/to/vcpkg/scripts/buildsystems/vcpkg.cmake"

cmake --build . --config Release
```

## Testing
```shell
ctest
```
