/*input
4 4 7
0 1
0 2
1 2
2 0
2 1
2 3
3 2
*/
#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define MAX 2010

struct Edge {
    int from, to, cap, flow;
};

struct Dicnic {
    int n, m, s, t, ans;
    vector<Edge> edges;
    vector<int> g[MAX];
    bool vis[MAX];
    int d[MAX], cur[MAX];
    
    void init(int n) {
        this -> ans = 0;
        this -> n = n;
        for (int i = 0; i <= n; i++) g[i].clear();
        edges.clear();
    }
    
    void addedges(int from, int to, int cap, int flo) {
        edges.push_back((Edge){from, to, cap, 0});
        edges.push_back((Edge){to, from, 0, 0});
        m = (int) edges.size();
        g[from].push_back(m - 2);
        g[to].push_back(m - 1);
    }
    
    bool bfs() {
        memset(vis, 0, sizeof(vis));
        queue<int> q;
        q.push(s);
        d[s] = 0; vis[s] = 1;
        
        while (!q.empty()) {
            int now = q.front(); q.pop();
            for (int i = 0; i < g[now].size(); i++) {
                Edge& e = edges[g[now][i]];
                
                if (!vis[e.to] && e.cap > e.flow) {
                    vis[e.to] = true;
                    d[e.to] = d[now] + 1;
                    q.push(e.to);
                }
            }
        }
        return vis[t];
    }
    
    int dfs(int now, int a) {
        if (now == t || a == 0) return a;
        
        int ans = 0, f = 0;
        for (int& i = cur[now]; i < g[now].size(); i++) {
            Edge& e = edges[g[now][i]];
            
            if (d[now] + 1 == d[e.to] && (f = dfs(e.to, min(a, e.cap - e.flow))) > 0) {
                e.flow += f;
                edges[g[now][i] ^ 1].flow -= f;
                ans += f;
                a -= f;
                if (a == 0) break;
            }
        }
        return ans;
    }
    
    int MaxFlow(int s, int t) {
        this -> s = s;
        this -> t = t;
        
        while (bfs()) {
            memset(cur, 0, sizeof(cur));
            ans += dfs(s, INF);
        }
        return ans;
    }
} solver;

int main() {
    cin.tie(0), cout.sync_with_stdio(false);

    int n, m, e;
    
    cin >> n >> m >> e;
    solver.init(n + m + 2);
    for (int i = 0; i < n; i++) solver.addedges(n + m + 1, i, 1, 0);
    for (int i = 0; i < m; i++) solver.addedges(n + i, n + m + 2, 1, 0);

    while (e--) {
        int x, y; cin >> x >> y;

        solver.addedges(x, n + y, 1, 0);
        cout << solver.MaxFlow(n + m + 1, n + m + 2) << '\n';
    }
    
    return 0;
}