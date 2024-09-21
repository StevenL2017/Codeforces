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
    vi a(n);
    in(a);

    vi pos(n);
    iota(pos.begin(), pos.end(), 0);
    vector<pair<int, int>> ans;
    for (int i = n - 1; i > 0; i--) {
        vi pre(n, -1);
        for (auto j: pos) {
            if (pre[a[j] % i] != -1) {
                ans.emplace_back(j, pre[a[j] % i]);
                pos.erase(find(pos.begin(), pos.end(), j));
                break;
            }
            pre[a[j] % i] = j;
        }
    }

    reverse(ans.begin(), ans.end());
    cout << "YES" << endl;
    for (auto [x, y]: ans) {
        cout << x + 1 << " " << y + 1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}