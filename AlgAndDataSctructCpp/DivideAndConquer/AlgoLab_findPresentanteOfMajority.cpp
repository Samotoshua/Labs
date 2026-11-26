#include <iostream>

using std::cin, std::cout, std::endl;

void fillArray(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
}

void printArray(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}


int presentanteOfMajority_Linear(int *arr, int n) {
    if (n <= 0) return -1;

    int majorCount = 0;
    int majorValue = arr[0];

    for (int i = 0; i < n; i++) {
        int count = 0;

        for (int j = 0; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }

        if (count > majorCount) {
            majorCount = count;
            majorValue = arr[i];
        }
    }

    return majorValue;
}


int presentanteOfMajority_DivideAndConquer(int *arr, int n, int left, int right) {
    if (n <= 0 || left > right) return -1;

    if (left == right) {
        return arr[left];
    }

    int middle = (left + right) / 2;

    int leftValue = presentanteOfMajority_DivideAndConquer(arr, n, left, middle);
    int rightValue = presentanteOfMajority_DivideAndConquer(arr, n, middle + 1, right);

    int leftCount = 0;
    int rightCount = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == leftValue) leftCount++;
        if (arr[i] == rightValue) rightCount++;
    }

    if (leftCount >= rightCount) {
        return leftValue;
    }

    return rightValue;
}


int main() {
    int n = 5;
    int *arr = new int[n];

    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 1;
    arr[3] = 2;
    arr[4] = 2;



    // fillArray(arr, n);
    printArray(arr, n);

    cout << endl;

    cout << presentanteOfMajority_Linear(arr,5);
    cout << endl;
    cout << presentanteOfMajority_DivideAndConquer(arr,n, 0, n-1);

    delete[] arr;

    return 0;
}
