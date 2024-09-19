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
    int n, c;
    cin >> n >> c;
    vi vis(c + 1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        vis[x] = 1;
    }

    vi yes, no, pre(c + 1);
    for (int x = 1; x <= c; x++) {
        if (vis[x]) yes.push_back(x);
        else no.push_back(x);
        pre[x] = pre[x - 1] + vis[x];
    }

    for (auto r: no) {
        for (auto y: yes) {
            if (r * 1ll * y > c) break;
            int left = r * y, right = min(c, (r + 1) * y - 1);
            if (pre[right] - pre[left - 1] > 0) {
                cout << "No" << endl;
                return;
            }
        }
    }
    cout << "Yes" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}