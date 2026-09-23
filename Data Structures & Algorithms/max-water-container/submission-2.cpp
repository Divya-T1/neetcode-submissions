class Solution {
public:
    int maxArea(vector<int>& heights) {
        //want max length
        //want max height if height is min(right,left)
        //1,7,2,5,4,7,3,6 
        int start = 0;
        int end = heights.size()-1;
        int maxA = min(heights[start],heights[end])*(end-start);

        while(start<end) {
            if(heights[start]<heights[end]) start++;
            else end--;
            maxA = max(maxA, min(heights[start],heights[end])*(end-start));
        }

        return maxA;
    }
};
