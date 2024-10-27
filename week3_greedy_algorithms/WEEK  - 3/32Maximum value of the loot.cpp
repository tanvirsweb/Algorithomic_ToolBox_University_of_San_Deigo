#include <iostream>
#include <cmath>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <algorithm>//needed for sort() function
#include <iomanip>
#include <assert.h>
#include <vector>
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
#define     all(v)            v.begin(),v.end()
#define     mp                     make_pair
#define     pb                     push_back
#define     endl                     '\n'

typedef   long long int               ll;

using namespace std;
int main() {
	int n, SizeOfKnapSack;
	cin >> n >> SizeOfKnapSack;
	vector<pair<int, int>> Value_Weight(n);
	//std::pair<T1,T2>Obj;//need <algorithm> header file for using pair.
	//Elements of this Template is (first and second)use DOT to access them
	//Obj.first=T1  Obj.second=T2
	//a Struct Template that provides a way to store 2 heterogenous objects as a single unit.
	//Heterogenous=datatype Different

	vector<pair<double,int>> ValuePerUnit(n); //double_=value per item <1.0*value/weight>
	//pair<double,int> =is the datatype of each element of vector.
	//we needed another vector as first one was int ,int and we need double,int.

	//as we are dividing integers we need to typecast it to double.
	for (int i = 0; i < n; i++) {
		cin >> Value_Weight[i].first >> Value_Weight[i].second;
		ValuePerUnit[i].first = 1.0 * Value_Weight[i].first / Value_Weight[i].second;
		ValuePerUnit[i].second = Value_Weight[i].second;
	}
	sort(ValuePerUnit.begin(), ValuePerUnit.end(),greater<pair<double,int>>());
	//sort(ValuePerUnit.begin(), ValuePerUnit.end(),[](<pair<double,int>v1,pair<double,int>v2){return v1.second>v2.second; }));//sort 1st greater and 2nd less
	//Sort acording to much Profit/weight
	//each time taking (unit/weight) Subtract the weight from max(SizeOfKnapSack) weight capacity
	double Res = 0;
	for (int i = 0; i < ValuePerUnit.size() && SizeOfKnapSack>0; i++) {
		Res += min(ValuePerUnit[i].second, SizeOfKnapSack)*ValuePerUnit[i].first;
		//min weight*value
		SizeOfKnapSack -= min(ValuePerUnit[i].second, SizeOfKnapSack);
	}
	cout << fixed << setprecision(4) << Res << endl;

	return 0;
}
//sort() greater<>(),min()
