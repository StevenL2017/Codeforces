#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <tuple>
#include <algorithm>
#include <functional>
#include <utility>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef vector<char> vc;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 3;

#define _  %  MOD
#define __ %= MOD

#define pq(T)                  priority_queue<T, vector<T>>
#define rpq(T)                 priority_queue<T, vector<T>, greater<T>>

#define sortA(v)               sort(v.begin(), v.end())
#define sortD(v)               sort(v.begin(), v.end(), greater<auto>())

#define rep(i, n)              for(int i = 0; i < n; ++i)
#define repA(i, a, n)          for(int i = a; i < n; ++i)
#define repD(i, a, n)          for(int i = a; i > n; --i)
#define loop(i, start, end)    for(auto i = start; (start<end)?i<end:i>end; (start<end)?i++:i--)

void solve() {
    int n;
    cin >> n;

    vi nums;
    rep(i, n) {
        int num;
        cin >> num;
        nums.push_back(num % 10);
    }

    unordered_set<int> one;
    unordered_set<int> two;
    rep(i, n) {
        for (auto &x : two) {
            if ((nums[i] + x) % 10 == 3) {
                cout << "YES" << "\n";
                return;
            }
        }
        if (two.size() < 10) {
            for (auto &x : one) {
                two.emplace((nums[i] + x) % 10);
            }
        }
        one.emplace(nums[i]);
    }
    cout << "NO" << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}