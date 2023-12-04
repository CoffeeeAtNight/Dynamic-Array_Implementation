#include "dyn_arr.h"

#define CAPACITY 10 

int main(int argc, char const *argv[])
{
  DynamicArray pDynArr;

  initDynamicArray(&pDynArr, CAPACITY);

  for (size_t i = 0; i < 20; i++)
  {
    appendToDynArr(&pDynArr, i);
  }

  printf("\nNumber of elements: %zu\n", getSizeOfDynArr(&pDynArr));
  printf("\nElements are: \n");

  for (size_t i = 0; i < pDynArr.size; i++)
  {
    printf("%d ", pDynArr.arr[i]);
  }

  printf("\nNow removing element from position 10: \n");
  removeFromDynArr(&pDynArr, 10);

  printf("Elements after removal: \n");
  for (size_t i = 0; i < pDynArr.size; i++)
  {
    printf("%d ", pDynArr.arr[i]);
  }

  free(pDynArr.arr);

  printf("\n");
  return 0;
}
