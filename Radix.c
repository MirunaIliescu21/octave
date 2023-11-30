#include <stdlib.h>
#include "Validate.h"

int get_max(int arr[], int n)
{
	int mx = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > mx)
			mx = arr[i];
	return mx;
}

// A function to do counting sort of arr[]
// according to the digit
// represented by exp.
void count_sort(int arr[], int n, int exp)
{
	// Output array
	int output[n];
	int i, count[10] = {0};

	// Store count of occurrences
	// in count[]
	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;

	// Change count[i] so that count[i]
	// now contains actual position
	// of this digit in output[]
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	// Build the output array
	for (i = n - 1; i >= 0; i--) {
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	// Copy the output array to arr[],
	// so that arr[] now contains sorted
	// numbers according to current digit
	for (i = 0; i < n; i++)
		arr[i] = output[i];
}

void radix_sort(int arr[], int n)
{
	// Find the maximum number to
	// know number of digits
	int m = get_max(arr, n);

	// Do counting sort for every digit.
	// Note that instead of passing digit
	// number, exp is passed. exp is 10^i
	// where i is current digit number
	for (int exp = 1; m / exp > 0; exp *= 10)
		count_sort(arr, n, exp);
}

int find_element_in_vector(int odx[], int n, int e)
{
	int i;
	int f = -1;
	for (i = 0; i < n; i++)
		if (odx[i] == e) {
			f = i;
			break;
		}
	return f;
}

void sort_vector(int *arr, int n, int *top)
{
	int *odx = malloc(n * sizeof(int));
	int i;
	for (i = 0; i < n; i++)
		odx[i] = arr[i];
	radix_sort(arr, n);
	for (i = 0; i < n; i++)
		top[i] = find_element_in_vector(odx, n, arr[i]);

	free(odx);
}
