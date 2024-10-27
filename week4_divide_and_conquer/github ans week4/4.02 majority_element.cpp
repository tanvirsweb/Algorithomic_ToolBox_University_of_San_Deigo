#include <algorithm>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  int major_got = 0;
  int count = 1;
  sort(a.begin(),a.end());
  int currentElement = a[0];
  for(int i = 1; i<a.size(); i++){
    if(a[i] == currentElement){
      count += 1;
      if(count > floor(a.size()/2)){return 1;}
    }
    else{currentElement = a[i];count = 1;}
  }
  return 0;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << get_majority_element(a, 0, a.size()) << '\n';
}
