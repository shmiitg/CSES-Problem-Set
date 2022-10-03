#include <bits/stdc++.h>
using namespace std;
#define int long long
#define max3(a, b, c) max(max(a, b), c)
#define min3(a, b, c) min(min(a, b), c)
typedef pair<int, int> pi;

const int inf = 1e18;

struct gph
{
    int cost;
    int node;
    bool taken;
};

struct comp
{
    bool operator()(gph const &g1, gph const &g2)
    {
        return g1.cost > g2.cost;
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pi>> adj(n + 1);
    vector<vector<int>> dist(n + 1, vector<int>(2));
    for (int i = 1; i <= n; i++)
    {
        dist[i][0] = dist[i][1] = inf;
    }
    // 0->not used, 1->used
    dist[1][0] = dist[1][1] = 0;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    priority_queue<gph, vector<gph>, comp> q;
    q.push({0, 1, 0});
    while (!q.empty())
    {
        gph curr = q.top();
        q.pop();
        int curr_d = curr.cost;
        int u = curr.node;
        bool taken = curr.taken;
        if (!taken && dist[u][0] < curr_d)
            continue;
        if (taken && dist[u][1] < curr_d)
            continue;
        for (auto i : adj[u])
        {
            int v = i.first;
            int d = i.second;
            if (dist[v][0] > dist[u][0] + d)
            {
                dist[v][0] = dist[u][0] + d;
                q.push({dist[v][0], v, 0});
            }
            if (dist[v][1] > min(dist[u][0] + d / 2, dist[u][1] + d))
            {
                dist[v][1] = min(dist[u][0] + d / 2, dist[u][1] + d);
                q.push({dist[v][1], v, 1});
            }
        }
    }
    cout << dist[n][1] << "\n";
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