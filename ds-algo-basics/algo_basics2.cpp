/* 
Sort - Bubble, Insertion, Selection, 
	 - Merge, Heap, Quick, 
	 - Counting, Radix, Bucket

 Binary search
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> vec = {2, 6, 3, 8, 1, 11, 44, 33, 67, 9};
vector<int> Arr = {2, 6, 3, 8, 1, 11, 44, 33, 67, 9};

void display(vector<int> v) {
	printf("Array: ");
	for (int i=0; i<v.size(); i++)
		printf("%d ", v[i]);
	printf("\n");
}

void bubble_sort(vector<int> &arr) {
	int i,j,k;
	for (i=1; i<arr.size(); i++) {
		for (j=i; j>0; j--) {
			if (arr[j] < arr[j-1]) {
				// swap
				k = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = k;
			}
		}
	}
}

void selection_sort(vector<int> &arr) {
	int i,j, k, minval, indx;

	for (i=0; i<arr.size(); i++) {
		indx = i;
		minval = arr[i];
		for (j=i+1; j<<arr.size(); j++) {
			if (arr[j] < minval) {
				indx = j;
				minval = arr[j];
			}
		}
		// swap
		k = arr[i];
		arr[i] = arr[indx];
		arr[indx] = k;
	}
}

void merge(int st, int mid, int end) {
	//merge two sorted arrays
	vector<int> subVec1(vec.begin()+st, vec.begin()+mid+1);
	vector<int> subVec2(vec.begin()+mid+1, vec.begin()+end+1);

	int i, j, k;
	i = st;
	j = 0;
	k = 0;

	for (; ((j<subVec1.size()) && (k<subVec2.size())) ; i++) {
		if (subVec1[j] < subVec2[k]) {
			vec[i] = subVec1[j];
			j++;
		}
		else {
			vec[i] = subVec2[k];
			k++;
		}
	}
	
	if (j==subVec1.size()) { // add remaining elements of suubvec2
		while(k != subVec2.size()) {
			vec[i] = subVec2[k];
			i++; k++;
		}
			
	}
	else {
		while(j != subVec1.size()) {
			vec[i] = subVec1[j];
			i++; j++;
		}
	}

}

void merge_sort(int start, int end) {
	if (start == end)
		return;

	int middle = start + (end-start)/2;
	merge_sort(start, middle);
	merge_sort(middle+1, end);

	merge(start, middle, end);
}

int partition(int p, int r) {
	int pivotIndex, pivotKey, i, j, s;
	pivotIndex = r;
	pivotKey = Arr[r];
	i = p-1;

	for (j=p; j<r; j++) {
		if (Arr[j] <= pivotKey) {
			i++;
			//swap A[i] with A[j]
			s = Arr[i]; 	Arr[i] = Arr[j];	Arr[j] = s;
		}
	}

	i++;
	//swap Arr[i] with Arr[r]
	s = Arr[i];	Arr[i] = Arr[r];	Arr[r] = s;
	
	return i;
}

void quick_sort(int p, int r) {
	if (p < r) {
		int q = partition(p, r);

		quick_sort(p, q-1);
		quick_sort(q+1, r);
	}
}

void counting_sort(vector<int> &v) {
	// assuming range of vector elements is [0-99]
	vector<int> count(100, 0);
	int i, j, k;

	for (i=0; i<v.size(); i++) {
		j = v[i];
		count[j]++;
	}

	k=0;
	for (i=0; i<99; i++) {
		for (j=0; j<count[i]; j++) {
			v[k] = i;
			k++;
		}
	}

}

bool binarySearch(vector<int> &v, int start, int end, int key) {
	if (end < start)
		return false;

	if (start == end) 
		return (v[start] == key) ? true : false;

	int mid = start + (end-start)/2;
	if (v[mid] == key) 
		return true;
	else if (v[mid] > key)
		return binarySearch(v, start, mid-1, key);
	else if (v[mid] < key)
		return binarySearch(v, mid+1, end, key);
}


int main() {
	// Bubble sort - repeatedly swapping the adjacent elements if they are in wrong order.
	// Insertion sort - similar to bubble. Can be used for linked list
	vector<int> arr = {4,6,1,9,4,6,3};
	printf("Bubble Sort\n");
	display(arr);
	bubble_sort(arr);
	display(arr);
	arr.clear();

	// Selection sort - by repeatedly finding the minimum element (considering ascending order) from unsorted part and putting it at the beginning
	arr = {4,6,1,9,4,6,3};
	printf("\nSelection Sort\n");
	display(arr);
	bubble_sort(arr);
	display(arr);
	arr.clear();

	// Merge sort: a Divide and Conquer algorithm. 
	// It divides the input array into two halves, calls itself for the two halves, and then merges the two sorted halves. 
	// Time complexity: θ(nLogn) in all 3 cases (worst, average and best) 
	printf("\nMerge Sort\n");
	display(vec);
	merge_sort(0, vec.size()-1);
	display(vec);
	vec.clear();

	// Heap sort - covered in ds_basics3.cpp
	//	time complexity of Heap Sort is O(nLogn)

	// Quick sort - read cormen pg 171-173
	// 		picks an element as pivot and partitions the given array around the picked pivot.
	//		Time complexity: worst case: O(n^2) average case: O(n-log-n) and constant factors are small
	//		Advantage- sorting in place (whereas merge sort requires O(N) extra storage)
	printf("\nQuick Sort\n");
	display(Arr);
	quick_sort(0, Arr.size()-1);
	display(Arr);

	/* stl sort algorithm
		This function internally uses IntroSort. In more details it is implemented using hybrid of QuickSort, HeapSort and InsertionSort.By default, it uses QuickSort but if QuickSort is doing unfair partitioning and taking more than N*logN time, it switches to HeapSort and when the array size becomes really small, it switches to InsertionSort. 
	*/
	vec = {2, 6, 3, 8, 1, 11, 44, 33, 67, 9};
	printf("\nSTL Sort\n");
	display(vec);
	sort(vec.begin(), vec.end());
	display(vec);
	vec.clear();

	// Counting sort - sorting technique based on keys between a specific range. It works by counting the number of objects having distinct key values (kind of hashing).
	// 		- Time: O(n+k) where n is the number of elements in input array and k is the range of input. 
	//		- we could not sort the elements if we have negative numbers in it
	vec = {2, 6, 3, 8, 1, 11, 44, 33, 67, 9};
	printf("\nCounting Sort\n");
	display(vec);
	counting_sort(vec);
	display(vec);

	/* Radix sort - digit by digit sort starting from least significant digit to most significant digit. Radix sort uses counting sort as a subroutine to sort.
	Eg: 
		Original, unsorted list:
		170, 45, 75, 90, 802, 24, 2, 66

		Sorting by least significant digit (1s place) gives: 
		[*Notice that we keep 802 before 2, because 802 occurred 
		before 2 in the original list, and similarly for pairs 
		170 & 90 and 45 & 75.]

		170, 90, 802, 2, 24, 45, 75, 66

		Sorting by next digit (10s place) gives: 
		[*Notice that 802 again comes before 2 as 802 comes before 
		2 in the previous list.]

		802, 2, 24, 45, 66, 170, 75, 90

		Sorting by the most significant digit (100s place) gives:
		2, 24, 45, 66, 75, 90, 170, 802

	Application: 
		In a typical computer, which is a sequential random-access machine, where the records are keyed by multiple fields radix sort is used. For eg., you want to sort on three keys month, day and year. You could compare two records on year, then on a tie on month and finally on the date. Alternatively, sorting the data three times using Radix sort first on the date, then on month, and finally on year could be used.
*/

	/* Bucket sort: Bucket sort is mainly useful when input is uniformly distributed over a range. For example, consider the following problem. Sort a large set of floating point numbers which are in range from 0.0 to 1.0 and are uniformly distributed across the range. 

	Algo: 
		Loop through the original array and put each object in a “bucket”.
		Sort each of the non-empty buckets
		Check the buckets in order and then put all objects back into the original array.

	Time complexity: average time complexity is O(n + k)

	See: https://www.geeksforgeeks.org/bucket-sort-2/

	*/

	// Binary search
	printf("\nBinary search\n");
	display(vec);
	if (binarySearch(vec, 0, vec.size(), 3)) 
		cout << "3 is present" << endl;
	else
		cout << "3 is not present" << endl;

	if (binarySearch(vec, 0, vec.size(), 11)) 
		cout << "11 is present" << endl;
	else
		cout << "11 is not present" << endl;

	if (binarySearch(vec, 0, vec.size(), 45)) 
		cout << "45 is present" << endl;
	else
		cout << "45 is not present" << endl;
	
	if (binarySearch(vec, 0, vec.size(), 1)) 
		cout << "1 is present" << endl;
	else
		cout << "1 is not present" << endl;
	
	if (binarySearch(vec, 0, vec.size(), 68)) 
		cout << "68 is present" << endl;
	else
		cout << "68 is not present" << endl;

	if (binarySearch(vec, 0, vec.size(), 2)) 
		cout << "2 is present" << endl;
	else
		cout << "2 is not present" << endl;
	vec.clear();
	return 0;
}
