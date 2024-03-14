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

int calc(vi& a, vi& b) {
    int n = ssz(a), m = ssz(b);
    vi c(n + 1);
    for (int i = n - 1, j = m - 1; i >= 0; i--) {
        c[i] += c[i + 1];
        while (j >= 0 && b[j] > a[i]) {
            j--;
        }
        if (j >= 0 && b[j] == a[i]) {
            c[i]++;
        }
    }

    int ans = c[0];
    for (int i = 0, j = 0, k = 0; i < m; i++) {
        while (j < n && a[j] <= b[i] + j) {
            j++;
        }
        while (k < m && b[k] - b[i] < j) {
            k++;
        }
        ans = max(ans, k - i + c[j]);
    }
    return ans;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vi neg_a, pos_a, neg_b, pos_b;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x < 0) neg_a.push_back(-x);
        else pos_a.push_back(x);
    }
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        if (x < 0) neg_b.push_back(-x);
        else pos_b.push_back(x);
    }
    reverse(neg_a.begin(), neg_a.end());
    reverse(neg_b.begin(), neg_b.end());
    cout << calc(neg_a, neg_b) + calc(pos_a, pos_b) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}