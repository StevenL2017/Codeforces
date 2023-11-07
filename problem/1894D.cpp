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
    int n, m;
    cin >> n >> m;
    vi a(n), b(m);
    in(a); in(b);

    sort(b.begin(), b.end());

    vi c;
    int j = 0;
    for (int i = n - 1; i >= 0; i--) {
        while (j < m && b[j] <= a[i]) {
            c.push_back(b[j++]);
        }
        c.push_back(a[i]);
    }
    while (j < m) {
        c.push_back(b[j++]);
    }

    reverse(c.begin(), c.end());

    out(c);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}