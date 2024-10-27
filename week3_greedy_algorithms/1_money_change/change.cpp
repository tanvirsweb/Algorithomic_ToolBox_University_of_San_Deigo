#include <iostream>
using namespace std;

int get_change(int val) {
  //write your code here
  int sum;
  sum=(val/10);//num of 10 taka notes= (taka/10)
  sum=sum+( (val%10)/5 );
  //num of 5 taka notes=(remainder for dividing 10)/5;
  sum=sum+( (val%10)%5 );
  //num of 1 taka notes=<(remainder for dividing 10)%remainder of 5>
  return sum;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
