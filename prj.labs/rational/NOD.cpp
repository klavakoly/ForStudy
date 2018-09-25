#include "NOD.h"
int NOD(int a, int b)
{
	while (b != 0)
	{
		if (a > b)
		{
			a %= b;
			if (!a)
			{
				return (b>0) ? b : (-b);
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
