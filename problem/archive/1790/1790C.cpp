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

void solve() {
    int n; cin >> n;
    vector<vi> a(n, vi(n - 1));
    for (int i = 0; i < n; i++) {
        in(a[i]);
    }

    vi cnt(n + 1, 0);
    int first = 0;
    for (int i = 0; i < n; i++) {
        cnt[a[i][0]]++;
        if (cnt[a[i][0]] > 1) {
            first = a[i][0];
        }
    }

    for (int i = 0; i < n; i++) {
        if (a[i][0] != first) {
            cout << first << " ";
            out(a[i]);
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}