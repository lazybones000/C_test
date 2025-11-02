// shorter_cpp.cpp
// Simple example to reduce typing time in cpp
// Never use it unless you want to get slap by your supervisor :)
//
// contributor: @revival0728
//
// This file should be compiled with c++11

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <functional>


// Reduce typing time by shorten the name of std container
using ll = long long;
using ld = long double;
template<class T, long long unsigned int N>
using Ar = std::array<T, N>;
template<class T>
using Vt = std::vector<T>;
template<class T, class C>
using Pq = std::priority_queue<T, std::vector<T>, C>;
template<class T>
using Ud_set = std::unordered_set<T>;
template<class K, class V>
using Ud_map = std::unordered_map<K, V>;

// Reduce typing time by magic loop macro
// the PICKER macro is the key macro to let it work
// the loop type depends on the number of arguments
#define loop(x, b, e, s) for(int x=(b); (s)>0?x<(e):x>(e); x+=(s))
#define loop1(e) loop(i, 0, e, 1)
#define loop2(x, e) loop(x, 0, e, 1)
#define loop3(x, b, e) loop(x, b, e, 1)
#define loop4(x, b, e, s) loop(x, b, e, s)
#define PICKER1(a, b, c, d, e, ...) e
#define LOOP(...) PICKER1(__VA_ARGS__, loop4, loop3, loop2, loop1)
#define FOR(...) LOOP(__VA_ARGS__)(__VA_ARGS__)
#define iter1(x) for(auto& i : x)
#define iter2(x, v) for(auto& x : v)
#define PICKER2(a, b, c, ...) c
#define ITER(...) PICKER2(__VA_ARGS__, iter2, iter1)
#define EACH(...) ITER(__VA_ARGS__)(__VA_ARGS__)

// Example Usage:
// problem: https://leetcode.com/problems/maximum-number-of-k-divisible-components/description/
int maxKDivisibleComponents(int n, Vt<Vt<int>>& edges, Vt<int>& values, int k) {
  int ans = 0;
  Vt<Vt<int>> adj(n, Vt<int>(0));
  FOR(i, edges.size()) {
    int u = edges[i][0], v = edges[i][1];
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  std::function<int(int, int)> dfs;
  dfs = [&](int u, int fu) -> int {
    int sum = values[u];
    EACH(v, adj[u]) {
      if(v == fu) continue;
      int sub_sum = dfs(v, u);
      if(sub_sum == 0) {
        ++ans;
      } else {
        sum += sub_sum, sum %= k;
      }
    }
    return sum % k;
  };
  if(dfs(0, 0) == 0)
    ++ans;
  else
    ans = 0;
  return ans;
}

int main() {
  int n, k;
  std::cin >> n >> k;
  Vt<Vt<int>> edges; edges.reserve(n - 1);
  FOR(i, n - 1) {
    Vt<int> edge(2);
    std::cin >> edge[0] >> edge[1];
    edges.push_back(edge);
  }
  Vt<int> values; values.reserve(n);
  EACH(values) {
    std::cin >> i;
  }
  std::cout << maxKDivisibleComponents(n, edges, values, k) << '\n';
}
