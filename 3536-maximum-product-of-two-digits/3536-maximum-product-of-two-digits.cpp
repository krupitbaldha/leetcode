class Solution {
public:
    void d(int n, vector<int>& v) {
        while (n > 0) {
            v[n % 10]++;
            n /= 10;
        }
    }

    int maxProduct(int n) {
        int pro = 1;
        int c = 2;
        vector<int> v(10, 0);

        d(n, v);

        for (int i = 9; i >= 0 && c > 0; i--) {
            while (v[i] > 0 && c > 0) {
                pro *= i;
                v[i]--;
                c--;
            }
        }

        return pro;
    }
};