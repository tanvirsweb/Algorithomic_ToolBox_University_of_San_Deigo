#include <iostream>
#include <cmath>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
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
//
int optimal_weight(int W, const vector<int> &w);


int main() {
    int n, W;
    std::cin >> W >> n;
    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        std::cin >> w[i];
    }
    std::cout << optimal_weight(W, w) << '\n';
}
//.........................

int optimal_weight(int W, const vector<int> &w) {
    int i,j;
    vector< vector<int> > M(w.size()+1, vector<int> (W+1, 0));
    for(i = 1; i <= w.size(); i++){
        for(j = 1; j <= W; j++){
            if(w[i-1] > j){M[i][j] = M[i-1][j];}
            else{M[i][j] = max(w[i-1] + M[i-1][j-w[i-1]], M[i-1][j]);}
        }
    }
    return M[w.size()][W];
}
