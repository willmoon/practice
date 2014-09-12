#include <iostream>

using namespace std;

void quickSort(int _nums[],int first,int last)
{
	if (first > last)
	{
		return;
	}

	int key = _nums[first];
	int i   = first;
	int k   = last;

	while(i < k)
	{
		while(i < k && _nums[k] > key)
			k --;
		_nums[i] = _nums[k];

		while(i < k && _nums[i] < key)
			i ++;
		_nums[k] = _nums[i];
	}

	_nums[i] = key;

	quickSort(_nums,first,i - 1);
	quickSort(_nums,k + 1,last);
}
 

 int main(int argc, char const *argv[])
 {
 	int nums[] = {12,2,1,333,-82,0,232,87,34,4,5667};
 	int length = sizeof(nums) / sizeof(*nums);

 	quickSort(nums,0,length - 1);

 	for (int i = 0; i < length; ++i)
 	{
 		cout << nums[i] << " ";
 	}
 	cout << endl;
 	return 0;
 }