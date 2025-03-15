#ifndef A_h__
#define A_h__

#ifdef UNIT_TESTING
#include <gtest/gtest_prod.h> 
#endif // UNIT_TESTING

class A
{
public:
	int GetPublicAnswer() const;

private:
	int GetPrivateAnswer() const;

#ifdef UNIT_TESTING
	FRIEND_TEST(TestA, PrivateMethod);
#endif // UNIT_TESTING
};

#endif // A_h__
