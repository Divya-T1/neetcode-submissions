class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> sum = {};
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-1; i++) {
            int rem = -1*nums[i];
            vector<int> num = {};
            for(int j=i+1; j<nums.size();j++) {
                if(find(num.begin(),num.end(), rem-nums[j])!=num.end()) {
                    sum.insert({nums[i],nums[j],rem-nums[j]});
                }

                num.push_back(nums[j]);
            }
        }

        vector<vector<int>> ans(sum.begin(),sum.end());
        return ans;
    }
};
