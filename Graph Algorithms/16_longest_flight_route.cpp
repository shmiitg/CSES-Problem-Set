// modifying dijkstra to find longest path
// take -1 as edge weight for each edge
// fails for 1 tc in cses (TLE)

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define max3(a, b, c) max(max(a, b), c)
#define min3(a, b, c) min(min(a, b), c)
typedef pair<int, int> pi;

const int maxn = 2e5 + 5;
const int inf = 1e18;
vector<vector<int>> adj(maxn);

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    priority_queue<pi, vector<pi>, greater<pi>> q;
    vector<int> dist(n + 1, inf), par(n + 1, -1);
    dist[1] = 0;
    par[1] = -1;
    q.push({0, 1});
    while (!q.empty())
    {
        pi curr = q.top();
        q.pop();
        int curr_d = curr.first;
        int u = curr.second;
        if (dist[u] < curr_d)
            continue;
        for (auto v : adj[u])
        {
            if (dist[u] != inf && dist[v] > dist[u] - 1)
            {
                dist[v] = dist[u] - 1;
                q.push({dist[v], v});
                par[v] = u;
            }
        }
    }
    int dest = n;
    vector<int> ans;
    while (dest != -1)
    {
        ans.push_back(dest);
        dest = par[dest];
    }
    if (ans.back() != 1)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (auto i : ans)
        cout << i << " ";
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