#include <iostream>
#include <cassert>
#include "Time.h"

using namespace std;

int main()
{
	//assert();
	Time a(0,0,1);
	
	a.DiffTime(2, 5, 6);
	a.PrintTime();
}