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

#define ssz(x)              (int)((x).size())
#define sorta(v)            sort(v.begin(), v.end())
#define sortd(v)            sort(v.rbegin(), v.rend())

#define rep(i, n)           for (int i = 0; i < n; i++)
#define repa(i, a, n)       for (int i = a; i < n; i++)
#define repd(i, a, n)       for (int i = a; i > n; i--)

#define endl '\n'
template <class T> void in(vector<T>& a) { rep(i, ssz(a)) cin >> a[i]; }
template <class T> void out(const vector<T>& a) { rep(i, ssz(a)) cout << a[i] << " \n"[i + 1 == ssz(a)]; }

#include <chrono>
#include <random>
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());

int N = 60;

int query1(int i) {
    N--;
    cout << "? " << i << endl;
    cout.flush();
    int a; cin >> a;
    return a;
}

int query2(int x) {
    N--;
    cout << "> " << x << endl;
    cout.flush();
    int a; cin >> a;
    return a;
}

void solve() {
    int n; cin >> n;

    int left = 0, right = 1e9, mx = right;
    while (left <= right) {
        auto mid = left + (right - left) / 2;
        if (query2(mid)) {
            left = mid + 1;
        } else {
            right = mid - 1;
            mx = mid;
        }
    }

    vi cand, idx(n);
    iota(idx.begin(), idx.end(), 1);
    int range = n;
    while (N > 0 && range > 0) {
        int i = rng32() % range;
        cand.push_back(query1(idx[i]));
        range--;
        swap(idx[i], idx[range]);
    }
    sorta(cand);
    if (cand.back() != mx) {
        cand.push_back(mx);
    }

    int d = 0;
    repa(i, 1, ssz(cand)) {
        d = gcd(d, cand[i] - cand[i - 1]);
    }

    cout << "! " << mx - d * (n - 1) << " " << d << endl;
    cout.flush();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}