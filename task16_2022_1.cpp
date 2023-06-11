#include <iostream>
class Base {
private:
  virtual void do_run() { std::cout << 1; }
public:
  void run() {
    do_run();
  }
};
class A : public Base {
public:
  virtual void do_run() override { std::cout << 2; }
};
int main() {
  A a; // creates both Base and A
  a.run(); // A itself has no function run, so it calls the one in Base. What happens there?
           // BASE::do_run()? Nope, its virtual (override is optional)! unvirtualling the base
           // results in 1!
  a.do_run(); // That's A::do_run() (for obvious reasons)
}
// answer : 22