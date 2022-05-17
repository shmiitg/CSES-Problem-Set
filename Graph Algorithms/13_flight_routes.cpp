#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define pb push_back
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define max3(a, b, c) max(max(a, b), c)
#define min3(a, b, c) min(min(a, b), c)
typedef vector<int> vi;
typedef pair<int, int> pi;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
const int inf = 1e18;
vector<vector<pi>> adj(MAXN);
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].pb({c, b});
    }
    priority_queue<pi, vector<pi>, greater<pi>> q;
    vi vis(n + 1);
    vector<vector<int>> dist(n + 1, vi(k + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
            dist[i][j] = inf;
    }
    dist[1][1] = 0;
    q.push({0, 1});
    while (!q.empty())
    {
        pi curr = q.top();
        q.pop();
        int curr_d = curr.first;
        int u = curr.second;
        if (curr_d > dist[u][k])
            continue;
        for (auto c : adj[u])
        {
            int d = c.first;
            int v = c.second;
            if (dist[v][k] > curr_d + d)
            {
                dist[v][k] = curr_d + d;
                q.push({dist[v][k], v});
                sort(dist[v].begin(), dist[v].end());
            }
        }
    }
    for (int i = 1; i <= k; i++)
    {
        cout << dist[n][i] << " ";
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