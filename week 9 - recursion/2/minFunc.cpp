#include "minFunc.h"

const int *min(const int arr[], int arrSize) {
    if (arrSize == 0) {
        return nullptr;
    }
    if (arrSize == 1) {
        // Base case.
        // array has 1 element, which is the minimum value
        return arr;
    } else {
        // uses recursion to find the smallest value in the array
        const int *temp = min(arr + 1, arrSize - 1);

        // if the first element in arr < the first element in smallest, it returns arr, which is the minumum
        if (*arr <= *temp) {
            return arr;
        } else {
            // the minumum will be the other value
            return temp;
        }
    }
}