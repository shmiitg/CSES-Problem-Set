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

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> indegree(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        // v is dependent on u
        indegree[v]++;
        adj[u].push_back(v);
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    vector<int> ans;
    while (!q.empty())
    {
        int node = q.front();
        ans.push_back(node);
        q.pop();
        for (auto c : adj[node])
        {
            indegree[c]--;
            if (indegree[c] == 0)
            {
                q.push(c);
            }
        }
    }
    int sz = ans.size();
    if (sz < n)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }
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