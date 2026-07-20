class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int sum = 0, k = 0;
        while (sum < target || (sum - target) % 2 != 0) {
            k++;
            sum += k;
        }
        return k;
    }
};
