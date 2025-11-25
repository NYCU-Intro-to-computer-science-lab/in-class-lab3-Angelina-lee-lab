#include <iostream>

using namespace std;

/**
 * 檢查一個整數 n 是否為質數 (Prime Number)。
 * 根據題目要求：直接在函數中透過迴圈判斷，不使用篩表。
 */
bool isPrime(int n) {
    if (n <= 1) return false;
    // 檢查從 2 到根號 n 是否有因數
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    
    // 讀取偶數 n
    if (cin >> n) {
        // 哥德巴赫猜想：找出兩個質數 a, b 使得 a + b = n
        // 題目要求輸出 a 最小的一組，因此從 2 開始檢查到 n/2
        for (int i = 2; i <= n / 2; ++i) {
            // 檢查 i 是否為質數，且 n - i 是否也為質數
            if (isPrime(i) && isPrime(n - i)) {
                cout << i << " " << (n - i) << endl;
                break; // 找到第一組 (a 最小) 即停止
            }
        }
    }

    return 0;
}
