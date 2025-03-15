#ifndef C_h__
#define C_h__

#include "A.h"
#include "B.h"

class C
{
public:
	int GetUniverseAnswer() const;

private:
	A m_A;
	B m_B;
};

#endif // C_h__
