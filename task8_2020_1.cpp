// stack-overflow example

void f() {
  f(); // infinite recursion!
       // for a recursive call of a function we need some memory as we need
       // to know where to come back after we are done with the function
       // but here we never come back! so the memory stacks up and overflows the
       // stack!
}

int main() {
  f(); // SIGSEGV! (RE caused by stack-overflow)
}