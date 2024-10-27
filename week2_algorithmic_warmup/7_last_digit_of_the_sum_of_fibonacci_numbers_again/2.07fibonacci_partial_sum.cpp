//learn??BINET'S formula
//find the relationship between the sum of Fibonacci numbers

//f(n+1)=f(n)+f(n-1)
//f(n-1)=f(n+1)-f(n)
// f(0)+f(1)+f(2)+f(3)+f(4)+......f(n-1)=f(n+1)-f(1)
// Sum(1 to n-1 th)=Fib(n+1)-1;
// sum(1 to n 'th)= Fib(n+2)-1;  //BINET's Formula//Fib[2]=1 /whatever Fib[1]=0/1(0112/1123)
// Sum Of 1st n fib numbers (Fib[0]+Fib[1]+.....+Fib[n]) = Fib[n+2]-Fib[2]
//proved by mathematical Induction

/*
Summation of l th fibonacci number to r th fibonacci number//Partial sum of fibonacci numbers

S(l,r)=S(r)-S(l-1)//as F(l) is included in the sum,so subtract [F(0) to F(l-1)]
S(l,r)=[ F(r+2)-1 ] -[F(l-1+2)-1]
-----------------------
S(l,r)=F(r+2)-F(l+1);
----------------------
*/

#include <iostream>
#include<ctime>
#include<cmath>
#include<cstdlib>
#include <cmath>//just use <bits/stdc++.h> instead of using multiple header
#include <algorithm>
#include <vector>
typedef   long long int               ll;

using namespace std;
long long get_fibonacci_partial_sum_naive(long long from, long long to);
void stressTest();

//............................................

// Sum Of 1st n fib numbers (Fib[0]+Fib[1]+.....+Fib[n]) = Fib[n+2]-Fib[2]
//proved by mathematical Induction
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

long long Fib(int n)//May not be always right
{
    double phi=(1+sqrt(5))/2;
    return round(pow(phi,n)/sqrt(5));// [((1+root5)/2)^n]/root5
}
ll partial_sum(ll from,ll to)
{
    ll sum=0;
    //sum=Fib(to+2)-Fib(from+1);//shows wrong ans sometimes
    sum=fibonacci_fast(to+2)-fibonacci_fast(from+1);
    return (sum%10);//Last digit
}
int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
    cout <<partial_sum(from,to)<< endl;//Fastest algo
    //stressTest();
}


long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}
//test whether your fastest algo is right all the time or not...................
void stressTest()
{
    ll native,fast,from,to;

    srand(time(0));//seed rand number generator
    while(1)//while(i++<40)
    {
        from=rand()%20;
        to=rand()%60+20;//if m=rand()%40+1;then m=1 to 39
        cout<<"from="<<from<<" to="<<to<<endl;

        native=get_fibonacci_partial_sum_naive(from,to);
        fast=partial_sum(from,to);
        //native=fibonacci_fast(from);
        //fast=Fib(from);



        cout<<native<<" "<<fast<<endl;
        if(native!=fast)
        {
            cout<<"............Error...........\n";
            break;
        }
    }
}
//def fibonacci_partial_sum_improved(m, n):
//return (get_fibonacci_huge(n+2, 10) + 10 - get_fibonacci_huge(m+1, 10)) % 10



