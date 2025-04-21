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
    int n;
    cin >> n;
    vector<vector<ll>> a(n, vector<ll>(n));
    for (int i = 0; i < n; i++) {
        in(a[i]);
    }

    multiset<int> s;
    for (int i = 0; i < n; i++) {
        int cur = 0;
        for (int j = n - 1; j >= 0; j--) {
            if (a[i][j] != 1) {
                break;
            }
            cur++;
        }
        s.insert(cur);
    }

    int mex = 1;
    while (!s.empty()) {
        int mn = *s.begin();
        if (mex <= mn) {
            mex++;
        }
        s.erase(s.begin());
    }

    cout << min(mex, n) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}