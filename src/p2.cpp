#include <iostream>

using namespace std;

/**
 * 使用歐幾里得演算法 (Euclidean Algorithm) 計算最大公因數。
 * 遞迴關係: gcd(a, b) = gcd(b, a % b)
 * 終止條件 (Base case): 當 b 為 0 時，回傳 a。
 */
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int a, b;
    
    // 讀取兩個整數 a 和 b
    if (cin >> a >> b) {
        // 計算並輸出最大公因數 Result
        cout << gcd(a, b) << endl;
    }

    return 0;
}
