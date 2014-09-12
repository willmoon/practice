#include <iostream>
#include "string.h"

using namespace std;

int violentMatch(const char* target,const char* source)
{
	int tLength = strlen(target);
	int sLength = strlen(source);
	if (tLength > sLength)
	{
		return -1;
	}
	int i = 0;
	int k = 0;

	while(i < tLength && k < sLength)
	{
		if (target[i] == source[k])
		{
			i ++;
			k ++;
		}
		else
		{
			k = k -i + 1;
			i = 0;
		}
	}

	if (i == tLength)
	{
		return k - i;
	}
	
	return -1;	
}

int main(int argc, char const *argv[])
{
	char target[] = "Hello";
	char source[] = "JHeooHell0oWorld";
	int index = violentMatch(target,source);
	cout << index << endl;
	return 0;
}