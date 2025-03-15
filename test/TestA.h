#pragma once

#include <gtest/gtest.h>

#define UNIT_TESTING
#include "A.h"
#include "A.cpp" // the linking error without this #include
#undef UNIT_TESTING

TEST(TestA, PrivateMethod)
{
    A a;
    ASSERT_EQ(a.GetPrivateAnswer(), 1);
}

TEST(TestA, PublicMethod)
{
    A a;
    ASSERT_EQ(a.GetPublicAnswer(), 22);
}
