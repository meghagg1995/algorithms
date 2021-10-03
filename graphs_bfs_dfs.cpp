#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

/* O(V^2) */
class Graph {
    public:
    int** graph;
    int V;
    int E;
    Graph(int V) {
        this->V = V;
        this->E = 0;
        graph = new int*[V];
        for(int i=0;i<V;i++) {
            graph[i] = new int[V];
            for(int j=0;j<V;j++) {
                graph[i][j] = 0;
            }
        }
    }
    void addEdge(int x, int y, bool directed = false) {
        E = E + 1;
        graph[x][y] = 1;
        if(!directed) {
            graph[y][x] = 1;
        }
    }
    void display() {
        for(int i=0;i<V;i++) {
            cout << i << " : ";
            for(int j=0;j<V;j++) {
                if(graph[i][j] == 1) {
                    cout << j << " ";
                }
            }
            cout << endl;
        }
    }
    void _bfs() {
        unordered_map<int, bool> m;
        for(int i=0;i<V;i++) {
            if(m.find(i) == m.end()) {
                bfs(i, m);
            }
        }
    }
    void bfs(int sv, unordered_map<int, bool>& visited) {
        queue<int> q;
        q.push(sv);
        visited[sv] = true;
        while(!q.empty()) {
            int current = q.front();
            q.pop();
            cout << current << " ";
            for(int i=0;i<V;i++) {
                if(graph[current][i] == 1 && visited.find(i) == visited.end()) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    } 
    void _dfs() {
        unordered_map<int, bool> m;
        for(int i=0;i<V;i++) {
            if(m.find(i) == m.end()) {
                dfs(i, m);
            }
        }
    }
    void dfs(int sv, unordered_map<int, bool>& visited) {
        visited[sv] = true;
        cout << sv << " ";
        for(int i=0;i<V;i++) {
            if(graph[sv][i] == 1 && visited.find(i) == visited.end()) {
                dfs(i, visited);
            }
        }
    }
};

/* O(V + 2E) ~ O(V + E) */
class Graph {
    public:
    int V;
    int E;
    list<int>* graph;
    Graph(int V) {
        this->V = V;
        this->E = 0;
        graph = new list<int>[V];
    }
    void addEdge(int x, int y, bool directed = false) {
        E = E + 1;
        graph[x].push_back(y);
        if(!directed) {
            graph[y].push_back(x);
        }
    }
    void display() {
        for(int i=0;i<V;i++) {
            cout << i << " : ";
            for(int v : graph[i]) {
                cout << v << " ";
            }
            cout << endl;
        }
    }
    /* O(V + E) */
    void _bfs() {
        bool* visited = new bool[V];
        for(int i=0;i<V;i++) {
            visited[i] = false;
        }
        for(int i=0;i<V;i++){
            if(visited[i] == false) {
                bfs(i, visited);
            }
        }
        delete [] visited;
    }
    void bfs(int sv, bool* visited) {
        queue<int> q;
        q.push(sv);
        visited[sv] = true;
        while(!q.empty()) {
            int current = q.front();
            q.pop();
            cout << current << " ";
            for(int v : graph[current]) {
                if(!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }  
    }
    void _dfs() {
        bool* visited = new bool[V];
        for(int i=0;i<V;i++) {
            visited[i] = false;
        }
        for(int i=0;i<V;i++){
            if(!visited[i]) {
                dfs(i, visited);
            }
        }
        delete [] visited;
    }
    void dfs(int sv, bool* visited) {
        cout << sv << " ";
        visited[sv] = true;
        for(int v : graph[sv]) {
            if(!visited[v]) {
                dfs(v, visited);
            }
        }
    }
};

class SGraph {
    public:
    int V;
    int E;
    unordered_map<string, list<pair<string, int> > > graph;
    SGraph(int V) {
        this->V = V;
        this->E = 0;
    }
    void addEdge(string x, string y, int weight, bool directed = false) {
        E = E + 1;
        graph[x].push_back(make_pair(y, weight));
        if(!directed) {
            graph[y].push_back(make_pair(x, weight));
        }
    }
    void display() {
        for(auto it = graph.begin();it!=graph.end();it++) {
            cout << it->first << " : ";
            for(pair<string, int> p : it->second) {
                cout << "(" << p.first << "," << p.second << ") ";
            }
            cout << endl;
        }
    }
};

int main() {
    int V, E;
    cin >> V >> E;
    Graph g(V);
    for(int i=0;i<E;i++){
        int x, y;
        cin >> x >> y;
        g.addEdge(x, y, false);
    }
    g._dfs();
    SGraph sg(6);
	sg.addEdge("A", "B", 10, false);
	sg.addEdge("B", "D", 5, false);
	sg.addEdge("C", "A", 12, false);
	sg.display();
}
