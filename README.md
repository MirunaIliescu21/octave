# Dynamic Matrix Management System in C

## Project Overview
This project allows for dynamic management of matrices in memory, including operations such as loading matrices, determining dimensions, displaying matrices, resizing, transposing, multiplying, and sorting. Additionally, the project includes the implementation of matrix multiplication using Strassen's algorithm. Matrices are stored in a resizable collection that automatically manages memory and capacity as matrices are added or modified.

## Features

### 1. Loading a Matrix into Memory
- Reads the number of rows and columns and allocates memory for a matrix of the specified dimensions.
- Uses a resizable array to store the collection of matrices. Each position in this array represents a newly loaded matrix, with dimensions stored in vectors for rows (`ql`) and columns (`qc`).
- Before adding a new matrix to the collection, the function `add_matrix` checks if there is sufficient capacity in the collection and vectors; if not, it doubles the capacity using `realloc`.

### 2. Determining Matrix Dimensions
- Reads an index and verifies if a matrix exists in the collection at that position.
- If valid, displays the dimensions stored in the `ql` and `qc` vectors; otherwise, displays an error message.

### 3. Displaying a Matrix from the Collection
- Reads an index and checks for the matrix at the specified position.
- If valid, displays the matrix from the collection; otherwise, shows an error message.

### 4. Resizing a Matrix
- Reads the matrix index, new number of rows, and the indices of rows to keep in the resized matrix, followed by the new number of columns and indices of columns to keep.
- If valid, performs resizing, keeping only specified elements, and creates a new matrix with updated dimensions, replacing the original matrix in the collection.
- Displays an error message if the specified index is invalid.

### 5. Multiplying Two Matrices
- Reads indices of two matrices to multiply.
- If both matrices exist in the collection, checks compatibility for multiplication (i.e., the number of columns in the first matrix equals the number of rows in the second matrix).
- Uses an algorithm to multiply matrices element-wise, storing the result in a new matrix at the end of the collection, reallocating memory if necessary.

### 6. Sorting Matrices
- Calculates the sum of elements for each matrix and stores the sums in the `sum` vector. The `top` vector is used to maintain an ordered list of matrix indices based on the sum of their elements.
- Uses Radix Sort to sort matrices by element sum in ascending order.

### 7. Transposing a Matrix
- Reads an index and checks if the matrix exists.
- For transposition, uses shared memory for the matrix to avoid unnecessary memory allocation. Retains specified rows and reallocates memory if needed, replacing the transposed matrix in the collection.

### 8. Releasing Memory for a Matrix
- Reads an index, verifies existence, and copies matrices with different indices to a new collection if valid. Shows an error message if the index is invalid.

### 9. Releasing All Resources
- Iterates through the collection, releasing memory for each matrix and associated row vectors.

### 10. Matrix Multiplication Using Strassen’s Algorithm
- Reads indices of two matrices to multiply and verifies if both matrices are square.
- If valid, performs Strassen’s multiplication by breaking matrices into blocks until reaching 1x1 matrices.
- Divides both matrices into four submatrices, allocating memory, initializing values, and calculating seven intermediary product matrices.
- Combines these products to form the result matrix, replacing the original, and releases all allocated memory.

## Getting Started
1. Clone the repository and navigate to the project directory.
2. Build and run the project using the following commands:
   ```bash
   make
   ./matrix_manager
