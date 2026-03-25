#ifndef DATAGENERATOR_H
#define DATAGENERATOR_H
#include <iostream>
template <class T>
void Swap(T& a, T& b); 

void GenerateRandomData(int a[], int n);
void GenerateSortedData(int a[], int n);
void GenerateReverseData(int a[], int n);
void GenerateNearlySortedData(int a[], int n);
void GenerateData(int a[], int n, int dataType); 
void PrintArray(int a[], int n);

#endif 
