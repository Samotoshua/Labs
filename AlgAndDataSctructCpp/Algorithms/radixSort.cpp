#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void fillArray(int a[], int n, int mode) {
    for (int i = 0; i < n; i++) {
        switch (mode) {
            case 1: a[i] = rand() % 1000; break;
            case 2: a[i] = 0; break;
            case 3: a[i] = i; break;
            case 4: a[i] = n - i - 1; break;
            case 5: a[i] = rand() % 5; break;
            case 6: a[i] = i; break;
        }
    }
    // Для майже впорядкованого масиву міняємо місцями два елементи.
    if (mode == 6 && n >= 2) {
        int first = n / 3;
        int second = first + 1;
        int temp = a[first];
        a[first] = a[second];
        a[second] = temp;
    }
}

void printArray(const int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    cout << '\n';
}

void radixSort(int a[], int n) {
    if (n <= 1) return;

    int maximum = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > maximum) maximum = a[i];
    }

    int* result = new int[n];
    for (long long place = 1; maximum / place > 0; place *= 10) {
        int count[10] = {};

        // Підраховуємо цифри поточного розряду.
        for (int i = 0; i < n; i++) {
            int digit = (a[i] / place) % 10;
            count[digit]++;
        }

        // Визначаємо кінцеву позицію кожної групи.
        for (int digit = 1; digit < 10; digit++) {
            count[digit] += count[digit - 1];
        }

        // Ідемо справа наліво, щоб зберегти порядок однакових цифр.
        for (int i = n - 1; i >= 0; i--) {
            int digit = (a[i] / place) % 10;
            result[--count[digit]] = a[i];
        }

        for (int i = 0; i < n; i++) {
            a[i] = result[i];
        }
    }
    delete[] result;
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    int n, mode;
    cout << "Array size: ";
    if (!(cin >> n) || n <= 0) return 1;

    cout << "1 - Random (0-999)\n"
         << "2 - All zeros\n"
         << "3 - Ascending\n"
         << "4 - Descending\n"
         << "5 - Repeated values (0-4)\n"
         << "6 - Almost sorted\n"
         << "Choose: ";
    if (!(cin >> mode) || mode < 1 || mode > 6) return 1;

    int* a = new int[n];
    fillArray(a, n, mode);

    cout << "Before: ";
    printArray(a, n);
    radixSort(a, n);
    cout << "After:  ";
    printArray(a, n);

    delete[] a;
}
