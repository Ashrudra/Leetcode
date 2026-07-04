class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater;
        stack<int> s;

        for (int num : nums2) {
            while (!s.empty() && num > s.top()) {
                nextGreater[s.top()] = num;
                s.pop();
            }
            s.push(num);
        }

        vector<int> result;
        for (int num : nums1) {
            if (nextGreater.count(num)) {
                result.push_back(nextGreater[num]);
            } else {
                result.push_back(-1);
            }
        }
        
        return result;
    }
};
