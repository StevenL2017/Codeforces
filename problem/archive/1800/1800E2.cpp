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
    string s, t;
    cin >> s >> t;

    if (s == t) {
        cout << "YES" << endl;
        return;
    }

    if (k >= n) {
        cout << "NO" << endl;
        return;
    }

    vi cnt(26);
    for (auto c: s) {
        cnt[c - 'a']++;
    }
    for (auto c: t) {
        cnt[c - 'a']--;
    }
    for (auto c: cnt) {
        if (c) {
            cout << "NO" << endl;
            return;
        }
    }

    for (int i = n - k; i < k; i++) {
        if (s[i] != t[i]) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}