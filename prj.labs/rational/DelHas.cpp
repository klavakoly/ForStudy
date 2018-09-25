#include "DelHas.h"

void delHas(int& a, int& b)
{
	int nod = NOD(a, b);
	if (nod)
	{
		a /= nod;
		b /= nod;
	}
};
