class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int leftMax = height[left];
        int rightMax = height[right];
        int tot = 0;
        while(left<right) {
            if(height[left]<height[right]) {
                int diff = leftMax - height[left+1];
                if(diff>=0) {
                    tot+=diff;
                }
                left++;
                leftMax = max(height[left], leftMax);
            }
            
            else {
                int diff = rightMax - height[right-1];
                if(diff>=0) {
                    tot+=diff;
                }
                right--;
                rightMax = max(height[right],rightMax);
            }
        }

        return tot;
    }
};
