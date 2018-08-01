#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <unordered_map>
#include <ctime>
using namespace std;

long increament(long x) {
    return x + 1;
}

long fibonacci(long x) {
    if (x < 2) {
        return x;
    }
    return fibonacci(x-1) + fibonacci(x-2);
}

int main()
{
    clock_t start, end;
    long result;
    result = 0;
    start = clock();
    result = fibonacci(40);
    end = clock();
    cout << result << endl;
    cout << (end - start) / double(CLOCKS_PER_SEC) << "s" << endl;
    return 0;
}