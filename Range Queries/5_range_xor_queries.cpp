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

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    vector<int> pref(n + 1);
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        pref[i + 1] = pref[i] ^ t;
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << (pref[l - 1] ^ pref[r]) << "\n";
    }
    return 0;
}