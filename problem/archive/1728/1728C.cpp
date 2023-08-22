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

int f(int x) {
    int ans = 0;
    while (x) {
        x /= 10;
        ans++;
    }
    return ans;
}

void solve() {
    int n; cin >> n;
    vi a(n), b(n);
    in(a); in(b);

    priority_queue<int> qa, qb;
    for (auto x: a) qa.emplace(x);
    for (auto x: b) qb.emplace(x);

    int ans = 0;
    while (!qa.empty() && !qb.empty()) {
        auto ma = qa.top(), mb = qb.top();
        if (ma == mb) {
            qa.pop();
            qb.pop();
        } else if (ma > mb) {
            qa.pop();
            qa.emplace(f(ma));
            ans++;
        } else {
            qb.pop();
            qb.emplace(f(mb));
            ans++;
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}