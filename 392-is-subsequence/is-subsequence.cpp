class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size(), m = t.size();
        if (!n) return true;
        if (m < n) return false;

        vector<array<int, 26>> nextPos(m + 2);
        for (int c = 0; c < 26; ++c) nextPos[m][c] = nextPos[m + 1][c] = -1;
        for (int i = m - 1; i >= 0; --i) {
            nextPos[i] = nextPos[i + 1];
            nextPos[i][t[i] - 'a'] = i;
        }

        int idx = 0, pos = 0;
        while (idx < n) {
            int c = s[idx] - 'a';
            if (pos > m) return false;
            int nxt = nextPos[pos][c];
            if (nxt == -1) return false;
            pos = nxt + 1;
            ++idx;
        }
        return true;
    }
};