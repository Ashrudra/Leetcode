class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }

        vector<int> map(128, 0);
        for (char c : t) {
            map[c]++;
        }

        int count = t.length();
        int left = 0, right = 0;
        int minLen = INT_MAX;
        int start = 0;

        while (right < s.length()) {
            if (map[s[right]] > 0) {
                count--;
            }
            map[s[right]]--;
            right++;

            while (count == 0) {
                if (right - left < minLen) {
                    minLen = right - left;
                    start = left;
                }
                map[s[left]]++;
                if (map[s[left]] > 0) {
                    count++;
                }
                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
