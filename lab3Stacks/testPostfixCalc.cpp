/*Ryan Kelly
rpk2kn
2/3/2018
filename: testPostfixCalc.cpp
*/

#include <iostream>
#include "stack.h"
#include <stdlib.h>
#include "postfixCalculator.h"
using namespace std;

int main() {
  /*
  PostfixCalculator p, p2, p3, p4, p5;
    p.pushNum (1);
    p.pushNum (2);
    p.pushNum (3);
    p.pushNum (4);
    p.pushNum (5);
    p.add();
    p.add();
    p.add();
    p.add();
    cout << "1 2 3 4 5 + + + + = " << p.getTopValue() << endl;

    p2.pushNum(20);
    p2.pushNum(10);
    p2.subtract();
    p2.pushNum(-3);
    p2.pushNum(10);
    p2.subtract();
    p2.subtract();
    p2.pushNum(2);
    p2.subtract();
    cout << "20 10 - -3 10 - - 2 - = " << p2.getTopValue() << endl;
    
    p3.pushNum(-1);
    p3.pushNum(-2);
    p3.pushNum(-5);
    p3.pushNum(3);
    p3.multiply();
    p3.pushNum(2);
    p3.pushNum(-2);
    p3.multiply();
    p3.multiply();
    p3.multiply();
    p3.multiply();
    cout << "-1 -2 -5 3 * 2 -2 * * * * = " << p3.getTopValue() << endl;

    p4.pushNum(-1512);
    p4.pushNum(-12);
    p4.pushNum(-2);
    p4.divide();
    p4.divide();
    p4.pushNum(-2);
    p4.divide();
    p4.pushNum(3);
    p4.divide();
    cout << "-1512 -12 -2 / / -2 / 3 / = " << p4.getTopValue() << endl;
    
    p5.pushNum(-1);
    p5.negate();
    p5.negate();
    p5.negate();
    cout << "-1 ~ ~ ~ = " << p5.getTopValue() << endl;
  */
  string s;
  PostfixCalculator p;
  while(cin >> s) {
    if(s.c_str()[0] == '*')
      p.multiply();
    else if(s.c_str()[0] == '/')
      p.divide();
    else if(s.c_str()[0] == '+')
      p.add();
    else if(s.c_str()[0] == '~')
      p.negate();
    else if(s.c_str()[0] == '-'){
      if(s.length() == 1)
	p.subtract();
      else
	p.pushNum(atoi(s.c_str()));
    }
    else
      p.pushNum(atoi(s.c_str()));
    cout << s << " ";
  }
  cout << "= " << p.getTopValue() << endl;
    return 0;
}
