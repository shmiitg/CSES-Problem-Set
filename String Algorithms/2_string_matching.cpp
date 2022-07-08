// kmp algorithm

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

vector<int> construct_pi(string s)
{
    int n = s.size();
    vector<int> pi(n);
    for (int i = 1; i < n; i++)
    {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
        {
            j = pi[j - 1];
        }
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

void solve()
{
    string text, s;
    cin >> text >> s;
    // search s in text
    string str = s + "#" + text;
    int n = str.size();
    vector<int> pi = construct_pi(str);
    // if we get a prefix value equal to len(s) after the "#", we have found the string s in text
    int sz = s.size();
    int cnt = 0;
    for (int i = sz; i < n; i++)
    {
        // the indexes where t is found is i- (sz + 1) - sz + 1
        if (pi[i] == sz)
        {
            cnt++;
        }
    }
    cout << cnt;
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