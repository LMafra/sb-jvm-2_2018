#include <string>
#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
  string s;
  const char * cl = "my_class_name.class";
  s = cl;
  cout << s.find_last_of(".class") << endl;
  cout << s.substr(0, s.find_last_of(".class") - 5) << endl;
  cout << s.substr(0, s.find_first_of(".class") - 5) << endl;
  const char * i = "nada a dizer" "nada a perder";
}