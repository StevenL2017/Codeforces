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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vi suf;
    int tot = 0;
    for (int i = n - 1; i > 0; i--) {
        if (s[i] == '0') tot--;
        else tot++;
        if (tot > 0) suf.push_back(tot);
    }

    sort(begin(suf), end(suf));

    int ans = 1;
    while (k > 0 && ssz(suf)) {
        k -= suf.back();
        suf.pop_back();
        ans++;
    }

    cout << (k > 0 ? -1 : ans) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}