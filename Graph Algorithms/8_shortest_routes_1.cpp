#include <bits/stdc++.h>
using namespace std;
#define int long long
#define max3(a, b, c) max(max(a, b), c)
#define min3(a, b, c) min(min(a, b), c)

typedef pair<int, int> pi;

const int mx = 1e5 + 5;
const int inf = 1e18;
int n, m;
vector<pi> adj[mx];
vector<int> dist(mx, inf);

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, d;
        cin >> a >> b >> d;
        adj[a].push_back({b, d});
    }
    priority_queue<pi, vector<pi>, greater<pi>> q;
    q.push({0, 1});
    dist[1] = 0;
    while (!q.empty())
    {
        pi curr = q.top();
        q.pop();
        int curr_d = curr.first;
        int u = curr.second;
        if (dist[u] < curr_d)
            continue;
        for (auto i : adj[u])
        {
            int v = i.first;
            int d = i.second;
            if (dist[v] > dist[u] + d)
            {
                dist[v] = dist[u] + d;
                q.push({dist[v], v});
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }
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