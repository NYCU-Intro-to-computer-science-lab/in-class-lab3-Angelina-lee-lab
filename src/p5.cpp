#include <iostream>
#include <cmath>

using namespace std;

/**
 * 河內塔變形：線性移動 (Linear Hanoi)
 * 規則：只能在相鄰柱子間移動 (1<->2, 2<->3)，嚴格禁止 1<->3 直接移動。
 * 所有的移動都必須尊重物理限制，利用遞迴解決。
 * * n: 圓盤數量
 * from: 來源柱
 * to: 目標柱
 * aux: 輔助柱
 */
void hanoi(int n, int from, int to, int aux) {
    if (n == 0) {
        return;
    }

    // 計算柱子間的距離，判斷是否相鄰
    int dist = abs(from - to);

    if (dist == 1) {
        // --- 情況 A: 相鄰柱子移動 (如 1->2 或 2->3) ---
        // 這類似標準河內塔，只是 aux 是這兩根柱子之外的第三根
        
        // 1. 將 n-1 個圓盤從 from 移到 aux (暫存)
        hanoi(n - 1, from, aux, to);
        
        // 2. 移動最大的圓盤 n (距離為 1，合法)
        cout << "Move disk " << n << " from " << from << " to " << to << endl;
        
        // 3. 將 n-1 個圓盤從 aux 移到 to
        hanoi(n - 1, aux, to, from);

    } else {
        // --- 情況 B: 跨越移動 (1->3 或 3->1) ---
        // 必須經過中間柱子 (aux，即柱子 2) 分兩段運送
        
        // 1. 先將 n-1 堆到「目標柱」(to)，以便讓 n 能移動到中間
        hanoi(n - 1, from, to, aux);
        
        // 2. 將圓盤 n 移動到中間柱 (aux)
        cout << "Move disk " << n << " from " << from << " to " << aux << endl;
        
        // 3. 將 n-1 從「目標柱」移回「來源柱」，清空目標柱給 n 使用
        hanoi(n - 1, to, from, aux);
        
        // 4. 將圓盤 n 從中間柱 (aux) 移動到目標柱 (to)
        cout << "Move disk " << n << " from " << aux << " to " << to << endl;
        
        // 5. 最後將 n-1 從來源柱再次移動到目標柱，完成堆疊
        hanoi(n - 1, from, to, aux);
    }
}

int main() {
    int n;
    
    // 讀取圓盤數量 n
    if (cin >> n) {
        // 題目要求：印出將 n 個圓盤從 柱子 1 移動到 柱子 3 的步驟
        // 初始呼叫：from=1, to=3, aux=2
        hanoi(n, 1, 3, 2);
    }

    return 0;
}
