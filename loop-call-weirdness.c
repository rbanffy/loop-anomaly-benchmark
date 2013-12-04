const unsigned N = 400 * 1000 * 1000;
 
volatile unsigned long long counter = 0;
 
// Don't inline the benchmarking code into main
void __attribute__((noinline)) tightloop();
void __attribute__((noinline)) loop_with_extra_call();
 
void tightloop() {
  unsigned j;
  for (j = 0; j < N; ++j) {
    counter += j;
  }
}
 
void foo() {
}
 
void loop_with_extra_call() {
  unsigned j;
  for (j = 0; j < N; ++j) {
    __asm__("call foo");
    counter += j;
  }
}
 
int main(int argc, char** argv) {
  if (argc <= 1) {
    return 1;
  }
 
  if (argv[1][0] == 't') {
    tightloop();
  } else if (argv[1][0] == 'c') {
    loop_with_extra_call();
  }
 
  return 0;
}
