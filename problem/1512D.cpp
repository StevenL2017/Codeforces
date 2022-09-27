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

int main() {
    int t;
    cin >> t;
    rep(c, t) {
        int n;
        cin >> n;
        vi nums;
        rep(i, n + 2) {
            int num;
            cin >> num;
            nums.push_back(num);
        }
        sortA(nums);

        ll tot = 0LL;
        rep(i, n) {
            tot += nums[i];
        }
        if (tot == nums[n] || tot == nums[n + 1]) {
            rep(i, n) {
                if (i < n - 1) {
                    cout << nums[i] << " ";
                } else {
                    cout << nums[i] << endl;
                }
                
            }
            continue;
        }

        tot += nums[n];
        int ix = -1;
        rep(i, n + 1) {
            if (tot - nums[i] == nums.back()) {
                ix = i;
                break;
            }
        }
        if (ix == -1) {
            cout << -1 << endl;
            continue;
        } else {
            int j = 0;
            rep(i, n + 1) {
                if (i == ix) continue;
                if (j < n - 1) {
                    cout << nums[i] << " ";
                } else {
                    cout << nums[i] << endl;
                }
                j++;
            }
        }
    }
    return 0;
}