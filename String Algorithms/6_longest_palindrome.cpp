#include <bits/stdc++.h>
using namespace std;
#define int long long

#define max3(a, b, c) max(max(a, b), c)
#define min3(a, b, c) min(min(a, b), c)

typedef pair<int, int> pi;

vector<int> manacher(string s)
{
    string t;
    t += "$";
    for (auto i : s)
    {
        t += "#";
        t.push_back(i);
    }
    t += "#";
    t += "@";
    int n = t.size();
    vector<int> p(n);
    int c = 0, r = 0;
    for (int i = 1; i < n - 1; i++)
    {
        int mirr = 2 * c - i;
        if (i < r)
        {
            p[i] = min(r - i, p[mirr]);
        }
        while (t[i + (1 + p[i])] == t[i - (1 + p[i])])
        {
            p[i]++;
        }
        if (i + p[i] > r)
        {
            c = i;
            r = i + p[i];
        }
    }
    return p;
}
void solve()
{
    string s;
    cin >> s;
    vector<int> p = manacher(s);
    int n = p.size();
    int st = 0;
    int currLen = 0;
    for (int i = 1; i < n - 1; i++)
    {
        if (i % 2)
        {
            // we have a # here
            int idx = i / 2;
            if (p[i] > currLen)
            {
                currLen = p[i];
                st = idx - p[i] / 2;
            }
        }
        else
        {
            // we have string character in even indexes
            int idx = i / 2 - 1;
            if (p[i] > currLen)
            {
                currLen = p[i];
                st = idx - p[i] / 2;
            }
        }
    }
    cout << s.substr(st, currLen);
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