#pragma once

#include <gtest/gtest.h>

#define UNIT_TESTING
#include "B.h"
#include "B.cpp" // the linking error without this #include
#undef UNIT_TESTING

TEST(TestB, PrivateMethod)
{
    B b;
    ASSERT_EQ(b.GetPrivateAnswer(), 2);
}

TEST(TestB, PublicMethod)
{
    B b;
    ASSERT_EQ(b.GetPublicAnswer(), 20);
}
