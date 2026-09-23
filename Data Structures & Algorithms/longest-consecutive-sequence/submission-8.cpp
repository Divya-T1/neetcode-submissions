class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return 1;
        sort(nums.begin(), nums.end());
        int seq_best = -1e9;
        int curr = 1;
        for(int i=1; i<nums.size(); i++) {
            //cout<<nums[i]<<" "<<curr;
            if(nums[i]==nums[i-1]+1) {
                curr++;
            }
            else if(nums[i]!=nums[i-1]) {
                seq_best = max(seq_best, curr);
                curr = 1;
            }
            seq_best = max(seq_best, curr);
        }

        return seq_best;
    }
};
