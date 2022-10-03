#include <bits/stdc++.h>
using namespace std;
#define int long long

#define max3(a, b, c) max(max(a, b), c)
#define min3(a, b, c) min(min(a, b), c)

typedef pair<int, int> pi;

vector<int> v;
map<int, int> mp, index_val;
vector<int> ans;

// build merge sort tree
void build_merge_tree(int index, int low, int high, vector<vector<int>> &seg)
{
    if (low == high)
    {
        seg[index].push_back(v[low]);
        return;
    }
    int mid = low + (high - low) / 2;
    build_merge_tree(2 * index + 1, low, mid, seg);
    build_merge_tree(2 * index + 2, mid + 1, high, seg);
    merge(seg[2 * index + 1].begin(), seg[2 * index + 1].end(),
          seg[2 * index + 2].begin(), seg[2 * index + 2].end(),
          back_inserter(seg[index]));
}

// query the count of elements
int query_cnt(int index, int low, int high, int l, int r, vector<vector<int>> &seg, int k)
{
    if (l > high || r < low)
        return 0;
    if (l <= low && r >= high)
    {
        return upper_bound(seg[index].begin(), seg[index].end(), k) - seg[index].begin();
    }
    int mid = low + (high - low) / 2;
    int left = query_cnt(2 * index + 1, low, mid, l, r, seg, k);
    int right = query_cnt(2 * index + 2, mid + 1, high, l, r, seg, k);
    return left + right;
}

// build segment tree
void build_seg_tree(int index, int low, int high, vector<int> &seg, int type)
{
    if (low == high)
    {
        seg[index] = v[low];
        return;
    }
    int mid = low + (high - low) / 2;
    build_seg_tree(2 * index + 1, low, mid, seg, type);
    build_seg_tree(2 * index + 2, mid + 1, high, seg, type);
    if (type)
        seg[index] = max(seg[2 * index + 1], seg[2 * index + 2]);
    else
        seg[index] = min(seg[2 * index + 1], seg[2 * index + 2]);
}

// query the max and min value in range [l,r]
int query(int index, int low, int high, int l, int r, vector<int> &seg, int type)
{
    if (low >= l && high <= r)
    {
        return seg[index];
    }
    if (l > high || r < low)
    {
        if (type)
            return -1e9;
        else
            return 1e9;
    }
    int mid = low + (high - low) / 2;
    int left = query(2 * index + 1, low, mid, l, r, seg, type);
    int right = query(2 * index + 2, mid + 1, high, l, r, seg, type);
    if (type)
        return max(left, right);
    else
        return min(left, right);
}

int get_median(int low, int high, int l, int r, int n, vector<vector<int>> &seg)
{
    // get length of vector from range [l,r]
    int len = query_cnt(0, 0, n - 1, l, r, seg, n);
    // cout << "len: " << len << "\n";
    int res = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int count = query_cnt(0, 0, n - 1, l, r, seg, mid);
        // cout << "count: " << count << endl;
        int req = len / 2 + 1;
        if (count >= req)
        {
            if (count == req)
                res = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return res;
}

// to cross check the median
int get_median_easy(int l, int r)
{
    vector<int> t;
    for (int i = l; i <= r; i++)
        t.push_back(v[i]);
    sort(t.begin(), t.end());
    return t[t.size() / 2];
}

void get_pivot(int l, int r, int n, vector<int> &seg_mx, vector<int> &seg_mn, vector<vector<int>> &seg)
{
    if (r - l < 2)
        return;
    int max_val = query(0, 0, n - 1, l, r, seg_mx, 1);
    int min_val = query(0, 0, n - 1, l, r, seg_mn, 0);
    int median = get_median(min_val, max_val, l, r, n, seg);
    // cout << "median: " << median << endl;
    vector<pair<int, int>> t = {{mp[min_val], min_val}, {mp[max_val], max_val}, {mp[median], median}};
    sort(t.begin(), t.end());
    // get the mid value
    ans.push_back(t[1].first);
    int mid = index_val[t[1].second];
    get_pivot(l, mid - 1, n, seg_mx, seg_mn, seg);
    get_pivot(mid + 1, r, n, seg_mx, seg_mn, seg);
}

int32_t main()
{
    int n;
    cin >> n;
    vector<int> t(n);
    for (auto &i : t)
        cin >> i;
    vector<pair<int, int>> vp;
    for (int i = 0; i < n; i++)
    {
        vp.push_back({t[i], i});
    }
    sort(vp.begin(), vp.end());
    for (auto i : vp)
    {
        mp[i.second] = i.first;
        v.push_back(i.second);
    }
    for (int i = 0; i < n; i++)
    {
        index_val[v[i]] = i;
    }
    vector<int> seg_mx(4 * n), seg_mn(4 * n);
    vector<vector<int>> seg(4 * n);
    // build max and min segment tree
    build_seg_tree(0, 0, n - 1, seg_mx, 1);
    build_seg_tree(0, 0, n - 1, seg_mn, 0);
    // build merge sort tree
    build_merge_tree(0, 0, n - 1, seg);
    get_pivot(0, n - 1, n, seg_mx, seg_mn, seg);
    for (auto i : ans)
        cout << i << " ";
    return 0;
}