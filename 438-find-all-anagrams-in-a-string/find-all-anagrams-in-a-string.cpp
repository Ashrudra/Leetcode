class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if (s.size() < p.size()) return res;
        vector<int> pCount(26, 0), sCount(26, 0);
        for (int i = 0; i < p.size(); i++) {
            pCount[p[i] - 'a']++;
            sCount[s[i] - 'a']++;
        }
        if (pCount == sCount) res.push_back(0);
        for (int i = p.size(); i < s.size(); i++) {
            sCount[s[i] - 'a']++;
            sCount[s[i - p.size()] - 'a']--;
            if (pCount == sCount) res.push_back(i - p.size() + 1);
        }
        return res;
    }
};
