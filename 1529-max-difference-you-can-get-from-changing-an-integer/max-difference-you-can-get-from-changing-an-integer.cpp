class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        string max_s = s;
        string min_s = s;

    
        for (char &c : max_s) {
            if (c != '9') {
                char replace = c;
                for (char &x : max_s) {
                    if (x == replace) x = '9';
                }
                break;
            }
        }

      
        if (min_s[0] != '1') {
            char replace = min_s[0];
            for (char &x : min_s) {
                if (x == replace) x = '1';
            }
        } 
      
        else {
            for (int i = 1; i < min_s.size(); ++i) {
                if (min_s[i] != '0' && min_s[i] != '1') {
                    char replace = min_s[i];
                    for (char &x : min_s) {
                        if (x == replace) x = '0';
                    }
                    break;
                }
            }
        }

        return stoi(max_s) - stoi(min_s);
    }
};
