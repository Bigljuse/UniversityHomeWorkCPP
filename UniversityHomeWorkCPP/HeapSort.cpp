#include <iostream>
#include <cstdlib> 
#include <vector>

using namespace std;

int GetParentId(int childId) {
	int parentId = 0;

	if (childId <= 2)
		return parentId;

	if (childId % 2 == 0)
		parentId = (childId - 2) / 2;
	else
		parentId = (childId - 1) / 2;

	return parentId;
}

int GetLeftChildId(int parentId, int arraySize)
{
	int leftChildId = 0;

	arraySize = arraySize - 1;

	if (parentId <= 0 && arraySize > 0)
		return 1;

	leftChildId = parentId * 2 + 1;

	if (leftChildId <= arraySize)
		return leftChildId;

	return -1;
}

int GetRightChildId(int parentId, int arraySize)
{
	int rightChildId = 0;

	arraySize = arraySize - 1;

	if (parentId <= 0 && arraySize > 1)
		return 2;

	rightChildId = parentId * 2 + 2;

	if (rightChildId <= arraySize)
		return rightChildId;

	return -1;
}

int GetChildsCount(int parentId, int arraySize)
{
	int childsCount = 0;
	int leftChildId = parentId * 2 + 1;
	int rightChildId = leftChildId + 1;

	if (rightChildId <= (arraySize - 1))
		return 2;
	else if (leftChildId == (arraySize - 1))
		return 1;

	return 0;
}

vector<int> sortParentsToMax(vector<int> unSortedArray, int parentId, int arraySize)
{
	int buffer = unSortedArray[parentId];
	int leftChildId = GetLeftChildId(parentId, arraySize);
	int rightChildId = GetRightChildId(parentId, arraySize);

	if (rightChildId == -1 || unSortedArray[leftChildId] > unSortedArray[rightChildId])
	{
		if (unSortedArray[leftChildId] < buffer)
			return unSortedArray;

		unSortedArray[parentId] = unSortedArray[leftChildId];
		unSortedArray[leftChildId] = buffer;
		parentId = leftChildId;

		if (GetChildsCount(parentId, arraySize) > 0)
			unSortedArray = sortParentsToMax(unSortedArray, parentId, arraySize);
	}
	else
	{
		if (unSortedArray[rightChildId] < buffer)
			return unSortedArray;

		unSortedArray[parentId] = unSortedArray[rightChildId];
		unSortedArray[rightChildId] = buffer;
		parentId = rightChildId;

		if (GetChildsCount(parentId, arraySize) > 0)
			unSortedArray = sortParentsToMax(unSortedArray, parentId, arraySize);
	}

	return unSortedArray;
}

vector<int> Swap(vector<int> unSortedArray, int arraySize)
{
	int buffer = 0;

	buffer = unSortedArray[0];
	unSortedArray[0] = unSortedArray[arraySize - 1];
	unSortedArray[arraySize - 1] = buffer;

	return unSortedArray;
}

vector<int> Sort(vector<int> unSortedArray)
{
	int arraySize = unSortedArray.size();
	int parentId = GetParentId(arraySize - 1);
	vector<int> sortedArray = unSortedArray;

	while (arraySize > 1)
	{
		while (parentId >= 0) {

			sortedArray = sortParentsToMax(sortedArray, parentId, arraySize);
			parentId -= 1;
		}

		sortedArray = Swap(sortedArray, arraySize);

		arraySize -= 1;
		parentId = 0;
	}
	return sortedArray;
}
