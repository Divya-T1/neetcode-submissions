class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size();
        int mid = high/2;
        int count = 0;
        while(count<nums.size()) {
            if(nums[mid]==target) return mid;
            else {
                if(nums[mid]>target) high = mid;
                else low = mid;
                mid = (high+low)/2;
            }

            count++;
        }

        return -1;
    }
};
