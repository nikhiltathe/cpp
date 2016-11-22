#include <iostream>
using namespace std;
class A {
  int n;
protected:
 A(int i) : n(i) { }
 virtual int get() = 0;
 virtual void print() = 0;
}; //End of class A


int A::get() {
  return n;
}

class B : private A {
protected:
  B(int i) : A(i) {}
   // Write the code here
public:
  int get() {
    return A::get();
 }
  void print() {
    get();
  }
}; // End of class B
   
class C : public B {
public:
  C(int i) : B(i) {}
  void print() {
      cout << get() ;
  }
}; //End of class C

int main(){
  int n;
  cin >> n;
  B *b1 = new C(4);
  b1->print();
  C *p = new C(n);
  p->print();
  return 0;
}
