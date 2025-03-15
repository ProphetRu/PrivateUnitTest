#ifndef B_h__
#define B_h__

#ifdef UNIT_TESTING
#include <gtest/gtest_prod.h> 
#endif // UNIT_TESTING

class B
{
public:
	int GetPublicAnswer() const;

private:
	int GetPrivateAnswer() const;

#ifdef UNIT_TESTING
	FRIEND_TEST(TestB, PrivateMethod);
#endif // UNIT_TESTING
};

#endif // B_h__
