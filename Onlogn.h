#ifndef ONLOGN_H
#define ONLOGN_H
#include <iostream>
using namespace std;

void Merge(int arr[], int left, int mid, int right);
void MergeSort(int arr[], int left, int right);

void Heapify(int arr[], int n, int i);
void HeapSort(int arr[], int n);

void RadixSort(int arr[], int n);
void CountingSortForRadix(int arr[], int n, int exp);
int GetMax(int arr[], int n);

void QuickSort(int arr[], int low, int high);
int Partition(int arr[], int low, int high);

void ShellSort(int arr[], int n);
#endif 
