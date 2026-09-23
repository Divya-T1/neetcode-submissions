class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> time(grid.size(), vector<int>(grid[0].size(), 1e9));
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j] == 2) {
                    vector<pair<int, int>> old;

                    queue<pair<int,int>> q;
                    q.push(make_pair(i, j));
                    time[i][j] = 0;

                    while(!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();
                        if(x!=0 && grid[x-1][y]==1 && find(old.begin(), old.end(), make_pair(x-1, y))==old.end()) {
                            if(time[x-1][y]>1 + time[x][y]) time[x-1][y] = 1 + time[x][y];
                            q.push(make_pair(x-1,y));
                            old.push_back(make_pair(x-1, y));
                        }

                        if(x!=grid.size()-1 && grid[x+1][y]==1 && find(old.begin(), old.end(), make_pair(x+1, y))==old.end()) {
                            if(time[x+1][y]>  1 + time[x][y]) time[x+1][y] = 1 + time[x][y];
                            q.push(make_pair(x+1,y));
                            old.push_back(make_pair(x+1, y));
                        }

                        if(y!=0 && grid[x][y-1]==1 && find(old.begin(), old.end(), make_pair(x, y-1))==old.end()) {
                            if(time[x][y-1]>1 + time[x][y]) time[x][y-1] = 1 + time[x][y];
                            q.push(make_pair(x,y-1));
                            old.push_back(make_pair(x, y-1));
                        }

                        if(y!=grid[0].size()-1 && grid[x][y+1]==1 && find(old.begin(), old.end(), make_pair(x, y+1))==old.end()) {
                            if(time[x][y+1]>1 + time[x][y]) time[x][y+1] = 1 + time[x][y];
                            q.push(make_pair(x,y+1));
                            old.push_back(make_pair(x, y+1));
                        }

                    }
                }
            }
        }
        
        int maxV = 0;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j]==1 && time[i][j]==1e9) {
                    cout<<i<<" "<<j<<endl;
                    return -1;
                }
                else {
                    if(time[i][j]!=1e9 && time[i][j]>maxV) {
                        maxV = time[i][j];
                    }
                }
            }
        }

        return maxV;
    }
};
