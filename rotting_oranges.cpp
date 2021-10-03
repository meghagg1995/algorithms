/*
  Time Complexity: O(m*n)
  Space Complexity: O(m*n) ~ All rotten oranges
*/

#include <queue>
using namespace std;

class Node {
public:
    int x;
    int y;
    int time;
    Node(int x, int y, int time) : x{x}, y{y}, time{time} {}
};

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

class Solution {
public:
    bool check(int x, int y, int m, int n) {
        if(x>=0 && y>=0 && x<m && y<n) {
            return true;
        }
        return false;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int m = grid.size();
        int n = grid[0].size();
        int c = 0;
        int t = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++) {
                if(grid[i][j] == 2) {
                    q.push(make_pair(i,j));
                } else if(grid[i][j] == 1){
                    c++;
                }
            }
        }
        if(c==0) return 0;
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                pair<int,int> curr = q.front();
                q.pop();
                for(int i=0;i<4;i++) {
                    int nx = curr.first + dx[i];
                    int ny = curr.second + dy[i];
                    if(check(nx, ny, m, n) && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        q.push(make_pair(nx, ny));
                        c--;
                    }
                }
            }
            t++;
        }
        if(c!=0) return -1;
        return t-1;
    }
    int _orangesRotting(vector<vector<int>>& grid) {
        queue<Node> q;
        int m = grid.size();
        int n = grid[0].size();
        int c = 0;
        int t = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++) {
                if(grid[i][j] == 2) {
                    Node _n(i,j,0);
                    q.push(_n);
                } else if(grid[i][j] == 1){
                    c++;
                }
            }
        }
        while(!q.empty()) {
            Node curr = q.front();
            q.pop();
            t = max(t, curr.time);
            for(int i=0;i<4;i++) {
                int nx = curr.x + dx[i];
                int ny = curr.y + dy[i];
                if(check(nx, ny, m, n) && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    Node _n(nx,ny,curr.time+1);
                    q.push(_n);
                    c--;
                }
            }
        }
        if(c!=0) return -1;
        return t;
    }
};
