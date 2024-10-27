#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

struct m1m2
{
  int m1;
  int m2;
};

m1m2 partition3(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l-1;
  int k = r+1;
  for (int i = l+1; i < k; i++) {
    if (a[i] < x) {
      j++;
      swap(a[i], a[j]);
    }
    else if (a[i]> x){
      k--;
      swap(a[i],a[k]);
      i--;
    }
  }
  m1m2 result = {j,k};
  return result;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }
  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  m1m2 M = partition3(a, l, r);
  randomized_quick_sort(a, l, M.m1);
  randomized_quick_sort(a, M.m2, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
