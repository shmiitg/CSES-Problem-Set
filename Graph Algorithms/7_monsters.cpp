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

const int mx = 1e3 + 5;
int st, ed;
vector<string> str(mx);
int d[] = {-1, 0, 1, 0, -1};
string dirs = "URDL";
int vis[mx][mx];
int dist[mx][mx];
int par[mx][mx];

int n, m;
bool check(int x, int y)
{
    return (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && str[x][y] != '#');
}

bool bfs(int node)
{
    memset(vis, 0, sizeof(vis));
    int x = node % mx;
    int y = node / mx;
    vis[x][y] = 1;
    queue<pi> q;
    q.push({node, 0});
    while (!q.empty())
    {
        pi curr = q.front();
        q.pop();
        int nd = curr.first;
        int c_dist = curr.second;
        int x = nd % mx;
        int y = nd / mx;
        if (x == 0 || y == 0 || x == n - 1 || y == m - 1)
        {
            ed = x + y * mx;
            return 1;
        }
        for (int i = 0; i < 4; i++)
        {
            int dx = d[i] + x;
            int dy = d[i + 1] + y;
            if (check(dx, dy) && (dist[dx][dy] == -1 || dist[dx][dy] > c_dist + 1))
            {
                vis[dx][dy] = 1;
                q.push({dx + dy * mx, c_dist + 1});
                par[dx][dy] = i;
            }
        }
    }
    return 0;
}
void solve()
{
    cin >> n >> m;
    memset(vis, 0, sizeof(mx));
    memset(dist, -1, sizeof(dist));
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        cin >> str[i];
        for (int j = 0; j < m; j++)
        {
            if (str[i][j] == 'A')
                st = i + j * mx;
            else if (str[i][j] == 'M')
            {
                q.push(i + j * mx);
                dist[i][j] = 0;
                vis[i][j] = 1;
            }
        }
    }
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        int x = curr % mx;
        int y = curr / mx;
        for (int i = 0; i < 4; i++)
        {
            int dx = x + d[i];
            int dy = y + d[i + 1];
            if (check(dx, dy))
            {
                vis[dx][dy] = 1;
                dist[dx][dy] = dist[x][y] + 1;
                q.push(dx + dy * mx);
            }
        }
    }
    if (!bfs(st))
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    string res;
    while (ed != st)
    {
        int x = ed % mx;
        int y = ed / mx;
        int p = par[x][y];
        res.pb(dirs[p]);
        x += -d[p];
        y += -d[p + 1];
        ed = x + y * mx;
    }
    cout << res.size() << "\n";
    reverse(res.begin(), res.end());
    cout << res;
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