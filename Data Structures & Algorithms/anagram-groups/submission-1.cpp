class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> m;

        for(string str:strs) {
            string temp = str;
            sort(str.begin(), str.end());
            m[str].push_back(temp);
        }

        vector<vector<string>> vect;

        for(auto& [key, value]:m) {
            vect.push_back(value);
        }

        return vect;
    }
};