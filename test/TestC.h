#pragma once

#include <gtest/gtest.h>

#define UNIT_TESTING
#include "C.h"
#include "C.cpp" // the linking error without this #include
#undef UNIT_TESTING

TEST(TestC, IntegrationTest)
{
    C c;
    ASSERT_EQ(c.GetUniverseAnswer(), 42);
}
