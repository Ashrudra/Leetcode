class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int index = 0;
        int i = 0;
        
        while (i < n) {
            int j = i;
            while (j < n && chars[j] == chars[i]) {
                j++;
            }
            
            chars[index++] = chars[i];
            int count = j - i;
            
            if (count > 1) {
                string s = to_string(count);
                for (char c : s) {
                    chars[index++] = c;
                }
            }
            
            i = j;
        }
        
        return index;
    }
};
