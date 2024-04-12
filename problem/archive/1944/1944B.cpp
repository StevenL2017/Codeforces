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
    int n, k;
    cin >> n >> k;
    k *= 2;
    vi a(2 * n);
    in(a);

    vi cnt(n + 1);
    for (int i = 0; i < n; i++) {
        cnt[a[i]]++;
    }

    vi g0, g1, g2;
    for (int i = 1; i <= n; i++) {
        if (cnt[i] == 0) g0.push_back(i);
        else if (cnt[i] == 1) g1.push_back(i);
        else g2.push_back(i);
    }

    int c = 0;
    for (auto x : g2) {
        if (c < k) {
            c += 2;
            cout << x << " " << x << " ";
        }
    }
    for (auto x : g1) {
        if (c < k) {
            c++;
            cout << x << " ";
        }
    }
    cout << endl;

    c = 0;
    for (auto x : g0) {
        if (c < k) {
            c += 2;
            cout << x << " " << x << " ";
        }
    }
    for (auto x : g1) {
        if (c < k) {
            c++;
            cout << x << " ";
        }
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}