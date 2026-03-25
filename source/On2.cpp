#include <iostream>
#include "On2.h"
using namespace std;
extern long long comp;
void BinaryInsertionSort(int a[], int n) {
	for (int i = 1; i < n; ++i) {
		int key = a[i];
		int first = 0, last = i - 1;
		while (first <= last) {
			int m = (first + last) / 2;
			comp++;
			if (key < a[m]) last = m - 1;
			else first = m + 1;
		}
		for (int j = i - 1; j >= first; --j)
			a[j + 1] = a[j];
		a[first] = key;
	}
}
void BubbleSort(int a[], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j > i; j--) {
			comp++;
			if (a[j] < a[j - 1]) {
				swap(a[j], a[j - 1]);
			}
		}
	}
}
void InterchangeSort(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			comp++;
			if (a[i] > a[j]) {
				swap(a[i], a[j]);
			}
		}
	}
}
void SelectionSort(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int min_index = i;
		for (int j = i + 1; j < n; j++) {
			comp++;
			if (a[j] < a[min_index]) {
				min_index = j;
			}
		}
		swap(a[min_index], a[i]);
	}
}
void InsertionSort(int arr[], int n) {
	for (int i = 1; i <= n - 1; i++) {
		int j = i;
		while (j > 0 && ++comp && arr[j - 1] > arr[j]) {
			int tmp = arr[j - 1];
			arr[j - 1] = arr[j];
			arr[j] = tmp;
			j--;
		}
	}
}

void ShakerSort(int a[], int n) {
	int left = 0, right = n - 1;
	while (++comp && left < right) {
		for (int i = left; ++comp && i < right; i++) {
			if (++comp && a[i] > a[i + 1]) {
				int tmp = a[i]; a[i] = a[i + 1]; a[i + 1] = tmp;
			}
		}
		right--;
		for (int i = right; ++comp && i > left; i--) {
			if (++comp && a[i] < a[i - 1]) {
				int tmp = a[i]; a[i] = a[i - 1]; a[i - 1] = tmp;
			}
		}
		left++;
	}
}
