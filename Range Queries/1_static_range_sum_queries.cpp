#include <bits/stdc++.h>
using namespace std;
#define int long long
#define max3(a, b, c) max(max(a, b), c)
#define min3(a, b, c) min(min(a, b), c)

typedef pair<int, int> pi;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    for (int i = 1; i < n; i++)
    {
        v[i] += v[i - 1];
    }
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        int st = a > 0 ? v[a - 1] : 0;
        int ed = v[b];
        cout << ed - st << "\n";
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