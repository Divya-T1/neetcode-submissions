class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> remain(nums.size(), 1e9);

        for(int i=0; i<nums.size(); i++) {
            if(find(remain.begin(), remain.end(), nums[i])==remain.end()) 
                remain[i] = target-nums[i];
            else {
                vector<int> fin;
                fin.push_back(i);
                int index = find(remain.begin(), remain.end(), nums[i])-remain.begin();
                cout<<i<<" "<<nums[i]<<" "<<index;
                fin.push_back(index);
                sort(fin.begin(), fin.end());
                return fin;
            }
        }

        return {};
    }
};
