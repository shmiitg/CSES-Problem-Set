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
int n, m;
vi adj[MAXN];
vi vis(MAXN), par(MAXN);

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    queue<int> q;
    q.push(1);
    vis[1] = 1;
    while (!q.empty())
    {
        int curr = q.front();
        if (curr == n)
        {
            vi ans;
            while (n != 1)
            {
                ans.pb(n);
                n = par[n];
            }
            ans.pb(1);
            reverse(all(ans));
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