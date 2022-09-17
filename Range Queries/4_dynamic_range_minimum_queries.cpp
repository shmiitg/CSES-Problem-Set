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

const int MAX = 2e5 + 5;
int v[MAX];
int seg[4 * MAX];

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
    seg[index] = min(seg[2 * index + 1], seg[2 * index + 2]);
}

// range minimum query from [l,r]
int query(int index, int low, int high, int l, int r)
{
    if (low >= l && high <= r)
    {
        return seg[index];
    }
    if (l > high || r < low)
        return 1e9;
    int mid = low + (high - low) / 2;
    int left = query(2 * index + 1, low, mid, l, r);
    int right = query(2 * index + 2, mid + 1, high, l, r);
    return min(left, right);
}

void pointUpdate(int index, int low, int high, int node, int val)
{
    if (low == high)
    {
        v[node] = val;
        seg[index] = val;
        return;
    }
    int mid = low + (high - low) / 2;
    if (node <= mid)
        pointUpdate(2 * index + 1, low, mid, node, val);
    else
        pointUpdate(2 * index + 2, mid + 1, high, node, val);
    seg[index] = min(seg[2 * index + 1], seg[2 * index + 2]);
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
        int type;
        cin >> type;
        if (type == 1)
        {
            // point update
            int idx, val;
            cin >> idx >> val;
            idx--;
            pointUpdate(0, 0, n - 1, idx, val);
        }
        else
        {
            // range min query
            int l, r;
            cin >> l >> r;
            l--, r--;
            cout << query(0, 0, n - 1, l, r) << "\n";
        }
    }
    return 0;
}