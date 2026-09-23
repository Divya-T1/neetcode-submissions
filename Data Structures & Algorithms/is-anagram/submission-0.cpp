class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> m1;
        map<char, int> m2;

        for(char c : s) {
            if(m1.count(c)>0) m1[c]++;
            else m1[c]=0;
        }

        for(char c : t) {
            if(m2.count(c)>0) m2[c]++;
            else m2[c]=0;
        }

        return m1==m2;
    }
};
