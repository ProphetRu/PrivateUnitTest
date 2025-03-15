cmake_minimum_required(VERSION 3.10)

#--------------------------------------------------------------------------------------------------
# variables
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/test)
set(PROJECT_NAME PrivateUnitTest)
set(TEST_NAME UnitTest)


#--------------------------------------------------------------------------------------------------
# project
project(${PROJECT_NAME})

if (MSVC)
	# enable VS-Solution filters support
	set_property(GLOBAL PROPERTY USE_FOLDERS ON)
endif (MSVC)


#--------------------------------------------------------------------------------------------------
# builds
add_executable(${PROJECT_NAME}
	${SRC_DIR}/A.cpp
	${SRC_DIR}/B.cpp
	${SRC_DIR}/C.cpp
	${SRC_DIR}/main.cpp
)

add_executable(${TEST_NAME} 
	${TEST_DIR}/test.cpp
)

# properties
set_target_properties(${PROJECT_NAME} ${TEST_NAME} 
	PROPERTIES
	CXX_STANDARD 23
	CXX_STANDARD_REQUIRED ON
)


#--------------------------------------------------------------------------------------------------
# gtest
#
find_package(GTest REQUIRED)

# add src to the include directories for the test target
target_include_directories(${TEST_NAME} 
	PRIVATE
	${SRC_DIR}
	${GTEST_INCLUDE_DIRS}
	${GTEST_LIBRARY} 
	${GTEST_INCLUDE_DIR}
	${GTEST_MAIN_LIBRARY}
)

# link test target against gtest libraries
target_link_libraries(${TEST_NAME} 
	PRIVATE
	GTest::gtest 
	GTest::gtest_main 
)


#--------------------------------------------------------------------------------------------------
# compiler settings
if (MSVC)
	set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
	
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MD")
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MDd")

	add_compile_options("/std:c++latest")
	
	target_compile_options(${PROJECT_NAME} PRIVATE
		/W4
	)
	target_compile_options(${TEST_NAME} PRIVATE
		/W4
	)
else ()
	target_compile_options(${PROJECT_NAME} PRIVATE
		-std=c++23 -Wall -Wextra -pedantic -Werror
	)
	target_compile_options(${TEST_NAME} PRIVATE
		-std=c++23 -Wall -Wextra -pedantic -Werror
	)
endif (MSVC)


#--------------------------------------------------------------------------------------------------
# testing
enable_testing()
include(GoogleTest)
gtest_discover_tests(${TEST_NAME})
