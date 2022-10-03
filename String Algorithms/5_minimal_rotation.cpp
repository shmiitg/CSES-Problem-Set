#include <bits/stdc++.h>
using namespace std;
#define int long long

#define max3(a, b, c) max(max(a, b), c)
#define min3(a, b, c) min(min(a, b), c)

typedef pair<int, int> pi;

int prime = 131;
const int mod = 1e9 + 7;

int binPow(int x, int n)
{
    int res = 1;
    while (n)
    {
        if (n % 2)
        {
            res *= x;
            res %= mod;
        }
        n >>= 1;
        x *= x;
        x %= mod;
    }
    return res;
}

vector<int> calcInverse(int n)
{
    vector<int> inverse(n);
    int x = 1;
    for (int i = 0; i < n; i++)
    {
        inverse[i] = binPow(x, mod - 2);
        x *= prime;
        x %= mod;
    }
    return inverse;
}

vector<int> calcHash(string s)
{
    int n = s.size();
    int curr = 0;
    vector<int> hash(n);
    int x = 1;
    for (int i = 0; i < n; i++)
    {
        hash[i] = curr + (s[i] - 'a' + 1) * x;
        hash[i] %= mod;
        curr = hash[i];
        x *= prime;
        x %= mod;
    }
    return hash;
}

int getHash(int l, int r, vector<int> &hash, vector<int> &inverse)
{
    if (l == 0)
        return hash[r];
    int diff = hash[r] - hash[l - 1] + mod;
    diff %= mod;
    return (diff * inverse[l]) % mod;
}

void solve()
{
    string s;
    cin >> s;
    s += s;
    int idx = 0;
    int n = s.size();
    vector<int> hash = calcHash(s);
    vector<int> inverse = calcInverse(n);
    for (int i = 1; i < n / 2; i++)
    {
        if (s[i] < s[idx])
        {
            idx = i;
            continue;
        }
        // do binary search
        int lo = i, hi = i + n / 2 - 1;

        while (lo <= hi)
        {
            int m = (lo + hi) >> 1;
            int len = m - i;
            int h1 = getHash(i, i + len, hash, inverse);
            int h2 = getHash(idx, idx + len, hash, inverse);
            if (h1 == h2)
            {
                if (s[i + len + 1] < s[idx + len + 1])
                {
                    idx = i;
                    break;
                }
                else
                {
                    lo = m + 1;
                }
            }
            else
            {
                hi = m - 1;
            }
        }
    }
    cout << s.substr(idx, n / 2) << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    tc = 1;
    while (tc--)
    {
        solve();
    }
    return 0;
}