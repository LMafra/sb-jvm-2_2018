//#include <regex>
#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  cin >> s;
  char c;
  int i;
for(i = s.length()-1, c = s[i];c != '/'; i-- , c = s[i]){
    cout << "i is => " << i << endl;
    cout << c << endl;
  }
  cout << "i ===> "<<i << endl;
  for(int ii =0; ii < i+1; ii++){
//    cout << "inside loopi " << i << endl;
    cout << s[ii];
  }
  cout << endl;
  return 0;
}
