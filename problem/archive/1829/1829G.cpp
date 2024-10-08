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

const int N = 1e6 + 1;

ll f[N];

void calc() {
    int row = 1, cur = 0;
    for (int i = 1; i < N; i++) {
        f[i] = i * 1ll * i;
        if (row > 1) {
            int ps = (row - 1) * (row - 2) / 2 + 1, pe = ps + row - 2;
            for (int j = 0; j < 2; j++) {
                int pre = i - row + j;
                if (pre >= ps && pre <= pe) {
                    f[i] += f[pre];
                }
            }
        }
        if (row > 2) {
            int ps = (row - 2) * (row - 3) / 2 + 1, pe = ps + row - 3;
            int pre = i - (row - 1) * 2;
            if (pre >= ps && pre <= pe) {
                f[i] -= f[pre];
            }
        }
        cur++;
        if (row == cur) {
            row++;
            cur = 0;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    cout << f[n] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    calc();
    int t = 1;
    cin >> t;
    while (t--) solve();
}