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

const int MOD = 1e9 + 7;
const int N = 4e4 + 3;

vi p;

int calc_num(vi& a) {
    int ans = 0;
    for (auto x: a) {
        ans *= 10;
        ans += x;
    }
    return ans;
}

void calc_palindrome() {
    for (int x = 1; x < 400; x++) {
        vi d;
        int y = x;
        while (y) {
            d.push_back(y % 10);
            y /= 10;
        }
        vi pre;
        for (int i = 1; i < ssz(d); i++) {
            pre.push_back(d[i]);
        }
        reverse(pre.begin(), pre.end());
        vi a = pre;
        for (auto num: d) {
            a.push_back(num);
        }
        int res = calc_num(a);
        if (res < N) {
            p.push_back(res);
        }
        pre.push_back(d[0]);
        for (auto num: d) {
            pre.push_back(num);
        }
        res = calc_num(pre);
        if (res < N) {
            p.push_back(res);
        }
    }
    sort(p.begin(), p.end());
}

int f[N];

void calc() {
    calc_palindrome();
    f[0] = 1;
    for (auto y: p) {
        for (int x = 1; x < N; x++) {
            if (y > x) {
                continue;
            }
            f[x] += f[x - y];
            f[x] %= MOD;
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