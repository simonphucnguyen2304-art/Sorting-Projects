# Sorting Algorithms: Analysis and Comparison 

A comprehensive C++ tool developed for executing, analyzing, and comparing various sorting algorithms. This project supports multiple input data distributions and provides detailed performance metrics, including execution time (ms) and algorithmic comparisons.

----------------------------------------------------------

## Contributors
Developed as part of the **Data Structures and Algorithms** course at **HCMUS**.

* **Đỗ Đăng Tú**
* **Đỗ Minh Khang**
* **Huỳnh Phúc Nguyên**
* **Huỳnh Đình Khương**

----------------------------------------------------------

## Features

* **Algorithms Implemented:** Selection Sort, Insertion Sort, Bubble Sort, Shaker Sort, Shell Sort, Heap Sort, Merge Sort, Quick Sort, Counting Sort, Radix Sort, and Flash Sort.
* **Data Generation:** Supports four distinct data distributions:
    * `Random` (-rand)
    * `Sorted` (-sorted)
    * `Reverse Sorted` (-rev)
    * `Nearly Sorted` (-nsorted)
* **Performance Measurement:** Precise tracking of:
    * **Runtime:** Execution time measured in milliseconds (ms).
    * **Comparisons:** Total count of algorithmic comparisons (comp).

----------------------------------------------------------

## Project Structure

The source code is organized into a modular architecture:

| Component | Files | Description |
| :--- | :--- | :--- |
| **Header Files** | `On2.h`, `Onlogn.h`, `DataGenerator.h` | Declarations for algorithms and utilities. |
| **Main Logic** | `main.cpp` | Entry point; handles CLI arguments and flow. |
| **O(n²) Algos** | `O(n2).cpp` | Implementations of average $O(n^2)$ algorithms. |
| **O(n log n) Algos** | `O(nlogn).cpp` | Implementations of average $O(n \log n)$ algorithms. |
| **O(n) Algos** | `O(n).cpp` | Implementations of average $O(n)$ algorithms. |
| **Data Gen** | `DataGenerator.cpp` | Utilities for creating test data distributions. |

----------------------------------------------------------

## Installation & Compilation

To build the project, ensure you have a C++ compiler (`g++`) installed.

1.  **Navigate** to the project directory.
2.  **Compile** using the following command:
    ```bash
    g++ *.cpp -std=c++14 -o groupID.exe
    ```

----------------------------------------------------------

## Usage Guide

The program operates in two primary modes: **Algorithm Mode** (`-a`) and **Comparison Mode** (`-c`).

### [ALGORITHM MODE]
* **Command 1:** Run a sort on an existing input file.
    `./groupID.exe -a [Algorithm] [Input_file] [Output_parameter]`
* **Command 2:** Run a sort on generated data with a specific order.
    `./groupID.exe -a [Algorithm] [Input_size] [Input_order] [Output_parameter]`
* **Command 3:** Run a sort on all data orders for a given size.
    `./groupID.exe -a [Algorithm] [Input_size] [Output_parameter]`

### [COMPARISON MODE]
* **Command 4:** Compare two algorithms on an existing input file.
    `./groupID.exe -c [Algorithm1] [Algorithm2] [Input_file]`
* **Command 5:** Compare two algorithms on generated data.
    `./groupID.exe -c [Algorithm1] [Algorithm2] [Input_size] [Input_order]`

### [PARAMETERS]
* **[Algorithm]:** `selection-sort`, `quick-sort`, `flash-sort`, `radix-sort`, etc.
* **[Input_order]:** `-rand`, `-nsorted`, `-sorted`, `-rev`.
* **[Output_parameter]:** `-time` (Runtime), `-comp` (Comparisons), `-both` (Both).

----------------------------------------------------------
