// modifying dijkstra to find longest path
// take -1 as edge weight for each edge
// fails for 1 tc in cses

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

vector<vi> adj(MAXN);
const int inf = 1e18;
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
    }
    priority_queue<pi, vector<pi>, greater<pi>> q;
    vi dist(n + 1, inf), par(n + 1, -1);
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
    vi ans;
    while (dest != -1)
    {
        ans.pb(dest);
        dest = par[dest];
    }
    if (ans.back() != 1)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }
    reverse(all(ans));
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