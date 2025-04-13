class Solution {
public:
    const int MOD = 1e9 + 7;

    long long modPower(long long base, long long exp) {
        long long result = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1)
                result = (result * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long evenPos = (n + 1) / 2;  // can take 0,2,4,6,8 -> 5 choices
        long long oddPos = n / 2;         // can take only primes -> 4 choices

        long long result = (modPower(5, evenPos) * modPower(4, oddPos)) % MOD;
        return result;
    }
};
