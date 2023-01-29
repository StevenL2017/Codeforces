#include <iostream>
#include <cstdio>
#include <climits>
#include <cmath>
#include <cstring>
#include <string>
#include <array>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <algorithm>
#include <functional>

using namespace std;

#define ll long long
#define vi vector<int>

#define ssz(x)              (int)((x).size())
#define sorta(v)            sort(v.begin(), v.end())
#define sortd(v)            sort(v.rbegin(), v.rend())

#define rep(i, n)           for (int i = 0; i < n; i++)
#define repa(i, a, n)       for (int i = a; i < n; i++)
#define repd(i, a, n)       for (int i = a; i > n; i--)

#define endl '\n'
template <class T> void in(vector<T>& a) { rep(i, ssz(a)) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { rep(i, ssz(a)) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

int query(int l, int r) {
    cout << "? " << l << " " << r << endl;
    cout.flush();
    int ans; cin >> ans;
    return ans;
}

void solve() {
    int n, t; cin >> n >> t;

    map<pair<int, int>, int> cache;
    function<void(int, int, int)> update = [&] (int pos, int l, int r) {
        cache[{l, r}]--;
        if (l < r) {
            auto mid = l + (r - l) / 2;
            if (pos <= mid) {
                update(pos, l, mid);
            } else {
                update(pos, mid + 1, r);
            }
        }
    };

    while (t--) {
        int k; cin >> k;

        int left = 1, right = n;
        while (left < right) {
            auto mid = left + (right - left) / 2;
            pair<int, int> range = make_pair(left, mid);
            if (!cache.count(range)) {
                cache[range] = mid - left + 1 - query(left, mid);
            }
            auto q = cache[range];
            if (k <= q) {
                right = mid;
            } else {
                k -= q;
                left = mid + 1;
            }
        }

        cout << "! " << right << endl;
        cout.flush();
        update(right, 1, n);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}