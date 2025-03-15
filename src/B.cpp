#include "B.h"

int B::GetPublicAnswer() const
{
	return 18 + GetPrivateAnswer();
}

int B::GetPrivateAnswer() const
{
	return 2;
}
