class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(), 0);
        int zero = count(nums.begin(), nums.end(), 0);
        if(zero>1) return result;
        if(zero==1) {
            int idx = 0;
            int prod = 1;
            for(int i=0; i<nums.size(); i++) {
                if(nums[i]==0) {
                    idx = i;
                }
                else prod*=nums[i];
            }
            result[idx] = prod;
        }

        else {
            int prod = 1;
            for(int i=0; i<nums.size(); i++) {
                prod*=nums[i];
            }

            for(int i=0; i<nums.size(); i++) {
                result[i] = prod/nums[i];
            }
            
        }

        return result;
    }
};
