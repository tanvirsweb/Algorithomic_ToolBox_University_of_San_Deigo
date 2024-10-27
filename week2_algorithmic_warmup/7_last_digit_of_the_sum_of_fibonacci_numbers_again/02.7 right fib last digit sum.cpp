#include<bits/stdc++.h>
#include <iostream>
#include<ctime>
#include<cmath>
#include<cstdlib>
#include <cmath>//just use <bits/stdc++.h> instead of using multiple header
#include <algorithm>
#include <vector>
typedef   long long int               ll;

using namespace std;
long long get_fibonacci_partial_sum(long long from, long long to);

// Function to return the nth Fibonacci number

long long fib(int n)
{
    double phi = (1 + sqrt(5)) / 2;
    return (round(pow(phi, n)/ sqrt(5)));
}
// Function to return the required sum
long long calculateSum(int from, int to)
{
// Using our deduced result
    long long sum = (fib(to + 2)+10 - fib(from + 1))%10;
    return sum%10;//last digit of partial sum
}
//.............................................

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i =0; i <= to; ++i) {
        if (i >= from) {
            sum= (sum+current);
        }

        long long new_current = next;
        next = (next + current);
        current = new_current;
    }
    //cout<<"  current= "<<current<<endl;

    return sum;
}
//test whether your fastest algo is right all the time or not...................
void stressTest()
{
    ll native,fast,from,to;

    srand(time(0));//seed rand number generator
    while(1)//while(i++<40)
    {
        from=rand()%30;
        to=rand()%40+30;//if m=rand()%40+1;then m=1 to 39
        cout<<"from="<<from<<" to="<<to<<endl;

        native=get_fibonacci_partial_sum_naive(from,to);
        fast=calculateSum(from,to);
        //native=fibonacci_fast(from);
        //fast=Fib(from);



        cout<<native<<" "<<fast<<endl;
        if(native!=fast)
        {
            cout<<"............Error...........\n";
            break;
        }
    }
}//...................................................

int main()
{
    int f,t;
    cin>>f>>t;
    cout << calculateSum(f, t)<<endl;
    //cout<<get_fibonacci_partial_sum_naive(f,t)<<endl;
    //cout<<get_fibonacci_partial_sum(f,t)<<endl;
    //stressTest();

    //return 0;
}

long long get_fibonacci_partial_sum(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i =0; i <= to; ++i) {
        if (i >= from) {
            sum= (sum+current)%10;
        }

        long long new_current = next;
        next = (next + current)%10;
        current = new_current;
    }
    //cout<<"  current= "<<current<<endl;

    return sum%10;
}

