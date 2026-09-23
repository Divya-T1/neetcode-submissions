class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> s;
        for(int n:nums) {
            if(s.count(n)==1) return true;
            s.insert(n); 
        }

        return false;
    }
};
