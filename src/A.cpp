#include "A.h"

int A::GetPublicAnswer() const
{
	return 21 + GetPrivateAnswer();
}

int A::GetPrivateAnswer() const
{
	return 1;
}
