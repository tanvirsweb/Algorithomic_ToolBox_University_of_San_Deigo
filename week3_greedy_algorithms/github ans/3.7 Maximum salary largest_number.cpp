#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isGreaterOrEqual(string a, string b){
  string a_in_the_front;
  a_in_the_front.append(a).append(b);
  string b_in_the_front;
  b_in_the_front.append(b).append(a);
  int a_front = stoi(a_in_the_front);
  int b_front = stoi(b_in_the_front);
  return a_front>=b_front;
}

string largest_number(vector<string> a) {
  string biggest;
  string biggest_digit;
  string digit;
  string result;
  while(a.size() > 0){
    biggest = "0";
    biggest_digit = "0";
    for (size_t i = 0; i < a.size(); i++) {
      digit = a[i].at(0);
      if(digit >= biggest_digit){
        if(digit == biggest_digit){
          if(isGreaterOrEqual(a[i], biggest)){biggest = a[i];}
        }
        else{
          biggest_digit = digit;
          biggest = a[i];
          }
        }
      }
    result += biggest;
    int index = distance(a.begin(), find(a.begin(), a.end(), biggest));
    a.erase(a.begin() + index);
    }
  return result;
  }

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
