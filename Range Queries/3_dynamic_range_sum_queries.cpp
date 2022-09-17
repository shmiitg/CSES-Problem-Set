#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1000000000
#define MOD 1000000007
#define pb push_back
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define max3(a, b, c) max(max(a, b), c)
#define min3(a, b, c) min(min(a, b), c)
#define max4(a, b, c, d) max(a, max3(b, c, d))
#define min4(a, b, c, d) min(a, min3(b, c, d))
typedef vector<int> vi;
typedef pair<int, int> pi;

const int MAXN = 200005;
int v[MAXN];
int seg[4 * MAXN]; // 4*size of array is upper bound for segment tree array

// index will be segment tree root node for build, query and pointUpdate
void build(int index, int low, int high)
{
    if (low == high)
    {
        seg[index] = v[low];
        return;
    }
    int mid = low + (high - low) / 2;
    build(2 * index + 1, low, mid);
    build(2 * index + 2, mid + 1, high);
    seg[index] = seg[2 * index + 1] + seg[2 * index + 2];
}

int query(int index, int low, int high, int l, int r)
{
    if (low >= l && high <= r)
    {
        return seg[index];
    }
    if (high < l || low > r)
        return 0;
    int mid = (low + high) / 2;
    int left = query(2 * index + 1, low, mid, l, r);
    int right = query(2 * index + 2, mid + 1, high, l, r);
    return left + right;
}

void pointUpdate(int index, int low, int high, int node, int val)
{
    if (low == high)
    {
        seg[index] = val;
        return;
    }
    int mid = (low + high) / 2;
    if (node >= low && node <= mid)
        pointUpdate(2 * index + 1, low, mid, node, val);
    else
        pointUpdate(2 * index + 2, mid + 1, high, node, val);
    seg[index] = seg[2 * index + 1] + seg[2 * index + 2];
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    build(0, 0, n - 1);
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int idx, val;
            cin >> idx >> val;
            idx--;        // 1 based indexing
            v[idx] = val; // change index to that value
            pointUpdate(0, 0, n - 1, idx, val);
        }
        else
        {
            int L, R;
            cin >> L >> R;
            L--, R--;
            cout << query(0, 0, n - 1, L, R) << "\n";
        }
    }
    return 0;
}