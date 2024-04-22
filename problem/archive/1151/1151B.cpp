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
    vector<vi> a(n, vi(m));
    for (int i = 0; i < n; i++) {
        in(a[i]);
    }
    
    vi ans(n, 1);
    int xor_ = 0;
    for (int i = 0; i < n; i++) {
        xor_ ^= a[i][0];
    }

    if (xor_) {
        cout << "TAK" << endl;
        out(ans);
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (a[i][j] != a[i][0]) {
                ans[i] = j + 1;
                cout << "TAK" << endl;
                out(ans);
                return;
            }
        }
    }

    cout << "NIE" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}