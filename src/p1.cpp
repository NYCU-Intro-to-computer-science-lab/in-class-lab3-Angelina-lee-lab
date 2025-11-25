#include <iostream>

using namespace std;

/**
 * Calculates the factorial of n (n!) recursively.
 * Base case: n = 0 returns 1.
 * Recursive step: n * factorial(n - 1).
 */
long long factorial(int n) {
    if (n <= 0) {
        return 1; // 0! is defined as 1
    }
    return n * factorial(n - 1);
}

/**
 * Calculates the summation of 1 to n recursively.
 * Base case: n = 0 returns 0.
 * Recursive step: n + sum(n - 1).
 */
long long sum(int n) {
    if (n <= 0) {
        return 0;
    }
    return n + sum(n - 1);
}

int main() {
    int n;
    
    // Read integer n
    if (cin >> n) {
        // Print Factorial result
        cout << factorial(n) << endl;
        
        // Print Summation result
        cout << sum(n) << endl;
    }

    return 0;
}
