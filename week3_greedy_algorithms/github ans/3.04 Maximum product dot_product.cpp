#include <iostream>//
#include <cmath>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <algorithm>//
#include <iomanip>
#include <assert.h>
#include <vector>//
#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <set>
#include <complex>
#include <list>
#include <climits>
#include <cctype>
#include <bitset>
#include <numeric>
#include <array>
#include <tuple>
#include <stdexcept>
#include <utility>
#include <functional>
#include <locale>
#define all(v) v.begin(), v.end()
#define mp make_pair
#define pb push_back


typedef long long int ll;
using namespace std;
long long max_dot_product(vector<int> a, vector<int> b);

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(a, b) << std::endl;
}
//.................

long long max_dot_product(vector<int> a, vector<int> b) {
  long long result = 0;
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  for (size_t i = 0; i < a.size(); i++) {
    result += ((long long) a[i]) * b[i];
  }
  return result;
}
