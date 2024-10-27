#include <iostream>
#include<ctime>
#include<cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
typedef   long long int               ll;
using namespace std;
int fibonacci_sum_squares_naive(long long n);
void stressTest();


ll Periodic(ll m) {
	ll a = 0, b = 1, c = a + b;
	for (int i = 0; i < m*m; i++) {
		c = (a + b) % m;
		a = b;
		b = c;
		if (a == 0 && b == 1)
			return i + 1;
	}
}
int Solve(ll n, ll m) {
	long long remainder = n % Periodic(m);

	long long first = 0;
	long long second = 1;

	long long res = remainder;

	for (int i = 1; i < remainder; i++) {
		res = (first + second) % m;
		first = second;
		second = res;
	}

	return res % m;
}

// Sum Of (Fib[0]^2+Fib[1]^2+.....+Fib[n]^2) = Fib[n]*Fib[n+1]
//sum of squares of fibonacci numbers.

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    long long n = 0;
    std::cin >> n;
    //std::cout << fibonacci_sum_squares_naive(n);
    cout << (Solve(n + 1,10)*Solve(n,10)) % 10 << endl;//Fast
    // Sum Of (Fib[0]^2+Fib[1]^2+.....+Fib[n]^2) = Fib[n]*Fib[n+1]
    //stressTest();

}
//...............................................
int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}

//test whether your fastest algo is right all the time or not...................
void stressTest()
{
    int n;
    ll native,fast;

    srand(time(0));//seed rand number generator
    while(1)//while(i++<40)
    {

        n=rand()%40;//if m=rand()%40+1;then m=1 to 39
        cout<<" n="<<n<<endl;

        native=fibonacci_sum_squares_naive(n);
        fast=(Solve(n + 1,10)*Solve(n,10)) % 10 ;

        cout<<native<<" "<<fast<<endl;
        if(native!=fast)
        {
            cout<<"............Error...........\n";
            break;
        }
    }
}


