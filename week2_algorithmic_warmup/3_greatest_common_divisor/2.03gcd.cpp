#include <iostream>
#include<ctime>
#include<cstdlib>

typedef   long long int          ll;
using namespace std;

int GCD(int First , int Second) {
	if (First == 0)//It doesn't matter who is small and who is big
		return Second;
	return GCD( Second % First ,First);// 1st=(2nd%1st) && (2nd=1st)
}
/*
5 2
2%5=2 5
5%2=1 2
2%1=0 1;
...........
2 5
5%2=1 2
2%1=0 1;

*/
ll FASTgcd(ll a, ll b) {
	while (b) {//b!=0
		ll tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;//return who is nonZERO
}

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  if(a==0)current_gcd=b; else if(b==0)current_gcd=a;
   for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;//The greatest number that divides BOth a and b=GCD
      }
    }
  }
  return current_gcd;
}
//test whether your fastest algo is right all the time or not..........................
void stressTest()
{
    int native,fast,n,m;

    srand(time(0));//seed rand number generator
    while(1)
    {
        //atleast one is NonZERO
        n=rand()%50;//n=0 to 50
        m=rand()%50+1;//if m=rand()%40+1;then m=1 to 39
        cout<<"n="<<n<<" m="<<m<<endl;
        native=gcd_naive(m,n);
        //fast=GCD(m,n);

        fast=FASTgcd(m,n);

        cout<<"m="<<m<<"n="<<n<<"\t";
        cout<<native<<" "<<fast<<endl;
        if(native!=fast)
        {
            cout<<"............Error...........\n";
            break;
        }
    }
}


int main() {

    //freopen("2.03in.txt","r",stdin);
    //freopen("2.03out.txt","wt",stdout);
    int a, b;
    std::cin >> a >> b;
    //std::cout << gcd_naive(a, b) << std::endl;//Native:work for small data and slow
    //std::cout << FASTgcd(a, b) << std::endl;//Fast but takes more time than GCD()
    std::cout << GCD(a, b) << std::endl;//FASTEST

    //stressTest();
    return 0;
}




/*int GCD(int small , int big) {
    if(small>big){//It doesn't matter who is small and who is big
        int tempBig;
        tempBig=big; big=small; small=tempBig; }//execute only if wrong direction input
	if (small == 0)
		return big;
	return GCD( big%small , small);
}*/
