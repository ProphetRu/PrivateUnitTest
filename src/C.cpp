#include "C.h"

int C::GetUniverseAnswer() const
{
	return m_A.GetPublicAnswer() + m_B.GetPublicAnswer();
}
