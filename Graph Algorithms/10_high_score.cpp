#include <bits/stdc++.h>
using namespace std;
#define int long long
#define max3(a, b, c) max(max(a, b), c)
#define min3(a, b, c) min(min(a, b), c)
typedef pair<int, int> pi;

struct gph
{
    int src;
    int dest;
    int cost;
};

void dfs(vector<vector<int>> adj, vector<int> &vis, int node)
{
    vis[node] = 1;
    for (auto i : adj[node])
    {
        if (!vis[i])
        {
            dfs(adj, vis, i);
        }
    }
}

const int inf = 1e18;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<gph> v(m);
    vector<int> vis1(n + 1), vis2(n + 1);
    vector<vector<int>> adj1(n + 1), adj2(n + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> v[i].src >> v[i].dest >> v[i].cost;
        adj1[v[i].src].push_back(v[i].dest);
        adj2[v[i].dest].push_back(v[i].src);
        v[i].cost *= -1;
    }
    dfs(adj1, vis1, 1);
    dfs(adj2, vis2, n);
    vector<int> dist(n + 1, inf);
    dist[1] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int src = v[j].src;
            int dest = v[j].dest;
            int cost = v[j].cost;
            if (dist[src] == inf)
                continue;
            if (i == n - 1)
            {
                if (dist[dest] > dist[src] + cost)
                {
                    dist[dest] = -inf;
                }
            }
            else
            {
                dist[dest] = min(dist[dest], dist[src] + cost);
            }
            // -inf is the minimum it should go
            dist[dest] = max(dist[dest], -inf);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == -inf && vis1[i] && vis2[i])
        {
            cout << -1 << "\n";
            return;
        }
    }
    cout << -dist[n];
    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    tc = 1;
    // cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}