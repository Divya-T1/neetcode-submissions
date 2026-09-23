class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> vals;
        int currSum = 0;
        int minI = 0;
        int maxI = 0;
        int maxV = -1e9;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]<0 && currSum+nums[i]<0) {
                vals.push_back(currSum+nums[i]);
                if(currSum+nums[i]>maxV) {
                    // minI = i;
                    // maxI = i;
                    maxV = currSum+nums[i];
                }
                currSum = 0;
            }

            else {
                vals.push_back(currSum+nums[i]);
                if(currSum+nums[i]>maxV) {
                    maxV=currSum+nums[i];
                }
                currSum+=nums[i];
            }
        }

        for(int i:vals){
            cout<<i<<", ";
        }

        return maxV;
    }
};
