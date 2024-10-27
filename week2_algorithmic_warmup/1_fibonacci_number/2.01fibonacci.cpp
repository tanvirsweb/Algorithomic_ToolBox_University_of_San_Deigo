#include <iostream>
#include<vector>
#include<ctime>
#include<stdio.h>
#include <cassert>
using namespace std;
void stressTest();
void test_solution();

// The following code calls a naive algorithm for computing a Fibonacci number.
//
// What to do:
// 1. Compile the following code and run it on an input "40" to check that it is slow.
//    You may also want to submit it to the grader to ensure that it gets the "time limit exceeded" message.
// 2. Implement the fibonacci_fast procedure.
// 3. Remove the line that prints the result of the naive algorithm, comment the lines reading the input,
//    uncomment the line with a call to test_solution, compile the program, and run it.
//    This will ensure that your efficient algorithm returns the same as the naive one for small values of n.
// 4. If test_solution() reveals a bug in your implementation, debug it, fix it, and repeat step 3.
// 5. Remove the call to test_solution, uncomment the line with a call to fibonacci_fast (and the lines reading the input),
//    and submit it to the grader.

int fibonacci_naive(int n) {
    if (n <= 1)
        return n;

    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

long long fibonacci_fast(int n) {
    std::vector<long long>Fib(n+1);//Fibonacci numbers can be very large so take long long type
    //long long Fib[n+1];
    int i;

    //if(n==1)return 0;
    //else if(n==2)return 1; no need instead of returning a[i]] return a[n]

    Fib[0]=0;
    Fib[1]=1;
    for(i=2;i<=n;i++)//i=2 to n(including)
    {//1st fibonacci number is (considered )returned 1;
        Fib[i]=Fib[i-1]+Fib[i-2];
    }

    return Fib[n];//return n;not n-1;first num Fib[0]=0 is not considered as Fib1 Fibbonacci number here
}



int main() {
    //freopen("2.01.txt","a",stdout);
    int n = 0;
    std::cin >> n;

    //std::cout << fibonacci_naive(n) << '\n';
    //test_solution();
    //stressTest();
    std::cout << fibonacci_fast(n) << '\n';
    return 0;
}
//....................................
//.....................................
void test_solution() {
    assert(fibonacci_fast(3) == 2);
    assert(fibonacci_fast(10) == 55);
    for (int n = 0; n < 20; ++n)
        assert(fibonacci_fast(n) == fibonacci_naive(n));
}
void stressTest()
{
    srand(time(0));
    while(1)
    {
        int n=rand()%40+1;
        std::cout<<"Fib("<<n<<")="<<"\t"<<fibonacci_fast(n)<<"="<<fibonacci_naive(n)<<std::endl;
        if(fibonacci_naive(n)!=fibonacci_fast(n)){
            std::cout<<".........Error......"<<std::endl;
            break;
        }
    }
}
