#include <iostream>
#include <fstream>
#include <cstring>
#include <ctime>
#include <iomanip>
#include "DataGenerator.h"
#include "On2.h"
#include "Onlogn.h"
#include "On.h"
using namespace std;
long long comp = 0;
void CopyArray(int a[], int b[], int n) {
	for (int i = 0; i < n; i++) b[i] = a[i];
}
void RunSort(string algo, int a[], int n) {
	if (algo == "selection-sort") SelectionSort(a, n);
	else if (algo == "insertion-sort") InsertionSort(a, n);
	else if (algo == "bubble-sort") BubbleSort(a, n);
	else if (algo == "quick-sort") QuickSort(a, 0, n - 1);
	else if (algo == "merge-sort") MergeSort(a, 0, n - 1);
	else if (algo == "heap-sort") HeapSort(a, n);
	else if (algo == "shell-sort") ShellSort(a, n);
	else if (algo == "radix-sort") RadixSort(a, n);
	else if (algo == "counting-sort") CountingSort(a, n);
	else if (algo == "shaker-sort") ShakerSort(a, n);
	else if (algo == "flash-sort") FlashSort(a, n);
	else if (algo == "binary-insertion-sort") BinaryInsertionSort(a, n);
}
int main(int argc, char* argv[]) {
	if (argc < 2) {
		cout << "Invalid command\n";
		return 0;
	}
	string mode = argv[1];
	if (mode == "-a") {
		cout << "ALGORITHM MODE\n";
		string algorithm = argv[2];
		ifstream fin(argv[3]);
		if (fin) {
			string inputFile = argv[3];
			string outputParam = argv[4];
			int n;
			fin >> n;
			int* a = new int[n];
			for (int i = 0; i < n; i++) fin >> a[i];
			cout << "Algorithm: " << algorithm << "\nInput file: " << inputFile << "\nInput size: " << n << "\n-------------------------\n";
			comp = 0;
			clock_t start = clock();
			RunSort(algorithm, a, n);
			clock_t end = clock();
			double time = (double)(end - start) / CLOCKS_PER_SEC * 1000;
			if (outputParam == "-time" || outputParam == "-both") cout << "Running time: " << time << " ms\n";
			if (outputParam == "-comp" || outputParam == "-both") cout << "Comparisons: " << comp << "\n";
			ofstream fout("output.txt");
			fout << n << "\n";
			for (int i = 0; i < n; i++) fout << a[i] << " ";
			delete[] a;
		}
		else if (argc == 6) {
			int n = atoi(argv[3]);
			string order = argv[4];
			string outputParam = argv[5];
			int* a = new int[n];
			if (order == "-rand") GenerateData(a, n, 0);
			else if (order == "-sorted") GenerateData(a, n, 1);
			else if (order == "-rev") GenerateData(a, n, 2);
			else if (order == "-nsorted") GenerateData(a, n, 3);
			ofstream finp("input.txt");
			finp << n << "\n";
			for (int i = 0; i < n; i++) finp << a[i] << " ";
			finp.close();
			cout << "Algorithm: " << algorithm << "\nInput size: " << n << "\nInput order: " << order << "\n-------------------------\n";
			comp = 0;
			clock_t start = clock();
			RunSort(algorithm, a, n);
			clock_t end = clock();
			double time = (double)(end - start) / CLOCKS_PER_SEC * 1000;
			if (outputParam == "-time" || outputParam == "-both") cout << "Running time: " << time << " ms\n";
			if (outputParam == "-comp" || outputParam == "-both") cout << "Comparisons: " << comp << "\n";
			ofstream fout("output.txt");
			for (int i = 0; i < n; i++) fout << a[i] << " ";
			delete[] a;
		}
		else if (argc == 5) {
			int n = atoi(argv[3]);
			string outputParam = argv[4];
			cout << "Algorithm: " << algorithm << "\nInput size: " << n << "\n";
			string orders[4] = { "Randomize", "Nearly Sorted", "Sorted", "Reversed" };
			string fnames[4] = { "input_1.txt", "input_3.txt", "input_4.txt", "input_2.txt" };
			for (int type = 0; type < 4; type++) {
				int* a = new int[n];
				GenerateData(a, n, type);
				ofstream finp(fnames[type]);
				finp << n << "\n";
				for (int i = 0; i < n; i++) finp << a[i] << " ";
				finp.close();
				cout << "\nInput order: " << orders[type] << "\n-------------------------\n";
				comp = 0;
				clock_t start = clock();
				RunSort(algorithm, a, n);
				clock_t end = clock();
				double time = (double)(end - start) / CLOCKS_PER_SEC * 1000;
				if (outputParam == "-time" || outputParam == "-both") cout << "Running time: " << time << " ms\n";
				if (outputParam == "-comp" || outputParam == "-both") cout << "Comparisons: " << comp << "\n";
				ofstream fout("output.txt");
				for (int i = 0; i < n; i++) fout << a[i] << " ";
				delete[] a;
			}
		}
	}
	else if (mode == "-c") {
		cout << "COMPARISON MODE\n";
		string alg1 = argv[2];
		string alg2 = argv[3];
		ifstream fin(argv[4]);
		if (fin) {
			int n;
			fin >> n;
			int* a = new int[n];
			int* b = new int[n];
			for (int i = 0; i < n; i++) {
				fin >> a[i];
				b[i] = a[i];
			}
			cout << "Algorithm: " << alg1 << " | " << alg2 << "\nInput file: " << argv[4] << "\nInput size: " << n << "\n-------------------------\n";
			comp = 0;
			clock_t start1 = clock();
			RunSort(alg1, a, n);
			clock_t end1 = clock();
			long long comp1 = comp;
			comp = 0;
			clock_t start2 = clock();
			RunSort(alg2, b, n);
			clock_t end2 = clock();
			long long comp2 = comp;
			double time1 = (double)(end1 - start1) / CLOCKS_PER_SEC * 1000;
			double time2 = (double)(end2 - start2) / CLOCKS_PER_SEC * 1000;
			cout << "Running time: " << time1 << " ms" << " | " << time2 << " ms" << "\nComparisons: " << comp1 << " | " << comp2 << "\n";
			ofstream fout("output.txt");
			for (int i = 0; i < n; i++) fout << a[i] << " ";
			delete[] a;
			delete[] b;
		}
		else {
			int n = atoi(argv[4]);
			string order = argv[5];
			int* a = new int[n];
			int* b = new int[n];
			if (order == "-rand") GenerateData(a, n, 0);
			else if (order == "-sorted") GenerateData(a, n, 1);
			else if (order == "-rev") GenerateData(a, n, 2);
			else if (order == "-nsorted") GenerateData(a, n, 3);
			ofstream finp("input.txt");
			finp << n << "\n";
			for (int i = 0; i < n; i++) finp << a[i] << " ";
			finp.close();
			CopyArray(a, b, n);
			cout << "Algorithm: " << alg1 << " | " << alg2 << "\nInput size: " << n << "\nInput order: " << order << "\n-------------------------\n";
			comp = 0;
			clock_t start1 = clock();
			RunSort(alg1, a, n);
			clock_t end1 = clock();
			long long comp1 = comp;
			comp = 0;
			clock_t start2 = clock();
			RunSort(alg2, b, n);
			clock_t end2 = clock();
			long long comp2 = comp;
			double time1 = (double)(end1 - start1) / CLOCKS_PER_SEC * 1000;
			double time2 = (double)(end2 - start2) / CLOCKS_PER_SEC * 1000;
			cout << fixed << setprecision(3) << "Running time: " << time1 << " ms" << " | " << time2 << " ms" << "\nComparisons: " << comp1 << " | " << comp2 << "\n";
			delete[] a;
			delete[] b;
		}
	}
	return 0;
}