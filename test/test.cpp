#include "TestA.h"
#include "TestB.h"
#include "TestC.h"

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}