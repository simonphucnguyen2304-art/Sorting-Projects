#include <iostream>
#include "On.h"
using namespace std;
extern long long comp;

void FlashSort(int a[], int n) {
	if (++comp && n <= 1) return;
	int m = int(0.45 * n);
	int* L = new int[m]();
	int minVal = a[0], maxIdx = 0;
	for (int i = 1; ++comp && i < n; i++) {
		if (++comp && a[i] < minVal) minVal = a[i];
		if (++comp && a[i] > a[maxIdx]) maxIdx = i;
	}
	if (++comp && a[maxIdx] == minVal) { delete[] L; return; }
	double c = (double)(m - 1) / (a[maxIdx] - minVal);
	for (int i = 0; ++comp && i < n; i++) {
		int k = int(c * (a[i] - minVal));
		L[k]++;
	}
	for (int i = 1; ++comp && i < m; i++) L[i] += L[i - 1];
	int tmp0 = a[maxIdx]; a[maxIdx] = a[0]; a[0] = tmp0;
	int move = 0, j = 0, k = m - 1;
	while (++comp && move < n - 1) {
		while (++comp && j > L[k] - 1) {
			j++;
			k = int(c * (a[j] - minVal));
		}
		int flash = a[j];
		while (++comp && j != L[k]) {
			k = int(c * (flash - minVal));
			int pos = --L[k];
			int tmpF = flash; flash = a[pos]; a[pos] = tmpF;
			move++;
		}
	}
	for (int i = 1; ++comp && i < n; i++) {
		int key = a[i], pos = i - 1;
		while (++comp && pos >= 0 && ++comp && a[pos] > key) {
			a[pos + 1] = a[pos];
			pos--;
		}
		a[pos + 1] = key;
	}
	delete[] L;
}

void CountingSort(int arr[], int n)
{
	int maxVal = arr[0];

	for (int i = 1; i < n; i++) {
		comp++;
		if (arr[i] > maxVal)
			maxVal = arr[i];
	}

	int* count = new int[maxVal + 1]();

	for (int i = 0; i < n; i++)
		count[arr[i]]++;

	int index = 0;

	for (int i = 0; i <= maxVal; i++)
		while (count[i]--)
			arr[index++] = i;

	delete[] count;
}