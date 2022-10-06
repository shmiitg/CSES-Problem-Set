// Toplogical sort to find longest path in a DAG

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define max3(a, b, c) max(max(a, b), c)
#define min3(a, b, c) min(min(a, b), c)
typedef pair<int, int> pi;

const int inf = 1e9;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;

vector<vector<int>> adj(maxn);
vector<int> vis(maxn), cnt(maxn), par(maxn);

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
    int n, m;
    cin >> n >> m;
    vector<int> indegree(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        indegree[v]++;
        adj[u].push_back(v);
    }
    dfs(1);
    if (vis[n] == 0)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    cnt[1] = 1;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto c : adj[node])
        {
            if (cnt[c] < cnt[node] + 1 && cnt[node])
            {
                cnt[c] = cnt[node] + 1;
                par[c] = node;
            }
            indegree[c]--;
            if (indegree[c] == 0)
            {
                q.push(c);
            }
        }
    }
    cout << cnt[n] << "\n";
    int z = n;
    vector<int> path;
    while (z)
    {
        path.push_back(z);
        z = par[z];
    }
    reverse(path.begin(), path.end());
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