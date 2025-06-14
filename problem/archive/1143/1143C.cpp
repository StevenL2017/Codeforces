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
    vi a(n, 1);
    for (int i = 0; i < n; i++) {
        int p, c;
        cin >> p >> c;
        p--;
        if (c == 0) {
            a[i] = 0;
            if (p >= 0) {
                a[p] = 0;
            }
        }
    }

    vi ans;
    for (int i = 0; i < n; i++) {
        if (a[i]) {
            ans.push_back(i + 1);
        }
    }

    if (ans.empty()) {
        cout << -1 << endl;
    } else {
        out(ans);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}