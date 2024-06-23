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
    vi a(n); in(a);

    set<int> s;
    for (auto x : a) {
        s.insert(x);
    }

    int i = 0, j = n - 1;
    while (i < j) {
        int mn = *s.begin(), mx = *s.rbegin();
        if (a[i] == mn || a[i] == mx) {
            s.erase(a[i++]);
            continue;
        }
        if (a[j] == mn || a[j] == mx) {
            s.erase(a[j--]);
            continue;
        }
        if (i < j) {
            cout << i + 1 << " " << j + 1 << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}