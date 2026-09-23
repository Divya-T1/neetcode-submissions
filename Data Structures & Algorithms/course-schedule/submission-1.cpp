class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, vector<int>> adj;
        for(vector<int> vect:prerequisites) {
            adj[vect[0]].push_back(vect[1]); 
        }

        vector<int> state(numCourses,0);
        for(int i=0; i<state.size(); i++) {
            if(state[i]==0) {
                if(!dfs(state,adj,i)) return false;
            }
        }

        return true;
    }

    bool dfs(vector<int>& state, map<int, vector<int>>& adj, int c) {
        if(state[c]==2) return true;
        if(state[c]==1) return false;
        else {

            state[c]=1;
            bool x = true;
            for(int i=0; i<adj[c].size(); i++) {
                if(!dfs(state,adj,adj[c][i])) x=false;
            }

            state[c]=2;

            return x;
        }
    }
};
