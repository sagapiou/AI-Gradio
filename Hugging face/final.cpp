
#include <iostream>
#include <chrono>
#include <random>

using namespace std;

const int ITERATIONS = 100000000;
const double PARAM1 = 4.0;
const double PARAM2 = 1.0;

int main() {
    chrono::time_point<chrono::high_resolution_clock> start, end;
    start = chrono::high_resolution_clock::now();
    double result = calculate(ITERATIONS, PARAM1, PARAM2) * 4.0;
    end = chrono::high_resolution_clock::now();

    cout << "Result: " << fixed << setprecision(12) << result << endl;
    cout << "Execution Time: " << chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000000.0 << " seconds" << endl;

    return 0;
}

double calculate(int iterations, double param1, double param2) {
    double result = 1.0;
    for (int i = 1; i <= iterations; ++i) {
        double j = i * param1 - param2;
        result -= (1 / j);
        j = i * param1 + param2;
        result += (1 / j);
    }
    return result;
}