#include <iostream>
using namespace std;

void sort(int _nums[], int first, int mid, int last, int temp[])
{
    if (first > mid)
    {
        return;
    }

    int i = first;
    int k = mid;
    int m = mid + 1;
    int n = last;
    int s = 0;

    while (i <= k && m <= n)
    {
        if (_nums[i] < _nums[m])
        {
            temp[s ++] = _nums[i ++];
        }
        else
        {
            temp[s ++] = _nums[m ++];
        }
    }

    while (i <= k)
    {
        temp[s ++] = _nums[i ++];
    }

    while (m <= n)
    {
        temp[s ++] = _nums[m ++];
    }

    for (int i = 0; i < s; ++i)
    {
        _nums[first + i] = temp[i];
    }
}

void merge(int _nums[],int first,int last,int temp[])
{
	if (first >= last)
	{
		return;
	}

	int i = first;
	int k = last;
	int mid = (first + last) / 2;

	merge(_nums,i,mid,temp);
	merge(_nums,mid + 1,last,temp);
	sort(_nums,i,mid,k,temp);
}

int main(int argc, char const *argv[])
{
	int nums[] = {12,2,1,333,-82,0,232,87,34,4,5667,34,333};
	int length = sizeof(nums) / sizeof(*nums);
	int *temp  = new int[length];

	merge(nums,0,length - 1,temp);

	for (int i = 0; i < length; ++i)
	{
		cout << nums[i] << " ";
	}

	cout << endl;

	delete[] temp;

	return 0;
}