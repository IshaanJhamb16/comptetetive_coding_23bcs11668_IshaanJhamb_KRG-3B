class Solution {
  public:
  
    // Build LPS array
    vector<int> buildLPS(string &pat) {
        int m = pat.size();
        vector<int> lps(m, 0);

        int len = 0; // longest prefix suffix
        int i = 1;

        while (i < m) {
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }

    vector<int> search(string &txt, string &pat) {
        vector<int> result;

        int n = txt.size();
        int m = pat.size();

        vector<int> lps = buildLPS(pat);

        int i = 0, j = 0;

        while (i < n) {
            if (txt[i] == pat[j]) {
                i++;
                j++;
            }

            if (j == m) {
                result.push_back(i - j);  // found match
                j = lps[j - 1];
            } 
            else if (i < n && txt[i] != pat[j]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }

        return result;
    }
};