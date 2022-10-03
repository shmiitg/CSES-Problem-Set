#include <bits/stdc++.h>
using namespace std;
#define int long long
#define max3(a, b, c) max(max(a, b), c)
#define min3(a, b, c) min(min(a, b), c)
typedef pair<int, int> pi;

const int mod = 1e9 + 7;
int prime = 131;

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

vector<int> calcInverse(int n)
{
    vector<int> inverse(n);
    int y = 1;
    for (int i = 0; i < n; i++)
    {
        inverse[i] = binPow(y, mod - 2);
        y *= prime;
        y %= mod;
    }
    return inverse;
}

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    // calculate hash array
    vector<int> hash = calcHash(s);
    // calculate inverse array
    vector<int> inverse = calcInverse(n);
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        int hashValue = hash[i];
        bool f = 1;
        int len = i + 1;
        for (int l = i + 1; l < n; l += len)
        {
            int currHashValue;
            int r = l + i;
            if (r < n)
            {
                currHashValue = ((hash[r] - hash[l - 1] + mod) % mod * inverse[l]) % mod;
            }
            else
            {
                int remLength = n - l - 1;
                hashValue = hash[remLength];
                currHashValue = ((hash[n - 1] - hash[l - 1] + mod) % mod * inverse[l]) % mod;
            }
            // cout << hashValue << " " << currHashValue << "\n";
            if (hashValue != currHashValue)
            {
                f = 0;
            }
        }
        if (f)
        {
            res.push_back(i + 1);
        }
    }
    for (auto i : res)
        cout << i << " ";
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