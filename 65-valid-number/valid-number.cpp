class Solution {
public:
    bool isNumber(string s) {
        int n = s.length();
        int i = 0;
        
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            i++;
        }
        
        bool hasDigit = false;
        bool hasDot = false;
        
        while (i < n && (isdigit(s[i]) || s[i] == '.')) {
            if (s[i] == '.') {
                if (hasDot) return false;
                hasDot = true;
            } else {
                hasDigit = true;
            }
            i++;
        }
        
        if (!hasDigit) return false;
        
        if (i < n && (s[i] == 'e' || s[i] == 'E')) {
            i++;
            if (i < n && (s[i] == '+' || s[i] == '-')) {
                i++;
            }
            bool hasExpDigit = false;
            while (i < n && isdigit(s[i])) {
                hasExpDigit = true;
                i++;
            }
            if (!hasExpDigit) return false;
        }
        
        return i == n;
    }
};