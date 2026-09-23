class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> check;
        int length = 0;
        int start = 0;
        int end = 0;
        for(char c:s) {
            int curr = check.size();
            check.insert(c);
            while(check.size() == curr) {
                check.erase(s[start]);
                curr = check.size();
                check.insert(c);
                start++;
            }

            if(check.size()>length) length = check.size();
            end++;
        }

        return length;
    }
};
