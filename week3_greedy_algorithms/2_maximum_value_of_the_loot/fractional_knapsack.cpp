#include <iostream>
#include<algorithm>//need for pair<>,sort(),min()
#include <vector>
using namespace std;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  // write your code here
  int i,n=weights.size();
  vector<pair<double,int>>v(n);
  //datatype of vector is pair named template which has 2 elements f datatype double and int.
  for(i=0;i<n;i++)
  {
    v[i].first=1.0*values[i]/weights[i];
    v[i].second=weights[i];
  }
  sort(v.begin(),v.end(),greater<pair<double,int>>());
  //sort(v.begin(),v.end(),[](int a,int b){return a>b;});
  //[](int a,int b){return a>b;} Lambda expression and greater<int>() does same work.
//std::greater<datatype> =sort in decending type //like greater than operator
//std::less<datatype> =sort in ascending order.//like less than operator
	//Sort acording to much Profit/weight
	//each time taking (unit/weight) Subtract the weight from max(SizeOfKnapSack) weight capacity
	double Res = 0;
	for (int i = 0; i < v.size() && capacity>0; i++) {
		Res += min(v[i].second, n)*v[i].first;
		//min weight*value
		capacity -= min(v[i].second, n);
	}
	//cout << fixed << setprecision(4) << Res << endl;
	return Res;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
    //values=values[i]/weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
