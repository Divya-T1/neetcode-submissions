class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> num;
        for(int x:nums) {
            int prev=num.size();
            num.insert(x);
            if(prev==num.size()) return true;
        }
        return false;
    }
};