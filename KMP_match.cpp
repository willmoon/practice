#include <iostream>
#include <cstring>

using namespace std;

void getNext(const char *target, int next[])
{
    int i = -1;
    int k = 0;
    int tLength = strlen(target);
    next[0] = -1;

    while (k < tLength -1)
    {
        if (i == -1 || target[i] == target[k])
        {
            i ++;
            k ++;
            next[k] = i;
        }
        else
        {
            i = next[i];
        }
    }

    for (int i = 0; i < tLength; ++i)
    {
    	cout << next[i] << " ";
    }
    cout << endl;
}

int KMPMatch(const char *target, const char *source)
{
    int i = 0;
    int k = 0;
    int tLength = strlen(target);
    int sLength = strlen(source);
    int *next = new int[strlen(target)];
    getNext(target,next);

    while (i < tLength && k < sLength)
    {
        if (i == -1 || target[i] == source[k])
        {
            i ++;
            k ++;
        }
        else
        {
            i = next[i];
        }
    }

    if (i >= tLength)
    {
        return k - i;
    }

    return -1;
}

int main(int argc, char const *argv[])
{
	char target[] = "HelloHe";
	char source[] = "JHeooHelloWorld";
	
	int index = KMPMatch(target,source);

	cout << index << endl;
	return 0;
}