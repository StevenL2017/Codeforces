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
    map<int, int> vert, diag;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        vert[x]++;
        diag[x + y]++;
    }

    vi ans(2);
    for (auto [x, c]: vert) {
        if (c & 1) {
            ans[0] = x;
            break;
        }
    }
    for (auto [d, c]: diag) {
        if (c & 1) {
            ans[1] = d - ans[0];
            break;
        }
    }
    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}