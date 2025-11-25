#include <iostream>

using namespace std;

/**
 * 遞迴印出縮排
 * k: 需要印出的 "|--" 數量
 * 限制：嚴格禁止使用迴圈，因此使用遞迴來重複印出
 */
void printIndent(int k) {
    if (k <= 0) {
        return;
    }
    cout << "|--";
    printIndent(k - 1);
}

/**
 * 計算費波那契數並視覺化過程
 * n: 目前要計算第幾項
 * depth: 目前的遞迴深度 (用於控制縮排)
 */
int fib(int n, int depth) {
    // 步驟 1: 進入函數時，印出縮排與 SEARCH
    printIndent(depth);
    cout << "SEARCH fib(" << n << ")" << endl;

    int result;

    // 定義 Base Cases: F(1)=1, F(2)=1
    if (n == 1 || n == 2) {
        result = 1;
    } else {
        // 步驟 2: 遞迴呼叫 (先算 n-1, 再算 n-2)
        // 深度加 1
        int left = fib(n - 1, depth + 1);
        int right = fib(n - 2, depth + 1);
        result = left + right;
    }

    // 步驟 3: 離開函數前，印出縮排與 GET 結果
    printIndent(depth);
    cout << "GET fib(" << n << ") = " << result << endl;

    return result;
}

int main() {
    int n;
    
    if (cin >> n) {
        // 從深度 0 開始計算
        int ans = fib(n, 0);
        
        // 最後一行印出最終計算結果
        cout << ans << endl;
    }

    return 0;
}
