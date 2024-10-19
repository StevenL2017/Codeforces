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
    int n, x;
    cin >> n >> x;
    vi a(n);
    in(a);

    int ans = 0, tot = 0;
    priority_queue<int> q;
    for (auto y: a) {
        if (tot >= y) {
            tot -= y;
            q.emplace(y);
        } else if (!q.empty() && q.top() >= y) {
            tot += q.top();
            tot -= y;
            q.pop();
            q.emplace(y);
        }
        tot += x;
        ans = max(ans, ssz(q));
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