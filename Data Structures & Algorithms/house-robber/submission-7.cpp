class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> tot(nums.size()+2,0);
        r(nums,tot,0);
        return tot[0];
    }
    
    int r(vector<int>& nums, vector<int>& tot, int n) {
        if(n>=nums.size()) {
            return 0;
        }

        tot[n] = max(nums[n]+tot[n+2], r(nums, tot, n+1));

        return tot[n];
    }
};
