#include <bits/stdc++.h>
using namespace std;
#define int long long
#define max3(a, b, c) max(max(a, b), c)
#define min3(a, b, c) min(min(a, b), c)
typedef pair<int, int> pi;

const int maxn = 1e5 + 5;

int n, m;
vector<int> adj[maxn];
vector<int> vis(maxn), par(maxn);

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
    queue<int> q;
    q.push(1);
    vis[1] = 1;
    while (!q.empty())
    {
        int curr = q.front();
        if (curr == n)
        {
            vector<int> ans;
            while (n != 1)
            {
                ans.push_back(n);
                n = par[n];
            }
            ans.push_back(1);
            reverse(ans.begin(), ans.end());
            cout << ans.size() << "\n";
            for (auto i : ans)
                cout << i << " ";
            return;
        }
        q.pop();
        for (auto c : adj[curr])
        {
            if (!vis[c])
            {
                par[c] = curr;
                q.push(c);
                vis[c] = 1;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
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