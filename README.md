# Dynamic Array in C

## Overview

This project implements a dynamic array in C, a fundamental data structure used in various applications. The dynamic array allows for efficient resizing, both expansion and contraction, to accommodate varying numbers of elements. This implementation demonstrates key programming concepts in C, including memory management, pointers, and data structure design.

## Features

- **Initialization**: Initializes a dynamic array with a specified initial capacity.
- **Appending**: Adds elements to the end of the array, resizing if necessary.
- **Removal**: Removes an element from a specified position in the array.
- **Automatic Resizing**: Dynamically increases and decreases the capacity of the array based on the number of elements.
- **Memory Management**: Efficiently allocates and frees memory to optimize resource usage.

## How to Compile and Run

To compile and run this project, you need a C compiler like GCC. Follow these steps:

1. Clone the repository or download the source code.
2. Navigate to the directory containing the source files.
3. Compile the program using a C compiler, e.g., `gcc -o dynamic_array main.c`.
4. Run the executable: `./dynamic_array`.

```c
// Initialize the Dynamic Array 
DynamicArray myArray;
initDynamicArray(&myArray, initialCapacity);

// Append elements
appendToDynArr(&myArray, element);

// Remove element
removeFromDynArr(&myArray, position);

// Free the allocated memory when done
freeDynArr(&myArray);
```

## License

Specify the license under which this project is made available. Common choices include MIT, GPL, Apache 2.0, etc.
