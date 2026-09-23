class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area = 0;
        vector<pair<int,int>> visited;

        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[i].size(); j++) {
                if(grid[i][j] == 1) {
                    queue<pair<int,int>> q;
                    q.push(make_pair(i,j));
                    visited.push_back(make_pair(i,j));
                    int count = 1;

                    while(!q.empty()) {
                        auto [x,y] = q.front();
                        q.pop();

                        if(x>0 && grid[x-1][y]==1 && find(visited.begin(), visited.end(), make_pair(x-1,y))==visited.end()) {
                            q.push(make_pair(x-1,y));
                            count++;
                            visited.push_back(make_pair(x-1,y));
                        }

                        if(y>0 && grid[x][y-1]==1 && find(visited.begin(), visited.end(), make_pair(x,y-1))==visited.end()) {
                            q.push(make_pair(x,y-1));
                            count++;
                            visited.push_back(make_pair(x,y-1));
                        }

                        if(x<grid.size()-1 && grid[x+1][y]==1 && find(visited.begin(), visited.end(), make_pair(x+1,y))==visited.end()) {
                            q.push(make_pair(x+1,y));
                            count++;
                            visited.push_back(make_pair(x+1,y));
                        }

                        if(y<grid[x].size()-1 && grid[x][y+1]==1 && find(visited.begin(), visited.end(), make_pair(x,y+1))==visited.end()) {
                            q.push(make_pair(x,y+1));
                            count++;
                            visited.push_back(make_pair(x,y+1));
                        }
                    }
                    
                    //cout<<area<<"\n";
                    area = max(area, count);

                }

            }
        }

        return area;
    }
};
