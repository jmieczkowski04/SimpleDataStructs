
# Simple data structures
C++ multiplatform, header-only data structs. Work as abstraction over pure C++ code. Handle memory management( preventing mem leaks) and add some useful features like getting a number of elements. Currently unsafe to use with multitasking.

## Quickstart
Just copy headers from src/ and include any structure you want to use(e.g. Array.h for arrays). All structures are in namespace zasty and are prefixed with T. Example:
```zasty::TArray<int> myArray;```

## Avaliable structures
Currently, the only available structures are TArray and TQueue, but in feature there will be added TStack and TMap.

## TArray API
 - operator\[size_t i\] - accessing element

 - Append(element) - add element to the back

 - Remove(size_t i) - remove element

 - Reserve(size_t N) - reserve memory for N elements. Useful if you want: A. remove more than one element from the end B. add many elements as optimalization C. use array in a static way

 - SetAutoAllocation(bool AutoAlloc) - use to set if the array is allowed to change dynamically. When set true, you can easily add new elements. When set false, you have to declare the size of the array via Reserve() function. Adding more elements than declared will throw error
 
 ## TQueue API
 - IsEmpty() - return true if no elements in queue
 
 - Enqueue(element) - add element to the end of queue
 
 - Dequeue() - remove and return first element