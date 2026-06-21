class Solution {
  public:
    string chooseSwap(string &s) {
         vector<int> present(26, 0);

        for(char ch : s)
            present[ch - 'a'] = 1;

        for(int i = 0; i < s.size(); i++) {
            present[s[i] - 'a'] = 0;

            for(int j = 0; j < s[i] - 'a'; j++) {
                if(present[j]) {
                    char c1 = s[i];
                    char c2 = char('a' + j);

                    for(char &ch : s) {
                        if(ch == c1)
                            ch = c2;
                        else if(ch == c2)
                            ch = c1;
                    }
                    return s;
                }
            }
        }

        return s;
        
    }
};
