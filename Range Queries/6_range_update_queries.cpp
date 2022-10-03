#include <bits/stdc++.h>
using namespace std;
#define int long long
#define max3(a, b, c) max(max(a, b), c)
#define min3(a, b, c) min(min(a, b), c)
typedef pair<int, int> pi;

const int MAX = 2e5 + 5;
int v[MAX];
int seg[4 * MAX], lazy[4 * MAX];

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

void range_update(int index, int low, int high, int l, int r, int val)
{
    if (lazy[index] != 0)
    {
        seg[index] += (high - low + 1) * lazy[index];
        if (low != high)
        {
            lazy[2 * index + 1] += lazy[index];
            lazy[2 * index + 2] += lazy[index];
        }
        lazy[index] = 0;
    }
    if (low > r || l > high || low > high)
    {
        return;
    }
    if (low >= l && high <= r)
    {
        seg[index] += (high - low + 1) * val;
        if (low != high)
        {
            lazy[2 * index + 1] += val;
            lazy[2 * index + 2] += val;
        }
        return;
    }
    int mid = low + (high - low) / 2;
    range_update(2 * index + 1, low, mid, l, r, val);
    range_update(2 * index + 2, mid + 1, high, l, r, val);
    seg[index] = seg[2 * index + 1] + seg[2 * index + 2];
}

int queryLazy(int index, int low, int high, int l, int r)
{
    if (lazy[index] != 0)
    {
        seg[index] += (high - low + 1) * (lazy[index]);
        if (low != high)
        {
            lazy[2 * index + 1] += lazy[index];
            lazy[2 * index + 2] += lazy[index];
        }
        lazy[index] = 0;
    }
    if (low > r || l > high || low > high)
    {
        return 0;
    }
    if (low >= l && high <= r)
    {
        return seg[index];
    }
    int mid = low + (high - low) / 2;
    int left = queryLazy(2 * index + 1, low, mid, l, r);
    int right = queryLazy(2 * index + 2, mid + 1, high, l, r);
    return left + right;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(lazy, 0, sizeof(lazy));
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
            int a, b, val;
            cin >> a >> b >> val;
            a--, b--;
            range_update(0, 0, n - 1, a, b, val);
        }
        else
        {
            int k;
            cin >> k;
            k--;
            cout << queryLazy(0, 0, n - 1, k, k) << "\n";
        }
    }
    return 0;
}