#include <bits/stdc++.h>
using namespace std;
#define int long long
#define max3(a, b, c) max(max(a, b), c)
#define min3(a, b, c) min(min(a, b), c)
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