#include "Onlogn.h"
#include <iostream>
using namespace std;
extern long long comp;

void Merge(int arr[], int left, int mid, int right) {
	int n1 = mid - left + 1;
	int n2 = right - mid;
	int* L = new int[n1];
	int* R = new int[n2];
	for (int i = 0; i < n1; i++) {
		L[i] = arr[left + i];
	}
	for (int j = 0; j < n2; j++) {
		R[j] = arr[mid + 1 + j];
	}
	int i = 0, j = 0, k = left;
	while (i < n1 && j < n2) {
		comp++;
		if (L[i] <= R[j]) {
			arr[k++] = L[i++];
		}
		else {
			arr[k++] = R[j++];
		}
	}
	while (i < n1)
		arr[k++] = L[i++];
	while (j < n2)
		arr[k++] = R[j++];
	delete[] R;
	delete[] L;
}
void MergeSort(int arr[], int left, int right) {
	if (left >= right) return;
	int mid = left + (right - left) / 2;
	MergeSort(arr, left, mid);
	MergeSort(arr, mid + 1, right);
	Merge(arr, left, mid, right);
}
int Partition(int arr[], int low, int high) {
	swap(arr[low + (high - low) / 2], arr[high]);
	int pivot = arr[high];
	int i = low - 1;
	for (int j = low; j < high; j++) {
		comp++;
		if (arr[j] < pivot) {
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return i + 1;
}
void QuickSort(int arr[], int low, int high) {
	if (low < high) {
		int pivot = Partition(arr, low, high);
		QuickSort(arr, low, pivot - 1);
		QuickSort(arr, pivot + 1, high);
	}
}
void Heapify(int arr[], int n, int i) {
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left < n && ++comp && arr[left] > arr[largest]) {
		largest = left;
	}
	if (right < n && ++comp && arr[right] > arr[largest]) {
		largest = right;
	}
	if (largest != i) {
		swap(arr[i], arr[largest]);
		Heapify(arr, n, largest);
	}
}
void HeapSort(int arr[], int n) {
	for (int i = n / 2 - 1; i >= 0; i--) {
		Heapify(arr, n, i);
	}
	for (int i = n - 1; i > 0; i--) {
		swap(arr[0], arr[i]);
		Heapify(arr, i, 0);
	}
}
int GetMax(int arr[], int n) {
	int max = arr[0];
	for (int i = 1; i < n; i++) {
		comp++;
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}
void CountingSortForRadix(int arr[], int n, int exp) {
	int* output = new int[n];
	int count[10] = { 0 };
	for (int i = 0; i < n; i++) {
		count[(arr[i] / exp) % 10]++;
	}
	for (int i = 1; i < 10; i++) {
		count[i] += count[i - 1];
	}
	for (int i = n - 1; i >= 0; i--) {
		int digit = (arr[i] / exp) % 10;
		output[count[digit] - 1] = arr[i];
		count[digit]--;
	}
	for (int i = 0; i < n; i++)
		arr[i] = output[i];
	delete[] output;
}
void RadixSort(int arr[], int n) {
	int m = GetMax(arr, n);
	for (int exp = 1; m / exp > 0; exp *= 10)
		CountingSortForRadix(arr, n, exp);
}

void ShellSort(int arr[], int n) {
	for (int gap = n / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < n; i++) {
			int temp = arr[i];
			int j = i;
			while (j >= gap && ++comp && arr[j - gap] > temp) {
				arr[j] = arr[j - gap];
				j -= gap;
			}
			arr[j] = temp;
		}
	}
}