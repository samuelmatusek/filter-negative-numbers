# Deletion of Negative Numbers in an Array (C)

A CLI utility written in C that dynamically allocates an array of integers, filters out all negative values in-place, and shrinks the allocated memory block using `realloc` to fit the remaining elements.

## Features

- **Dynamic Memory Allocation:** Allocates the initial array on the heap using `malloc`.
- **In-Place Filtering:** Removes negative numbers without allocating a second full-sized array.
- **Memory Downsizing:** Uses `realloc` to safely shrink the allocated memory block to match the exact count of remaining positive numbers.
- **Memory Safe:** Handles edge cases (such as all numbers being negative or all positive) and cleans up properly to prevent memory leaks.

## How to Build and Run

### 1. Compilation
Compile using GCC with strict standard flags:
```bash
gcc -Wall -pedantic -g odstraneniZapornychCisel.c -o filter_negatives
```

### 2. Execution
```bash
./filter_negatives
```

### 3. Memory Leak Check (Valgrind)
```bash
valgrind --leak-check=full --show-leak-kinds=all ./filter_negatives
```

## Example Usage

```text
Zadejte pocet prvku:
6
Zadejte prvky:
4 -2 7 -8 0 5
Pole po odstraneni zapornych cisel:
4 7 0 5
```
