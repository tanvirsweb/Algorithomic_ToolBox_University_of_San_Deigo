#include <iostream>
#include<ctime>
#include<cstdlib>
#include<vector>

using namespace std;
void stressTest();
//slow and works for small input only,use long long instead
int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;//the sum will be very large
        //integer overflow may occur,then -ve value will be shown
    }

    return (current % 10);
}
//take less storage and fast but not fastest
int get_fibonacci_last_digit_FAST(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current)%10;
    }

    return current;
}
//Fastest algorithm.................................................................
int fibCalc(int n)
{
	vector<int> fib(n + 1);//no need for long long as just storing last digit,not full number
	fib[0] = 0;
	fib[1] = 1;
	for (int i = 2; i <= n; i++)
		//fib[i] = (fib[i - 1]%10 + fib[i - 2]%10)%10;
		fib[i] = (fib[i - 1]+ fib[i - 2])%10;
		//fib[i] and fib[i-1] will be small.so no need for extra mod
	return fib[n];
}

int main() {
    //freopen("2.02input.txt","rt",stdin);
    //freopen("2.02.txt","wt",stdout);//rt,wt,r,w,a should be inside double qutation
    int n;
    std::cin >> n;
    //int c=get_fibonacci_last_digit_FAST(n);
    int c = fibCalc(n);//fastest algo
    /*
    vector takes much storage but
    changing value of 3 var each time takes more time than changing value of
    one vector element
    */

    std::cout << c << '\n';
    //stressTest();
    }
    //------------------------------------------------------
    //------------------------------------------------------
//test whether your fastest algo is right all the time or not..........................
void stressTest()
{
    int native,fast,n;

    srand(time(0));//seed rand number generator
    while(1)
    {
        n=rand()%40;//n=0 to 100
        native=get_fibonacci_last_digit_naive(n);
        //fast=get_fibonacci_last_digit_FAST(n);
        fast=fibCalc(n);

        cout<<"Fib("<<n<<") %"<<10<<"=\t";
        cout<<native<<" "<<fast<<endl;
        if(native!=fast)
        {
            cout<<"............Error...........\n";
            break;
        }
    }
}
