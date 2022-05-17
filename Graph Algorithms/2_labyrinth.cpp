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

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int n, m;
int vis[1001][1001];
int par[1001][1001];
vector<string> v(1001);
string dirs = "URDL";

bool check(int i, int j)
{
    return (i >= 0 && j >= 0 && i < n && j < m && !vis[i][j] && v[i][j] != '#');
}

void solve()
{
    memset(vis, 0, sizeof(vis));
    memset(par, -1, sizeof(par));
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    queue<int> q;
    int start, end;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == 'A')
            {
                start = i * m + j;
                q.push(i * m + j);
                vis[i][j] = 1;
                break;
            }
        }
    }
    while (!q.empty())
    {
        int curr = q.front();
        int x = curr / m;
        int y = curr % m;
        q.pop();
        if (v[x][y] == 'B')
        {
            end = x * m + y;
            string res;
            while (end != start)
            {
                int x = end / m;
                int y = end % m;
                int p = par[x][y];
                res.pb(dirs[p]);
                int ex = x - dx[p];
                int ey = y - dy[p];
                end = ex * m + ey;
            }
            reverse(all(res));
            cout << "YES\n"
                 << res.size() << "\n"
                 << res;
            return;
        }
        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (check(nx, ny))
            {
                par[nx][ny] = k;
                q.push(nx * m + ny);
                vis[nx][ny] = 1;
            }
        }
    }
    cout << "NO\n";
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