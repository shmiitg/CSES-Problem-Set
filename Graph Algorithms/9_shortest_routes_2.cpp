#include <bits/stdc++.h>
using namespace std;
#define int long long
#define max3(a, b, c) max(max(a, b), c)
#define min3(a, b, c) min(min(a, b), c)

typedef pair<int, int> pi;

const int inf = 1e18;
const int mx = 5e2 + 5;
int dist[mx][mx];

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 0; i < mx; i++)
    {
        for (int j = i + 1; j < mx; j++)
        {
            dist[i][j] = dist[j][i] = inf;
        }
    }
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = min(c, dist[a][b]);
        dist[b][a] = dist[a][b];
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        if (dist[a][b] == inf)
            dist[a][b] = -1;
        cout << dist[a][b] << "\n";
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