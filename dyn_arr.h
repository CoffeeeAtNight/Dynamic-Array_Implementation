// dyn_arr.h
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
  int *arr;
  size_t size;
  size_t capacity;
} DynamicArray;

int initDynamicArray(DynamicArray *pDynArr, size_t initCapacity);
int appendToDynArr(DynamicArray *pDynArr, int item);
int removeFromDynArr(DynamicArray *pDa, int rm_pos);
DynamicArray *reallocDynArr(DynamicArray *pDynArr, int mode);
DynamicArray *reallocateDynArrToIncreaseCapacity(DynamicArray *pDynArr);
DynamicArray *reallocateDynArrToDecreaseCapacity(DynamicArray *pDynArr);
int freeDynArr(DynamicArray *pDynArr);
size_t getSizeOfDynArr(DynamicArray *pDynArr);
void setSizeOfDynArr(DynamicArray *pDynArr, size_t newSize);
size_t getCapacityOfDynArr(DynamicArray *pDynArr);
void setCapacityOfDynArr(DynamicArray *pDynArr, size_t newCapacity);
int *getDynArr(DynamicArray *pDynArr);
int internalHandleError(const char *errMsg);
void printDynArrStatus(DynamicArray *pDynArr);


/**
 * Initializes a dynamic array with the given initial capacity.
 *
 * @param pDynArr a pointer to the DynamicArray struct
 * @param initCapacity the initial capacity of the dynamic array
 *
 * @return 0 on success
 *
 * @throws ErrorType if an error occurs while trying to allocate memory
 */
int initDynamicArray(DynamicArray *pDynArr, size_t initCapacity)
{
  pDynArr->arr = (int*)malloc(sizeof(int) * initCapacity);
  if (!getDynArr(pDynArr))
    return internalHandleError("Error occurred while trying to allocate memory.\n");

  pDynArr->size = 0;
  pDynArr->capacity = initCapacity;
  return 0;
}


/**
 * Appends an item to the given DynamicArray.
 *
 * @param pDynArr a pointer to the DynamicArray structure to append the item to
 * @param item the item to be appended to the DynamicArray
 *
 * @return 0 indicating successful append
 *
 * @throws ErrorType if there is an error during the append operation
 */
int appendToDynArr(DynamicArray *pDynArr, int item)
{
  int currentSize = getSizeOfDynArr(pDynArr);
  if (currentSize + 1 >= getCapacityOfDynArr(pDynArr))
  {
    pDynArr = reallocateDynArrToIncreaseCapacity(pDynArr);
  }

  pDynArr->arr[pDynArr->size] = item;
  int newSize = currentSize + 1;

  setSizeOfDynArr(pDynArr, newSize);
  return 0;
}

/**
 * Removes an element from the given DynamicArray at the specified position.
 *
 * @param pDynArr pointer to the DynamicArray
 * @param rm_pos the position of the element to be removed
 *
 * @return -1 if an error occurs, otherwise no return value
 *
 * @throws None
 */
int removeFromDynArr(DynamicArray *pDynArr, int rm_pos)
{
  int currentSize = getSizeOfDynArr(pDynArr);
  int currentCapacity = getCapacityOfDynArr(pDynArr);

  if (rm_pos > currentSize || rm_pos < 0) 
  {
    printf("Out of bound, no element to remove at position %d", rm_pos);
    return -1;
  }

  for (size_t i = rm_pos + 1; i < currentSize; i++)
  {
    pDynArr->arr[i-1] = pDynArr->arr[i];
  }

  setSizeOfDynArr(pDynArr, currentSize - 1);

  reallocateDynArrToDecreaseCapacity(pDynArr);
}

/**
 * Frees the memory of the previously allocated dynamic array.
 *
 * @param pDynArr pointer to the DynamicArray
 *
 * @return 0 if the memory is freed successfully
 *
 * @throws None
 */
int freeDynArr(DynamicArray *pDynArr)
{  
  free(pDynArr->arr);
  pDynArr = NULL;
  return 0;
}

// Getters and Setters

size_t getSizeOfDynArr(DynamicArray *pDynArr) 
{
  return pDynArr->size;
}

void setSizeOfDynArr(DynamicArray *pDynArr, size_t newSize)
{
  pDynArr->size = newSize;
}

size_t getCapacityOfDynArr(DynamicArray *pDynArr)
{
  return pDynArr->capacity;
}

void setCapacityOfDynArr(DynamicArray *pDynArr, size_t newCapacity)
{
  pDynArr->capacity = newCapacity;
}

int *getDynArr(DynamicArray *pDynArr)
{
  return pDynArr->arr;
}

DynamicArray *reallocateDynArrToIncreaseCapacity(DynamicArray *pDynArr)
{
  printf("Array capacity reached...\n");
  printf("Reallocating array to increase capacity by x2\n");
  int currentCapacity = getCapacityOfDynArr(pDynArr);

  reallocDynArr(pDynArr, 1);

  setCapacityOfDynArr(pDynArr, currentCapacity * 2);

  printDynArrStatus(pDynArr);
  return pDynArr;
}

DynamicArray *reallocateDynArrToDecreaseCapacity(DynamicArray *pDynArr)
{
  printf("Reallocating array to decrease capacity minus 1\n");

  int currentCapacity = getCapacityOfDynArr(pDynArr);
  reallocDynArr(pDynArr, 0);
  setCapacityOfDynArr(pDynArr, currentCapacity - 1);

  printDynArrStatus(pDynArr);
  return pDynArr;
}

DynamicArray *reallocDynArr(DynamicArray *pDynArr, int mode)
{
  size_t newCapacity;
  if (mode == 0) {
    // Remove element mode TODO
    newCapacity = getCapacityOfDynArr(pDynArr) - 1;
  } else {
    // Append element mode TODO
    newCapacity = getCapacityOfDynArr(pDynArr) * 2;
  }

  pDynArr->arr = (int *)realloc(getDynArr(pDynArr), (newCapacity * sizeof(int)));

  if (pDynArr->arr == NULL)
  {
    internalHandleError("Error occurred trying to re-allocate the array.");
    return NULL;
  }

  return pDynArr;
}

void printDynArrStatus(DynamicArray *pDynArr) 
{
  printf("After re-allocation the new capacity is now: %ld elements\n", getCapacityOfDynArr(pDynArr));
  printf("Total size of allocated memory is: %ld bytes\n", (sizeof(int) * getCapacityOfDynArr(pDynArr)));
  printf("\n");
}

int internalHandleError(const char *errMsg)
{
  fprintf(stderr, "%s", errMsg);
  return 1;
}

// End of dyn_arr.h