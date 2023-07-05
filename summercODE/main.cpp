#include <bits/stdc++.h>
using namespace std;


int shortestBridge(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int ans = 0;
    queue<pair<int,int>> q;
    vector<vector<int>> vis(n,vector<int>(m,0));
    vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
    bool flag = false;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1){
                //don't use dfs here
//dfs will not give shortest path
                queue<pair<int,int>> q;
                q.push({i,j});
                vis[i][j] = 1;
                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for(int k=0;k<4;k++){
                        int nx = x + dir[k][0];
                        int ny = y + dir[k][1];
                        if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]==1 && vis[nx][ny]==0){
                            vis[nx][ny] = 1;
                            q.push({nx,ny});
                        }
                    }
                }
                flag = true;
                break;
            }
        }
        if(flag) break;
    }
    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int nx = x + dir[k][0];
                int ny = y + dir[k][1];
                if(nx>=0 && ny>=0 && nx<n && ny<m && vis[nx][ny]==0){
                    if(grid[nx][ny]==1) return ans;
                    vis[nx][ny] = 1;
                    q.push({nx,ny});
                }
            }
        }
        ans++;
    }
    return ans;
}