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
    int k1; cin >> k1;
    queue<int> q1;
    for (int i = 0; i < k1; i++) {
        int x; cin >> x;
        q1.push(x);
    }
    int k2; cin >> k2;
    queue<int> q2;
    for (int i = 0; i < k2; i++) {
        int x; cin >> x;
        q2.push(x);
    }

    int ans = 0;
    while (!q1.empty() && !q2.empty()) {
        int x1 = q1.front();
        q1.pop();
        int x2 = q2.front();
        q2.pop();
        if (x1 < x2) {
            q2.push(x1);
            q2.push(x2);
        } else {
            q1.push(x2);
            q1.push(x1);
        }
        ans++;
        if (ans > 110) {
            cout << -1 << endl;
            return;
        }
    }
    cout << ans << " " << (q1.empty() ? 2 : 1) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}