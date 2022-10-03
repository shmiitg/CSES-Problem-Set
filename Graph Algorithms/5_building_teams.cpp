#include <bits/stdc++.h>
using namespace std;
#define int long long
#define max3(a, b, c) max(max(a, b), c)
#define min3(a, b, c) min(min(a, b), c)
typedef pair<int, int> pi;

const int maxn = 1e5 + 5;

int n, m;
vector<int> adj[maxn];
vector<int> vis(maxn), col(maxn);

bool dfs(int node, int c)
{
    vis[node] = 1;
    col[node] = c + 1;
    for (auto i : adj[node])
    {
        if (!vis[i])
        {
            if (!dfs(i, c ^ 1))
                return 0;
        }
        else
        {
            if (col[node] == col[i])
                return 0;
        }
    }
    return 1;
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
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (!dfs(i, 0))
            {
                cout << "IMPOSSIBLE\n";
                return;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << col[i] << " ";
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