#include "NOD.h"
#include <math.h>
int NOD(int a, int b)
{
	while (b != 0)//пока b не 0
	{
		if (abs(a) > abs(b))
		{
			a %= b;
			if (!a)
			{
				return b;
			}
		}
		else
		{
			b %= a;
			if (!b)
			{
				return (a>0) ? a : (-a);
			}
		}
	}
};
