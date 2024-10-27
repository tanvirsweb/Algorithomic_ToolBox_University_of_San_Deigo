#include <iostream>
#include<ctime>
#include<cstdlib>

typedef   long long int          ll;
using namespace std;

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}
//....................................................................
//=======================================================================
using namespace std;
// Find gcd For Two Numbers
ll gcd(ll a, ll b) {
	while (b) {
		ll tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}

// Find Lcm For Two Numbers
ll lcm(ll a, ll b) {
	return a / (ll)(gcd(a, b))* b;//a/gcd is integer no tension.
	//lcm=multiplication of 2 numbers /divided by their gcd.
}
//.............................................................................
//=============================================================================

//test whether your fastest algo is right all the time or not...................
void stressTest()
{
    int native,fast,n,m;

    srand(time(0));//seed rand number generator
    while(1)
    {
        //Both Input of LCM should not be 0
        n=rand()%50+1;//n=1 to 50
        m=rand()%50;//if m=rand()%40+1;then m=1 to 39
        cout<<"n="<<n<<" m="<<m<<endl;
        native=lcm_naive(m,n);

        fast=lcm(m,n);

        cout<<native<<" "<<fast<<endl;
        if(native!=fast)
        {
            cout<<"............Error...........\n";
            break;
        }
    }
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm(a, b) << std::endl;//fast
  //std::cout << lcm_naive(a, b) << std::endl;//Native
  //stressTest();
  return 0;
}
