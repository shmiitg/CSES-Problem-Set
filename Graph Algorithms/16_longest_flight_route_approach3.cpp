#include <bits/stdc++.h>
using namespace std;
#define int long long
#define max3(a, b, c) max(max(a, b), c)
#define min3(a, b, c) min(min(a, b), c)
typedef pair<int, int> pi;

const int inf = 1e9;
const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;

vector<vector<int>> adj(maxn);
vector<int> vis(maxn), cnt(maxn, 1), child(maxn), flag(maxn);

void dfs(int node)
{
    vis[node] = 1;
    for (auto c : adj[node])
    {
        if (!vis[c])
        {
            dfs(c);
        }
        flag[node] |= flag[c];
        if (cnt[node] < cnt[c] + 1 && flag[c])
        {
            cnt[node] = cnt[c] + 1;
            child[node] = c;
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    flag[n] = 1;
    dfs(1);
    if (vis[n] == 0)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }
    vector<int> path;
    int z = 1;
    while (z != n)
    {
        path.push_back(z);
        z = child[z];
    }
    path.push_back(n);
    int len = path.size();
    cout << len << "\n";
    for (auto i : path)
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