#include <iostream>

using namespace std;

void printIndent(int k) {
    if (k <= 0) {
        return;
    }
    cout << "|--";
    printIndent(k - 1);
}

int fib(int n, int depth) {

    printIndent(depth);
  cout << "SEARCH fib(" << n << ")" << endl;

    int result;
    if (n == 1 || n == 2) {
        result = 1;
    } else {
       
        int left = fib(n - 1, depth + 1);
        int right = fib(n - 2, depth + 1);
        result = left + right;
    }
    printIndent(depth);
    cout << "GET fib(" << n << ") = " << result << endl;

    return result;
}

int main() {
    int n;
    
    if (cin >> n) {
        
        int ans = fib(n, 0);
      
        cout << ans << endl;
    }

    return 0;
}
