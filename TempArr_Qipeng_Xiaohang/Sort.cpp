/*
Qipeng Liao and Xiaohang Yin
Assignemnet#4
02/17/2019
Sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
Qipeng Liao did the Insertion Sort  function and Quick Sort function
Xiaohang Yin did the Merge Sort function and main function.
*/
#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;

class Sort
{
private:

public:

	void swap(int * a, int* b)
	{
		int t = *a;
		*a = *b;
		*b = t;
	}
	/**
	This funtion is meant to take the last element as the pivot, place the pivot element
	in its correct posision in a sorted array then place all elements smaller than pivot to the left
	and the greater to the its right.
	**/
	int partition(int arr[], int low, int high)
	{
		int pivot = arr[high];		//pivot
		int i = (low - 1);			//index of smaller element

		for (int j = low; j <= high - 1; j++)
		{
			if (arr[j] <= pivot)
			{
				i++;
				swap(&arr[i], &arr[j]);
			}
		}
		swap(&arr[i + 1], &arr[high]);
		return (i + 1);
	}
	//Performing the Quick Sort now
	//arr[] is the array to be sorted
	//high is the starting index
	//low is the ending index
	void quickSort(int arr[], int low, int high)
	{
		if (low < high)
		{
			/*
			pi here is the partitioning index and arr[p] is now in the right place.
			*/
			int pi = partition(arr, low, high);
			quickSort(arr, low, pi - 1);
			quickSort(arr, pi + 1, high);
		}
	}
	void insertionSort(int arr[], int n)
	{
		int i, key, j;
		for (i = 1; i < n; i++)
		{
			key = arr[i];
			j = i - 1;
			while (j >= 0 && arr[j] > key)
			{
				arr[j + 1] = arr[j];
				j = j - 1;
			}
			arr[j + 1] = key;
		}
	}
	/**

	int quickSort()
	{
		int arr[32];
		int n, i, j,temp;

		cout << "Enter total number of items to read: ";
		cin >> n;
		//check if they are bound
		if (n<0 ||n>32)
		{
			cout << "Input a valid range!!" << endl;
			return -1;
		}
		//read n elements if they are bound
		for ( i = 0; i < n; i++)
		{
			cout << "Enter element [" << i + 1 << "]";
			cin >> arr[i];
			//print input elements
			cout << "Unsorted Array elements: " << endl;
			for ( i = 0; i < n; i++)
			{
				cout << arr[i] << "\t";
				cout << endl;
			}
			//sorting in Descending order
			for ( i = 0; i < n; i++)
			{
				for ( j = 0; j < n; j++)
				{
					if (arr[i]<arr[j])
					{
						temp = arr[i];
						arr[i] = arr[j];
						arr[j] = temp;
					}
				}
			}
			//print sorted elements
			cout << "Sorted Array elements in Descending order: " << endl;
			for ( i = 0; i < n; i++)
			{
				cout << arr[i] << "\t";
				cout << endl;
				return 0;
			}
		}
	}
	**/
	void merge(int arr[], int l, int m, int r)
	{
		int i, j, k;
		int n1 = m - l + 1;
		int n11 = n1;
		int n2 = r - m;
		//create temporary arrays
		int* L = new int[n1];
		int* R = new int[n2];

		//copy data into the temporary arrays
		for (i = 0; i < n1; i++)
		{
			L[i] = arr[l + i];
			for (j = 0; j < n2; j++)
			{
				R[j] = arr[m + 1 + j];
			}
		}
		//merge the temporary arrays back into arr[l...r]
		i = 0; //initial index of firs
		j = 0;
		k = l;
		while (i < n1&&j < n2)
		{
			if (L[i] <= R[j])
			{
				arr[k] = L[i];
				i++;
			}
			else
			{
				arr[k] = R[j];
				j++;
			}
			k++;
		}
		//copy remaining elements of L[], if they are there
		while (i < n1)
		{
			arr[k] = L[i];
			i++;
			k++;
		}
		//copy remaining elements of R[], if they are there
		while (j < n2)
		{
			arr[k] = R[j];
			j++;
			k++;
		}
	}
	void mergeSort(int arr[], int l, int r)
	{
		if (l < r)
		{
			int m = l + (r - l) / 2;
			mergeSort(arr, l, m);
			mergeSort(arr, m + 1, r);
			merge(arr, l, m, r);
		}
	}
	void printArray(int A[], int size)
	{
		int i;
		for (i = size - 1; i >= 0; i--)
		{
			cout << A[i];
			cout << endl;
		}
	}
};

int main()
{
	Sort obj;
	const int SORT_MAX_SIZE = 32;
	int arr[SORT_MAX_SIZE];
	int g;
	cout << "Enter the size of int array: \n";
	cin >> g;

	if (g < 0 || g>32)
	{
		cout << "Input a valid range!!" << endl;

		cin.ignore();
		cin.ignore();
		return -1;
	}
	else
	{
		cout << "Enter the values to the array: \n";
		for (int i = 0; i < g; i++)
		{
			cin >> arr[i];
		}
	}

	int n = g;
	cout << "Given an array is: " << endl;
	obj.printArray(arr, n);
	obj.mergeSort(arr, 0, n - 1);
	cout << "Merge Sorted Array is: " << endl;
	obj.printArray(arr, n);
	obj.insertionSort(arr, n);
	cout << "\n Insertion Sorted Array is: " << endl;
	obj.printArray(arr, n);
	obj.quickSort(arr, 0, n - 1);
	cout << "\n Quick Sorted Array is: " << endl;
	obj.printArray(arr, n);
	cin.ignore();
	cin.ignore();
	return 0;
}