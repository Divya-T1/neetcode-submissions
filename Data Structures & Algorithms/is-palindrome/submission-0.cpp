class Solution {
public:
    bool isPalindrome(string s) {
        string m = "";
        for(char x:s) {
            if(isalnum(x)){
                x = tolower(x);
                m = m+x;
            }
        }
        cout<<m;
        int i = 0;
        int j = m.length()-1;
        while(i<j) {

            if(m[i]==m[j]) {
                i++;
                j--;
            }

            else return false;
        }

        return true;
    }
};
