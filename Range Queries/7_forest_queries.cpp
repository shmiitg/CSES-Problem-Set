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

const int MAX = 1e3 + 5;
char v[MAX][MAX];
int pref[MAX][MAX];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> v[i][j];
    }
    memset(pref, 0, sizeof(pref));
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            pref[i][j] = (v[i][j] == '*') + (i > 0 ? pref[i - 1][j] : 0);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            pref[i][j] += pref[i][j - 1];
        }
    }
    while (q--)
    {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        y1--, x1--, y2--, x2--;
        int res = pref[y2][x2] - (x1 > 0 ? pref[y2][x1 - 1] : 0) - (y1 > 0 ? pref[y1 - 1][x2] : 0) + (y1 > 0 && x1 > 0 ? pref[y1 - 1][x1 - 1] : 0);
        cout << res << "\n";
    }
    return 0;
}