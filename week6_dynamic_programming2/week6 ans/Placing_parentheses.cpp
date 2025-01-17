#include <iostream>
#include <cmath>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <iomanip>
#include <assert.h>
#include <cassert>
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
long long eval(long long a, long long b, char op);
long long get_maximum_value(const string &exp);

int main() {
    string s;
    std::cin >> s;
    std::cout << get_maximum_value(s) << '\n';
}
//...........................

long long eval(long long a, long long b, char op) {
    if (op == '*') {
        return a * b;
    } else if (op == '+') {
        return a + b;
    } else if (op == '-') {
        return a - b;
    } else {
        assert(0);
    }
}
//...................................

long long get_maximum_value(const string &exp) {
    long n = exp.length()/2 + 1;
    vector< vector<long> > m(n, vector<long> (n, 0));
    vector< vector<long> > M(n, vector<long> (n, 0));
    vector<long >numbers;
    vector<char >op;

    for (int i = 0; i <  exp.size(); i++){
        if (i%2==0){numbers.push_back((long ) exp[i] - 48);}
        else{op.push_back(exp[i]);}
    }

    for(int i = 0; i < numbers.size(); i++){
        m[i][i] = numbers[i];
        M[i][i] = numbers[i];
    }
    for (int s=1; s < numbers.size(); s++){
        for (int i=0; i < numbers.size()-s; i++){
            int j = i + s;
            long max_value = numeric_limits<long>::min();
            long min_value = numeric_limits<long>::max();
            for (int k = i; k <=  j-1; k++){
                long a = eval(M[i][k], M[k+1][j], op[k]);
                long b = eval(M[i][k], m[k+1][j], op[k]);
                long c = eval(m[i][k], M[k+1][j], op[k]);
                long d = eval(m[i][k], m[k+1][j], op[k]);
                max_value = max(max_value,max(a, max(b, max(c, d))));
                min_value = min(min_value,min(a, min(b, min(c, d))));
            }
            pair<long, long>min_max;
            min_max.first = min_value;
            min_max.second = max_value;
            m[i][j] = min_max.first;
            M[i][j] = min_max.second;
        }
    }
    return M[0][numbers.size()-1];
}
