
#include <iostream>

int ArrSum(int* PtrArr, int Cnt);
int ArrAvg(int* PtrArr, int Cnt);

int main()
{
	int Arr[5] = {};
	int Cnt = sizeof(Arr) / sizeof(int);

	for (int i = 0; i < Cnt; i++)
	{
		std::cin >> Arr[i];
	}

	std::cout << "Sum : " << ArrSum(Arr, Cnt) << ", Avg : " << ArrAvg(Arr, Cnt);

	return 0;
}

int ArrSum(int* PtrArr, int Cnt)
{
	int Result = 0;
	for (int i = 0; i < Cnt; i++)
	{
		Result += *(PtrArr + i);
	}

	return Result;
}

int ArrAvg(int* PtrArr, int Cnt)
{
	return ArrSum(PtrArr, Cnt) / Cnt;
}