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

int query_and(int i, int j) {
    cout << "and " << i << " " << j << endl;
    cout.flush();
    int x;
    cin >> x;
    return x;
}

int query_or(int i, int j) {
    cout << "or " << i << " " << j << endl;
    cout.flush();
    int x;
    cin >> x;
    return x;
}

void solve() {
    int n, k;
    cin >> n >> k;

    vi ans(n);
    int qa12 = query_and(1, 2);
    int qa13 = query_and(1, 3);
    int qa23 = query_and(2, 3);
    int qo12 = query_or(1, 2);
    int qo13 = query_or(1, 3);
    int qo23 = query_or(2, 3);
    for (int i = 0; i < 30; i++) {
        int a12 = qa12 >> i & 1;
        int a13 = qa13 >> i & 1;
        int a23 = qa23 >> i & 1;
        int o12 = qo12 >> i & 1;
        int o13 = qo13 >> i & 1;
        int o23 = qo23 >> i & 1;
        if (!a12 && !a13 && !a23) {
            if (o12 && o13) {
                ans[0] |= 1 << i;
            } else if (o12 && o23) {
                ans[1] |= 1 << i;
            } else if (o13 && o23) {
                ans[2] |= 1 << i;
            }
        } else {
            for (int j = 0; j < 3; j++) {
                ans[j] |= 1 << i;
            }
            if (!a13 && !a23) {
                ans[2] ^= 1 << i;
            } else if (!a12 && !a23) {
                ans[1] ^= 1 << i;
            } else if (!a12 && !a13) {
                ans[0] ^= 1 << i;
            }
        }
    }

    for (int j = 3; j < n; j++) {
        int qa = query_and(1, j + 1);
        int qo = query_or(1, j + 1);
        for (int i = 0; i < 30; i++) {
            int a = qa >> i & 1;
            int o = qo >> i & 1;
            if (ans[0] >> i & 1) {
                ans[j] |= a << i;
            } else {
                ans[j] |= o << i;
            }
        }
    }

    sort(ans.begin(), ans.end());

    cout << "finish " << ans[k - 1] << endl;
    cout.flush();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}