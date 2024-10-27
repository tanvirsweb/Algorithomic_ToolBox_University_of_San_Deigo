//Mod of a large Fibonacci number
#include <iostream>
#include<ctime>
#include<cstdlib>

typedef   long long int            ll;
using namespace std;

//--------------------------------------
//Fast Algorithm.
ll Periodic(ll m) {
	ll a = 0, b = 1, c = a + b;
	for (int i = 0; i < m*m; i++) {
		c = (a + b) % m;//if m's multiplier is found then mod=0 and exit
		a = b;
		b = c;
		if (a == 0 && b == 1)
			return i + 1;// Periodic(m) != (m*m-1)%m;
                //There is no exact formula for the length of the period.
        //The mod value in a period are Fibbonacci Numbers
		//How many numbers can be in a Period??Length of the period
	}

}
//𝐹𝑖         0 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610
//𝐹𝑖 mod 2   0 1 1 0 1 1 0  1  1  0  1  1   0   1   1   0
//          ..3.. --3-- ..3....  ---3---   .....3...

//0%2 1%2 1%2 | 2%2 3%2 5%2 |8%2 13%2 21%2 | 34%2 55%2 89%2 | 144%2
//  0   1   1 |  0   1   1  |  0   1   1   |    0    1    1 |   0
//__________________________________________________________________

//𝐹𝑖 mod 3  0 1 1 2 0 2 2  1  0  1  1  2   0    2  2   1
//          .........8......   -------------8-----------
/*
Take a detailed look at this table. Do you see? Both these sequences are periodic! For 𝑚 = 2, the period
is 011 and has length 3, while for 𝑚 = 3 the period is 01120221 and has length 8. Therefore, to compute,
say, 𝐹2015 mod 3 we just need to find the remainder of 2015 when divided by 8. Since 2015 = 251 · 8 + 7, we
conclude that 𝐹2015 mod 3 = 𝐹7 mod 3 = 1.
This is true in general: for any integer 𝑚 ≥ 2, the sequence 𝐹𝑛 mod 𝑚 is periodic. The period always
starts with 01 and is known as Pisano period.
*/

int Solve(ll n, ll m) {
	long long remainder = n % Periodic(m);
	//Remain position after INTEGER number<n/periodic(m)> of full periods
	//Num position for the N th fibonacci number

	long long first = 0;
	long long second = 1;

	long long res = remainder;

	for (int i = 1; i < remainder; i++) {
		res = (first + second) % m;
		first = second;
		second = res;
	}

	return res % m;
	//return mod value= Fib(n)%m = Fib(n % PeriodForM) %m = Num(remainder) th fibonacci number
	//f(2015)%3=f(2015%8)%3=f(7)%3; which need less time
	// 8 is periodic remainder for (mod 3),
	//After each 8 numbers Everything REPEATS if we use mod 3 serially for each fibonacci number;
	//f(n)%m=f(n%How many fibonacci num in period for MOD m)%m;
}
//=====================================================
//Native algorithm
long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}
//-----------------------------------------------------------------------------
//test whether your fastest algo is right all the time or not...................
void stressTest()
{
    int n,m;
    ll native,fast;

    srand(time(0));//seed rand number generator
    while(1)//while(i++<40)
    {
        //Both Input of LCM should not be 0
        n=rand()%500+2;//n=2 to 501
        m=rand()%50;//if m=rand()%40+1;then m=1 to 39
        cout<<"m="<<m<<" n="<<n<<endl;

        native=get_fibonacci_huge_naive(m,n);
        fast=Solve(m,n);

        cout<<native<<" "<<fast<<endl;
        if(native!=fast)
        {
            cout<<"............Error...........\n";
            break;
        }
    }
}//----------------------------------------------------------------------
int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    long long n, m;
    std::cin >> n >> m;
    //std::cout << get_fibonacci_huge_naive(n, m) << '\n';
    std::cout << Solve(n, m) << '\n';
    //stressTest();
}
