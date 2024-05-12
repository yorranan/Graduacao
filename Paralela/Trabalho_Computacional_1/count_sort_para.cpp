// C++ code for the above approach: 
#include <iostream> 
#include <omp.h> 
#include <vector> 

using namespace std; 

// Function to find maximum value in array 
int getMax(vector<int> arr, int n) 
{ 
	int mx = arr[0]; 
	for (int i = 1; i < n; i++) 
		if (arr[i] > mx) 
			mx = arr[i]; 
	return mx; 
} 

// Count sort of arr[] 
void countSort(vector<int>& arr, int n, int exp) 
{ 

	// Output array 
	int output[n]; 
	int i, count[10] = { 0 }; 

	// Store count of occurrences in count[] 
	for (i = 0; i < n; i++) 
		count[(arr[i] / exp) % 10]++; 

	// Change count[i] so that count[i] now contains actual 
	// position of this digit in output[] 
	for (i = 1; i < 10; i++) 
		count[i] += count[i - 1]; 

	// Build the output array 
	for (i = n - 1; i >= 0; i--) { 
		output[count[(arr[i] / exp) % 10] - 1] = arr[i]; 
		count[(arr[i] / exp) % 10]--; 
	} 

	// Copy the output array to arr[], so that arr[] now 
	// contains sorted numbers according to current digit 
	for (i = 0; i < n; i++) 
		arr[i] = output[i]; 
} 

// Parallel count sort 
void parallelCountSort(vector<int>& arr, int n) 
{ 
	int m = getMax(arr, n); 

	// Do counting sort for every digit. Note that instead 
	// of passing digit number, exp is passed. exp is 10^i 
	// where i is current digit number 
	for (int exp = 1; m / exp > 0; exp *= 10) { 
		for (int i = 0; i < n; i++) 
			countSort(arr, n, exp); 
	} 
} 

// Driver program to test above functions 
int main() 
{ 
	vector<int> arr = { 170, 45, 75, 90, 802, 24, 2, 66 }; 
	int n = arr.size(); 
	cout << "Array before sorting: \n"; 
	for (int i = 0; i < n; i++) { 
		cout << arr[i] << " "; 
	} 
	cout << "\n"; 
	parallelCountSort(arr, n); 

	cout << "Array after sorting: \n"; 
	for (int i = 0; i < n; i++) { 
		cout << arr[i] << " "; 
	} 
	return 0; 
}
