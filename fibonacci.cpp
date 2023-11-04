
#include <iostream>

// Bad
int fib(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    
    return fib(n - 1) + fib(n - 2);
}

// Memo_table should be initialized to hold n+1 items set to -1.
int memoized_fib(int n, std::vector<int>& memo_table) {
    if (memo_table[n] != -1) {
        return memo_table[n];
    }

    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }

    memo_table[n] = fib(n - 1) + fib(n - 2);
    return memo_table[n];
}

int DP_fib(int n) {
    std::vector<int> DP (n + 1, 0);  // n+1 zeros.

    DP[0] = 0;
    DP[1] = 1;

    for (int i = 2; i <= n; i++) {
        DP[i] = DP[i-1] + DP[i-2];
    }

    return DP[n];
}

int main() {
    int a = 0;
    int b = 1;

    std::cout << "Fib(" << 0 << ") = " << 0 << '\n';
    std::cout << "Fib(" << 1 << ") = " << 1 << '\n';

    for (int i = 2; i < 20; i++) {
        int c = a + b;
        std::cout << "Fib(" << i << ") = " << c << '\n';
        a = b;
        b = c;
    }

    std::cout << DP_fib(10) << '\n';

    std::vector<int> memo_table (11, -1); 
    std::cout << memoized_fib(10, memo_table) << '\n';
}
