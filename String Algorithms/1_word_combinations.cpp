// using trie in word break type problem

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define max3(a, b, c) max(max(a, b), c)
#define min3(a, b, c) min(min(a, b), c)
typedef pair<int, int> pi;

const int mod = 1e9 + 7;

struct TrieNode
{
    TrieNode *child[26];
    bool word_end;
    TrieNode()
    {
        word_end = 0;
        memset(child, 0, sizeof(child));
    }
};

void insert(TrieNode *root, string s)
{
    for (auto i : s)
    {
        i -= 'a';
        if (!root->child[i])
        { // if there is no child node, then insert one
            root->child[i] = new TrieNode();
        }
        root = root->child[i];
    }
    root->word_end = 1;
}
bool search(TrieNode *root, string s)
{
    for (auto i : s)
    {
        i -= 'a';
        if (!root->child[i])
            return 0;
        root = root->child[i];
    }
    return root->word_end;
}

void solve()
{
    string s;
    cin >> s;
    int k;
    cin >> k;
    vector<string> v;
    for (int i = 0; i < k; i++)
    {
        string t;
        cin >> t;
        v.push_back(t);
    }
    TrieNode *root = new TrieNode();
    for (auto i : v)
    {
        insert(root, i);
    }
    int n = s.size();
    vector<int> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i < n; i++)
    {
        string t1 = s.substr(0, i);
        if (search(root, t1))
            dp[i]++;
        if (dp[i])
        {
            TrieNode *node = root;
            for (int j = i; j < n; j++)
            {
                if (!node)
                    break;
                node = node->child[s[j] - 'a'];
                if (node && node->word_end)
                {
                    dp[j + 1] += dp[i];
                    dp[j + 1] %= mod;
                }
            }
        }
    }
    cout << dp[n] << "\n";
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