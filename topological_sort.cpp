#include <unordered_map>
#include <queue>

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    /*
    	unordered_map<int, list<int>> graph; O(N)
        vector<vector<int>> graph;  O(V)
        int** graph; O(V)
    */
    unordered_map<int, vector<int>> graph;
    vector<int> dependency(v, 0);
    vector<bool> visited(v, false);
    for(int i=0;i<e;i++) {
        graph[edges[i][0]].push_back(edges[i][1]);
        dependency[edges[i][1]] += 1;
    }
    queue<int> q;
    for(int i=0;i<v;i++) {
        if(dependency[i] == 0) {
            q.push(i);
            visited[i] = true;
        }
    }
    vector<int> ans;
    while(!q.empty()) {
        int current = q.front();
        q.pop();
        ans.push_back(current);
        for(int v : graph[current]) {
            if(!visited[v]) {
                dependency[v]--;
                if(dependency[v] == 0) {
                    q.push(v);
                    visited[v] = true;
                }
            }
        }
    }
    return ans;
}
