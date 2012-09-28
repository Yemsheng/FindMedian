#include<iostream>

using namespace std;

float findMedian(int *firstArray, int firstSize, int *secondArray, int secondSize);

int main()
{
	//int firstArray[] = {1};
	//int secondArray[] = {2};
	//int firstArray[] = {1,3,5,7};
	//int secondArray[] = {2,4,6,8};
	//int firstArray[] = {0,1,2,3,4,5,6,7,8};
	//int secondArray[] = {3};
	int firstArray[] = {1,3,5,7};
	int secondArray[] = {2,4,6,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24};

	float median = findMedian(firstArray,sizeof(firstArray)/sizeof(int), secondArray, sizeof(secondArray)/sizeof(int));
	cout<<"median = "<<median<<endl;

	return 0;
}

float findMedian(int *firstArray, int firstSize, int *secondArray, int secondSize)
{
	if(firstArray==NULL||secondArray==NULL)
	{
		return 0;
	}
	if(firstSize<1||secondSize<1)
	{
		return 0;
	}

	int allSize = firstSize + secondSize;
	int allStep = (allSize + 1) / 2;
	bool isEven = false;
	if(allSize%2==0)
	{
		allStep++;
		isEven = true;
	}
	else
	{
		isEven = false;
	}
	
	int first = 0;
	int second = 0;
	int medianValue = 0;
	int lastMedianValue = medianValue;
	
	int i = 0;
	while(i<allStep)
	{
		if((first<firstSize)&&(second<secondSize))
		{
			if(firstArray[first]<=secondArray[second])
			{
				lastMedianValue = medianValue;
				medianValue = firstArray[first];
				first++;
			}
			else
			{
				lastMedianValue = medianValue;
				medianValue = secondArray[second];
				second++;
			}
		}
		else if((first<firstSize)&&(second>=secondSize))
		{
			lastMedianValue = medianValue;
			medianValue = firstArray[first];
			first++;
		}
		else if((first>=firstSize)&&(second<secondSize))
		{
			lastMedianValue = medianValue;
			medianValue = secondArray[second];
			second++;
		}
		else
		{
			break;
		}
		i++;
	}

	if(isEven)
	{
		float temp = lastMedianValue + medianValue;
		return temp/2;
	}
	return medianValue;
}