#include <bits/stdc++.h>
using namespace std;
#define int long long
#define max3(a, b, c) max(max(a, b), c)
#define min3(a, b, c) min(min(a, b), c)
typedef pair<int, int> pi;

const int MAXN = 1e5 + 5;

vector<int> adj[MAXN];
vector<int> vis(MAXN), par(MAXN, -1);
int n, m;
int st, ed;

// cycle detection
bool cycle(int node, int parent)
{
    vis[node] = 1;
    for (auto c : adj[node])
    {
        if (!vis[c])
        {
            par[c] = node;
            if (cycle(c, node))
                return 1;
        }
        else
        {
            if (parent != c)
            {
                st = c;
                ed = node;
                return 1;
            }
        }
    }
    return 0;
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
            if (cycle(i, -1))
            {
                vector<int> v;
                v.push_back(st);
                while (ed != st)
                {
                    v.push_back(ed);
                    ed = par[ed];
                }
                v.push_back(ed);
                cout << v.size() << "\n";
                for (auto i : v)
                    cout << i << " ";
                return;
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