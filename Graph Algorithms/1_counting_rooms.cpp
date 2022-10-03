#include <bits/stdc++.h>
using namespace std;
#define int long long
#define max3(a, b, c) max(max(a, b), c)
#define min3(a, b, c) min(min(a, b), c)
typedef pair<int, int> pi;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int n, m;
int vis[1001][1001];
vector<string> v;

bool check(int i, int j)
{
    return (i >= 0 && j >= 0 && i < n && j < m && !vis[i][j]);
}

void dfs(int i, int j)
{
    vis[i][j] = 1;
    for (int k = 0; k < 4; k++)
    {
        int nx = dx[k] + i;
        int ny = dy[k] + j;
        if (check(nx, ny) && v[nx][ny] == '.')
        {
            dfs(nx, ny);
        }
    }
}
void solve()
{
    memset(vis, 0, sizeof(vis));
    cin >> n >> m;
    v.resize(n);
    for (auto &i : v)
        cin >> i;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == '.' && !vis[i][j])
            {
                dfs(i, j);
                cnt++;
            }
        }
    }
    cout << cnt << "\n";
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