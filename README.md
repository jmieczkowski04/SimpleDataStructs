
# Simple data structures
C++ multiplatform, header-only data structs. Work as abstraction over pure C++ code. Handle memory management( preventing mem leaks) and add some useful features like getting a number of elements.

## Quickstart
Just copy headers from src/ and include any structure you want to use(e.g. Array.h for arrays). All structures are in namespace zasty and are prefixed with T. Example:
```zasty::TArray<int> myArray;```

## Avaliable structures
Currently, the only one available is TArray, but in feature I will add TQueue, TMap and TStack.

## TArray API
 - operator\[size_t i\] - accessing element

 - Append(element) - adding element to the back

 - Remove(size_t i) - removing element

 - Reserve(size_t N) - reserving memory for N elements. Useful if you want: A. remove more than one element from the end B. add many elements as optimalization C. use array in a static way

 - SetAutoAllocation(bool AutoAlloc) - setting if the array is allowed to change dynamically. When set true, you can easily add new elements. When set false, you have to declare the size of the array via Reserve() function. Adding more elements than declared will throw error