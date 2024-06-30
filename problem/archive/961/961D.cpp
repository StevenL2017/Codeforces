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

const int N = 1e5 + 1;

int n;
pair<int, int> a[N];

inline pair<int, int> operator -(const pair<int, int> &a, const pair<int, int> &b) {
    return {a.first - b.first, a.second - b.second};
}

inline ll operator *(const pair<int, int> &a, const pair<int, int> &b) {
    return a.first * 1ll * b.second - a.second * 1ll * b.first;
}

bool check(pair<int, int> &p1, pair<int, int> &p2) {
    vi vis(n);
    for (int i = 0; i < n; i++) {
        if ((p1 - p2) * (a[i] - p2) == 0) {
            vis[i] = 1;
        }
    }
    int i1 = -1, i2 = -1;
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        if (i1 == -1) i1 = i;
        else if (i2 == -1) i2 = i;
    }
    if (i2 == -1) return true;
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        if ((a[i] - a[i1]) * (a[i2] - a[i1]) != 0) {
            return false;
        }
    }
    return true;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    if (n < 3 || check(a[0], a[1]) || check(a[0], a[2]) || check(a[1], a[2])) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}