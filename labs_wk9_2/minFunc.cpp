#include "minFunc.h"
const int * min(const int arr[], int arrSize) {
    
    if (arrSize == 0) {
        return nullptr;
    }
    else if (arrSize == 1) {
        return arr + (arrSize - 1);
    }
    else {
        const int * minPointer = min(arr, arrSize - 1);
        if (*minPointer < arr[arrSize - 1]) {
            return minPointer;
        }
        else {
            return arr + (arrSize - 1);
        }
    }
}