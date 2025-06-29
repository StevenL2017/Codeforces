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

    string ans;
    int l = 0, r = n - 1, cur = 0;
    while (l <= r) {
        vector<pair<int, int>> cand;
        if (cur < a[l]) cand.emplace_back(a[l], 'L');
        if (cur < a[r]) cand.emplace_back(a[r], 'R');
        sort(begin(cand), end(cand));
        if (ssz(cand) == 2 && cand[0].first != cand[1].first) {
            cand.pop_back();
        }
        if (ssz(cand) == 1) {
            if (cand[0].second == 'L') {
                ans += cand[0].second;
                cur = cand[0].first;
                l++;
            } else {
                ans += cand[0].second;
                cur = cand[0].first;
                r--;
            }
        } else if (ssz(cand) == 2) {
            int l1 = l + 1, r1 = r - 1;
            while (l1 <= r && a[l1] > a[l1 - 1]) {
                l1++;
            }
            while (r1 >= l && a[r1] > a[r1 + 1]) {
                r1--;
            }
            if (l1 - l >= r - r1) {
                ans += string(l1 - l, 'L');
            } else {
                ans += string(r - r1, 'R');
            }
            break;
        } else {
            break;
        }
    }
    cout << ssz(ans) << endl;
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}