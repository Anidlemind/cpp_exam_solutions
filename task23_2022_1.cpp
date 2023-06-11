// tricky!
#include <iostream>
class Mom { // this dumb fuck only weights 1 byte for different adresses of classes
            // empty classes generally weight 1 byte, I mean, classes with no fields
            // Functions weight nothing ig
public:
  Mom() { std::cout << "Mom"; }
};
class Son: virtual public Mom {};
class Daughter: public Mom {};

// interestingly weights of Son and Daughter differ. Son is 8 and Daughter is 1 byte.
// Why is that? Well... There is a rule that "empty" classes do not need to weight
// anything in case of a non-virtual derivation, in case of a virtual derivation though,
// there is a pointer to another class stored that weights exactly 8 bytes!

class Grandson: public Son, public Daughter {};

// this shithead somehow weights 16 bytes, but... why?
// well, my guess would be: it derives Son which is 8 and SOMEHOW it does not
// consider Daughter an empty class (maybe, just maybe - multiple derivation is an exception from that rule)
// so it adds 1. After all that the byte alignment
// kicks in and adds the remaining 7 to be a multiple of 8

// Derivation looks like this:
//
//       Mom
//      /   \
//  virtual  \
//    /       \
//   Son   Daughter
//     \      /
//      \    /
//     Grandson
//

int main() {
  Grandson g;
  std::cout << sizeof(g);
}

// answer : 16
