class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> profit(nums.size(), 0);
        if(nums.size()==1) {
            return nums[0];
        }

        if(nums.size()==2) {
            return max(nums[0], nums[1]);
        }

        profit[0] = nums[0];
        profit[1] = max(nums[0], nums[1]);

        for(int i=2; i<nums.size(); i++) {
            int temp = nums[i]+profit[i-2];
            cout<<i<<" "<<profit[i-1]<<" "<<temp<<endl;
            profit[i] = max(profit[i-1], temp);
        }

        int maxV = 0;

        for(int num:profit) {
            if(num>maxV) maxV=num;
        }

        return maxV;

    }
};
