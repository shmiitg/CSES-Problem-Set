#include <bits/stdc++.h>
using namespace std;
#define int long long
#define max3(a, b, c) max(max(a, b), c)
#define min3(a, b, c) min(min(a, b), c)
typedef pair<int, int> pi;

const int maxn = 1e5 + 5;

int n, m;
vector<int> adj[maxn];
vector<int> vis(maxn);

void dfs(int node)
{
    vis[node] = 1;
    for (auto c : adj[node])
    {
        if (!vis[c])
            dfs(c);
    }
}
void solve()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> v;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
            v.push_back(i);
        }
    }
    int sz = v.size();
    cout << sz - 1 << "\n";
    for (int i = 1; i < sz; i++)
    {
        cout << v[i] << " " << v[i - 1] << "\n";
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