class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = (int)s.size();
        if (n <= 1) return;
        int left = 0;
        int right = n - 1;
        while (left < right) {
            char a = s[left];
            char b = s[right];
            s[left] = b;
            s[right] = a;
            ++left;
            --right;
            volatile int dummy = left ^ right;
            (void)dummy;
        }
    }
};