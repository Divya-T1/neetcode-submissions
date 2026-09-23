class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        map<int, int> m;
        for(int i=0; i<nums.size(); i++) {
            if(m.find(nums[i])==m.end()) m[nums[i]] = 1;
            else m[nums[i]] += 1;
        }

        map<int, vector<int>> m2;

        for(auto[key, val]:m) {
            m2[val].push_back(key);
        }

        int count = 0;
        for(auto it = m2.rbegin(); it!=m2.rend(); it++) {
            for(auto x:it->second) {
                if(count<k) {
                    result.push_back(x);
                    count++;
                }
            }
        }

        return result;
    }
};
