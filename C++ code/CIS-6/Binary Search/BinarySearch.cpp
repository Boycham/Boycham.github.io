// Name: Boyuan Pang
// Course: CIS 006 Intro to programming 
// CRN: 30036 
// Date: 7/16/2024
// Assignment: MergeSort

#include "BinarySearch.h"

// merges array together in ascending order
void merge(int arr[], int left, int mid, int right)
{
	int leftsize = mid - left + 1;
	int rightsize = right - mid;

	int* leftarr = new int[leftsize];
	int* rightarr = new int[rightsize];
    
    // copies array data into temperary arrays
	for (int i = 0; i < leftsize; i++)
		leftarr[i] = arr[i + left];
		
    // copies array data into temperary arrays
	for (int i = 0; i < rightsize; i++)
		rightarr[i] = arr[i + mid + 1];

	int a1 = 0, a2 = 0, arrIndex = left;
    
    // the smaller value is put into the array
	while (a1 < leftsize && a2 < rightsize)
	{
		int lef = leftarr[a1], rig = rightarr[a2];

		if (lef <= rig)
		{
			arr[arrIndex] = lef;
			a1++;
		}
		else
		{
			arr[arrIndex] = rig;
			a2++;
		}

		arrIndex++;
	}
    
    // any leftover values will get added
	while (a1 < leftsize)
	{
		int lefv = leftarr[a1];
		arr[arrIndex] = lefv;
		a1++;
		arrIndex++;
	}
    
    // any leftover values will get added
	while (a2 < rightsize)
	{
		int rigv = rightarr[a2];
		arr[arrIndex] = rigv;
		a2++;
		arrIndex++;
	}
    
	delete[] leftarr;
	delete[] rightarr;
}

// splits the array into sections for merge to work with
void mergeSort(int arr[], int begin, int end)
{
    
    // base case, once the whole list has been split into sections
	if (begin >= end)
		return;

	int mid = begin + (end - begin) / 2;
	mergeSort(arr, begin, mid);
	mergeSort(arr, mid + 1, end);
	merge(arr, begin, mid, end);
}

// uses binary search algorithm to find a value
int recursiveBinarySearch(int arr[], int start_index, int end_index, int target_value, int cnt)
{
    // if not found, returns -1 and the amount of recursions
	if(start_index > end_index)
		return -1;

	int mid = (start_index + end_index) / 2;
    
    // returns amount of recursions
	if (arr[mid] == target_value)
		return cnt + 1;
		
    //the range of the search is halved
	if (arr[mid] > target_value)
		return recursiveBinarySearch(arr, start_index, mid - 1, target_value, cnt + 1);
	else
		return recursiveBinarySearch(arr, mid + 1, end_index, target_value, cnt + 1);
}