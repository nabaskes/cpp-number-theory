#include <limits.h>
#include <stdio.h>

int collatz_steps(long long input) {
  long steps = 0;

  while (input > 1) {
    if (input % 2 == 0) {
      input = input / 2;
    } else {
      input = 3 * input + 1;
    }
    steps += 1;
  }

  return steps;
}

int main() {
  long long n = 0;
  int steps = 0;
  while (n < LLONG_MAX) {
    steps = collatz_steps(n);
    printf("%llu : %lu\n", n, steps);
    n += 1;
  }
}
