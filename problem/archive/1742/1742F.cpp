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
    int q;
    cin >> q;
    ll cnt_a_s = 1, cnt_a_t = 1;
    bool bs = false, bt = false;
    while (q--) {
        int op, k;
        string x;
        cin >> op >> k >> x;
        bool b = false;
        for (auto c: x) {
            if (c > 'a') {
                b = true;
                break;
            }
        }
        if (b) {
            if (op == 1) {
                bs = true;
            } else {
                bt = true;
            }
        } else {
            if (op == 1) {
                cnt_a_s += k * 1ll * ssz(x);
            } else {
                cnt_a_t += k * 1ll * ssz(x);
            }
        }
        if (bt || (!bs && cnt_a_s < cnt_a_t)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}