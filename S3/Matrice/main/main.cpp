
#include <stdio.h>

#include "Canvas.h"

int main()
{
	Canvas x(30, 30);
	
	x.DrawCircle(15, 15, 12, '*');
	x.Print();
	x.FillCircle(15, 15, 12, '*');
	x.Print();
	 
	x.Clear();
	x.DrawRect(5, 5, 25, 20, '*');
	x.Print();
	x.FillRect(5, 5, 25, 20, '*');
	x.Print();
	
	x.Clear();
	x.DrawRect(5, 5, 25, 25, '*');
	x.DrawLine(5, 5, 25, 25, '*');
	x.Print();
	return 0;
}
