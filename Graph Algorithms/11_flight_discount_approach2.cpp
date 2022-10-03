#include <bits/stdc++.h>
using namespace std;
#define int long long
#define max3(a, b, c) max(max(a, b), c)
#define min3(a, b, c) min(min(a, b), c)

typedef pair<int, int> pi;

int n, m;
const int inf = 1e18;

vector<int> dijkstra(vector<vector<pi>> &adj, int src)
{
    vector<int> dist(n + 1, inf);
    dist[src] = 0;
    priority_queue<pi, vector<pi>, greater<pi>> q;
    q.push({0, src});
    while (!q.empty())
    {
        pi curr = q.top();
        q.pop();
        int curr_d = curr.first;
        int u = curr.second;
        if (dist[u] < curr_d)
            continue;
        for (auto c : adj[u])
        {
            int d = c.first;
            int v = c.second;
            if (dist[v] > dist[u] + d)
            {
                dist[v] = dist[u] + d;
                q.push({dist[v], v});
            }
        }
    }
    return dist;
}

struct edge
{
    int u;
    int v;
    int cost;
};
void solve()
{
    cin >> n >> m;
    vector<vector<pi>> adj1(n + 1), adj2(n + 1);
    vector<edge> edges;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj1[a].push_back({c, b});
        adj2[b].push_back({c, a});
        edges.push_back({a, b, c});
    }
    vector<int> dist1 = dijkstra(adj1, 1);
    vector<int> dist2 = dijkstra(adj2, n);
    int ans = inf;
    for (auto i : edges)
    {
        int u = i.u;
        int v = i.v;
        int cost = i.cost;
        ans = min(ans, dist1[u] + dist2[v] + cost / 2);
    }
    cout << ans << "\n";
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