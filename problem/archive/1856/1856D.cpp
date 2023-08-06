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
#define ssz(a) (int)((a).size())

#define endl '\n'
template <class T> void in(vector<T>& a) { for (int i = 0; i < ssz(a); i++) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { for (int i = 0; i < ssz(a); i++) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

int query(int l, int r) {
    if (l == r) return 0;
    cout << "? " << l << " " << r << endl;
    cout.flush();
    int x; cin >> x;
    return x;
}

void solve() {
    int n; cin >> n;

    function<int(int, int)> dfs = [&] (int l, int r) -> int {
        if (l == r) return l;
        int mid = (l + r) / 2;
        int left = dfs(l, mid);
        int right = dfs(mid + 1, r);

        int q1 = query(left, right - 1);
        int q2 = query(left, right);
        if (q1 == q2) return right;
        else return left;
    };
    int ans = dfs(1, n);

    cout << "! " << ans << endl;
    cout.flush();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}