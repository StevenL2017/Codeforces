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

    vi cnt(n);
    for (auto &x: a) {
        cnt[--x]++;
    }

    vi ans;
    multiset<int> s;
    int len = n - count(cnt.begin(), cnt.end(), 0);
    int l = 0, r = 0, d = len, t = 0;
    while (len) {
        while (d >= len) {
            if (cnt[a[r]] > 0) {
                s.insert(a[r]);
            }
            d -= (cnt[a[r]] == 1);
            cnt[a[r]]--;
            r++;
        }
        int x = t == 0 ? *s.rbegin() : *s.begin();
        ans.emplace_back(x + 1);
        while (a[l] != x) {
            s.extract(a[l]);
            l++;
        }
        s.erase(x);
        d -= (cnt[x] > 0);
        cnt[x] = 0;
        len--;
        t ^= 1;
    }

    cout << ssz(ans) << endl;
    out(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}