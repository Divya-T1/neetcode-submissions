class Solution {
public:
    bool isValid(string s) {
        stack<char> s1;
        if(s.length()==0) return true;
        //if(s[0]==')' || s[0]==']' || s[0]=='}') return false;
        int i = 0;
        while(i<s.length()) {
            char s2 = s[i];
            if(s2=='(' || s2=='[' || s2=='{') s1.push(s2);
            else {
                if(!s1.empty()) {
                    if(s2==')' && s1.top()=='(') s1.pop();
                    else if(s2==']' && s1.top()=='[') s1.pop();
                    else if(s2=='}' && s1.top()=='{') s1.pop();
                    else return false;
                }
                else s1.push(s[i]);
                
            }
            i++;
        }

        if(s1.empty()) return true;
        return false;
    }
};
