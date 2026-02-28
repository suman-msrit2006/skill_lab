#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
    vector<int> tree;
    int n;

    void build(vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2*node, start, mid);
            build(arr, 2*node+1, mid+1, end);
            tree[node] = max(tree[2*node], tree[2*node+1]);
        }
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid)
                update(2*node, start, mid, idx, val);
            else
                update(2*node+1, mid+1, end, idx, val);

            tree[node] = max(tree[2*node], tree[2*node+1]);
        }
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l)
            return INT_MIN;
        if (l <= start && end <= r)
            return tree[node];

        int mid = (start + end) / 2;
        return max(query(2*node, start, mid, l, r),
                   query(2*node+1, mid+1, end, l, r));
    }

public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4*n);
        build(arr, 1, 0, n-1);
    }

    void update(int idx, int val) {
        update(1, 0, n-1, idx, val);
    }

    int queryMax(int l, int r) {
        return query(1, 0, n-1, l, r);
    }
};
