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

int query(int l, int r) {
    cout << "? " << l << " " << r << endl;
    cout.flush();
    int cnt = 0;
    for (int i = l; i <= r; i++) {
        int x;
        cin >> x;
        if (l <= x && x <= r) {
            cnt++;
        }
    }
    return cnt;
}

void solve() {
    int n;
    cin >> n;

    int l = 1, r = n;
    while (l < r) {
        auto mid = (l + r) / 2;
        auto cnt = query(l, mid);
        if (cnt & 1) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << "! " << l << endl;
    cout.flush();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}