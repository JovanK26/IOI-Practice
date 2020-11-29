#include "cycle.h"

void escape(int n)
{
	int x=(n+1)/2;
	bool check=jump(0);
	while(x>1)
    {
        if(check)
        {
            check=jump(x);
        }
        else
        {
            check=jump(n-x);
        }
        x=(x+1)/2;
    }
    if(jump(0))jump(1);
    else
    {
        jump(n-1);
    }
    if(!jump(0))jump(n-1);
}

