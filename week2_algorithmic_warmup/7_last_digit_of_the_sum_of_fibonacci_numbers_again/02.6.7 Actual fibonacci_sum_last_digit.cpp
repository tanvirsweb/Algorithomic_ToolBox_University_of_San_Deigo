//learn??BINET'S formula
//find the relationship between the sum of Fibonacci numbers

//f(n+1)=f(n)+f(n-1)
//f(n-1)=f(n+1)-f(n)
// f(0)+f(1)+f(2)+f(3)+f(4)+......f(n-1)=f(n+1)-f(1)
// Sum(1 to n-1 th)=Fib(n+1)-1;
//..............................
// sum(1 to n 'th)= Fib(n+2)-1;  //BINET's Formula//Fib[2]=1 /whatever Fib[1]=0/1(0112/1123)
// Sum Of 1st n fib numbers (Fib[0]+Fib[1]+.....+Fib[n]) = Fib[n+2]-Fib[2]
//.............................proved by mathematical Induction
#include <iostream>
#include<ctime>
#include<cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
typedef   long long int               ll;

using namespace std;

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

// Sum Of 1st n fib numbers (Fib[0]+Fib[1]+.....+Fib[n]) = Fib[n+2]-Fib[2]
ll Huge_Fibonacci(ll n) {
	int Last_Digit_Of_nPlus2 = Solve(n + 2, 10);//fib(n+2)%10
	int Last_Digit_Of_2 = Solve(2, 10);//fib(2)%10

	if (Last_Digit_Of_nPlus2 >= Last_Digit_Of_2)
		return (Last_Digit_Of_nPlus2 - Last_Digit_Of_2);
	else
		return ((10 + Last_Digit_Of_nPlus2) - Last_Digit_Of_2);
		//make Fib(n+2)%10 Larger so that the sum become +ve
}

int main() {
    long long from,to;
    std::cin >>from>>to;

    cout << ( (Huge_Fibonacci(to)+10-Huge_Fibonacci(from-1))%10) << endl;//Fastest algo
    //sum(0-to)+10-sum(0 to from-1)=from-to all fib sum
}


