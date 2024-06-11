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

set<int> find(vi& a) {
    int i = -1, j = -1, k = -1;
    for (int c = 0; c < ssz(a); c++) {
        if (i == -1 || a[c] > a[i]) {
            k = j;
            j = i;
            i = c;
        } else if (j == -1 || a[c] > a[j]) {
            k = j;
            j = c;
        } else if (k == -1 || a[c] > a[k]) {
            k = c;
        }
    }
    set<int> ans;
    ans.insert(i);
    ans.insert(j);
    ans.insert(k);
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vi a(n), b(n), c(n);
    in(a);
    in(b);
    in(c);

    set<int> cand;
    for (auto x : find(a)) {
        cand.insert(x);
    }
    for (auto x : find(b)) {
        cand.insert(x);
    }
    for (auto x : find(c)) {
        cand.insert(x);
    }

    int ans = 0;
    for (auto x : cand) {
        for (auto y : cand) {
            if (x == y) continue;
            for (auto z : cand) {
                if (z == x || z == y) continue;
                ans = max(ans, a[x] + b[y] + c[z]);
            }
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