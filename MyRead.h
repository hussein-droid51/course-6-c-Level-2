#pragma once
#include <iostream>
using namespace std;

namespace MyRead
{
	int ReadNumber()
	{
		int Number =0;
		do
		{

			printf("Please Enter An Integer Number: \n");
			cin >> Number;
			
		} while (Number < 0);
		return Number;
	}
}