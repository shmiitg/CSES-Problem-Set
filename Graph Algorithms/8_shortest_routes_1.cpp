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

const int mx = 1e5 + 5;
const int inf = 1e18;
int n, m;
vector<pi> adj[mx];
vi dist(mx, inf);

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, d;
        cin >> a >> b >> d;
        adj[a].pb({b, d});
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