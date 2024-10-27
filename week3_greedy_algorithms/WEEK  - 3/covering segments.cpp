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
#include <climits>//
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
#define endl '\n'

typedef long long int ll;
using namespace std;

struct Segment {
  int start, end;
};

vector<int> optimal_points(vector<Segment> &segments);
bool segmentComparator(Segment a , Segment b);



bool segmentComparator(Segment a , Segment b) {
  return a.end < b.end;
}
//...................................
int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
//..................

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int > points;
  sort(segments.begin(), segments.end(), segmentComparator);
  int endIndex = segments[0].end;
  for (int i=1; i < segments.size(); i++) {
      if (segments[i].start > endIndex) {
          points.push_back(endIndex);
          endIndex = segments[i].end;
      }
      else {
          if (segments[i].end < endIndex)
          endIndex = segments[i].end;
      }
  }
  points.push_back(endIndex);
  return points;
}
