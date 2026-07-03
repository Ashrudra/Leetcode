class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;
        
        vector<int> s1_counts(26, 0);
        vector<int> s2_counts(26, 0);
        
        for (int i = 0; i < s1.length(); i++) {
            s1_counts[s1[i] - 'a']++;
            s2_counts[s2[i] - 'a']++;
        }
        
        for (int i = 0; i < s2.length() - s1.length(); i++) {
            if (s1_counts == s2_counts) return true;
            s2_counts[s2[i + s1.length()] - 'a']++;
            s2_counts[s2[i] - 'a']--;
        }
        
        return s1_counts == s2_counts;
    }
};
