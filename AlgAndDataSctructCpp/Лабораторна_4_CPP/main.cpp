// Лабораторна робота 4. Варіант 14. Сортування за розрядами.
#include <algorithm>
#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <random>
#include <stdexcept>
#include <vector>
#include "graphics.h"
using namespace std;

// Сортування невід'ємних цілих за десятковими розрядами.
void radixSort(vector<int>& a, bool draw = false) {
    if (a.empty()) return;
    for (int x : a)
        if (x < 0) throw invalid_argument("Negative number");
    int maximum = *max_element(a.begin(), a.end());
    vector<int> b(a.size());
    for (long long exp = 1; maximum / exp > 0; exp *= 10) {
        int count[10] = {};
        for (int x : a) ++count[(x / exp) % 10];

        // Знаходимо початкову позицію кожної групи цифр.
        int position = 0;
        for (int digit = 0; digit < 10; ++digit) {
            int size = count[digit];
            count[digit] = position;
            position += size;
        }

        fill(b.begin(), b.end(), -1);
        for (int i = 0; i < (int)a.size(); ++i) {
            int digit = (a[i] / exp) % 10;
            int j = count[digit]++;
            b[j] = a[i];
            if (draw) drawFrame(a, b, i, j, exp);
        }
        a.swap(b);
    }
}

// Медіана трьох запусків; копіювання та перевірка не входять у час.
double measure(const vector<int>& input) {
    vector<int> expected = input;
    sort(expected.begin(), expected.end());
    vector<double> times;
    for (int repeat = 0; repeat < 3; ++repeat) {
        vector<int> a = input;
        auto start = chrono::steady_clock::now();
        radixSort(a);
        auto finish = chrono::steady_clock::now();
        if (a != expected) throw runtime_error("Wrong result");
        times.push_back(chrono::duration<double, milli>(finish-start).count());
    }
    sort(times.begin(), times.end());
    return times[1];
}

int main() {
    try {
        mt19937 generator(14);
        uniform_int_distribution<int> value(0, 100000);
        auto makeArray = [&](int n) {
            vector<int> a(n);
            for (int& x : a) x = value(generator);
            if (n > 0) a[0] = 100000;
            return a;
        };
        // Перевірка порожнього масиву та прикладу з повторами.
        vector<int> empty;
        radixSort(empty);
        vector<int> example = {170,45,75,90,802,24,2,66,45,0};
        vector<int> sortedExample = example;
        radixSort(sortedExample);
        cout << "Sorted: ";
        for (int x : sortedExample) cout << x << ' ';
        cout << "\n\nN; time_ms\n" << fixed << setprecision(3);

        ofstream sizes("sizes.csv");
        sizes << "n;time_ms\n" << fixed << setprecision(6);
        vector<pair<double,double>> points;
        for (int n = 50000; n <= 1000000; n += 50000) {
            double t = measure(makeArray(n));
            sizes << n << ';' << t << '\n';
            cout << n << "; " << t << '\n';
            points.push_back({n,t});
        }
        sizes.close();
        saveChart(points);

        vector<int> random = makeArray(200000);
        vector<int> ascending = random;
        sort(ascending.begin(), ascending.end());
        vector<int> descending = ascending;
        reverse(descending.begin(), descending.end());
        vector<int> almost = ascending;
        uniform_int_distribution<int> index(0, 199999);
        for (int i = 0; i < 2000; ++i)
            swap(almost[index(generator)], almost[index(generator)]);
        vector<int> repeated(200000);
        for (int& x : repeated) x = (generator() % 10) * 11111;
        uniform_int_distribution<int> length(50000,1000000);
        vector<vector<int>> arrays = {ascending, descending, random,
            almost, repeated, vector<int>(200000,0), makeArray(length(generator))};
        vector<string> names = {"ascending","descending","random",
            "almost_sorted","repeated","zeros","random_N"};
        ofstream cases("cases.csv");
        cases << "case;n;time_ms\n" << fixed << setprecision(6);
        for (int i = 0; i < (int)arrays.size(); ++i) {
            double t = measure(arrays[i]);
            cases << names[i] << ';' << arrays[i].size() << ';' << t << '\n';
            cout << names[i] << ": " << arrays[i].size() << "; " << t << '\n';
        }

        beginAnimation();
        drawFrame(example, vector<int>(example.size(),-1), -1,-1,0);
        radixSort(example, true);
        drawFrame(example, example, -1,-1,-1);
        endAnimation();
        cout << "\nDone. CSV tables, chart.bmp, step.bmp, final.bmp, animation.gif created.\n";
    } catch (const exception& e) {
        cerr << e.what() << '\n';
        return 1;
    }
}
