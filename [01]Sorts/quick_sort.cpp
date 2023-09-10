//after implementation, ive found it has worst time complexity among all sorts

#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& array, int low, int high) {
    int pivot = array[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i++;
            swap(array[i], array[j]);
        }
    }

    swap(array[i + 1], array[high]);

    return i + 1;
}

void quickSort(vector<int>& array, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(array, low, high);
        quickSort(array, low, pivotIndex - 1);
        quickSort(array, pivotIndex + 1, high);
    }
}

int main() {
    int numElements;
    cout << "Enter the number of elements in the array: ";
    cin >> numElements;

    vector<int> inputArray(numElements);

    cout << "Enter " << numElements << " integers: ";
    for (int i = 0; i < numElements; i++) {
        cin >> inputArray[i];
    }

    cout << "Original Array: ";
    for (int element : inputArray) {
        cout << element << " ";
    }
    cout << endl;

    quickSort(inputArray, 0, numElements - 1);

    cout << "Sorted Array: ";
    for (int element : inputArray) {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}
