#include <limits.h>
#include <map>
using namespace std;


class RecurCollatz {
  map<long long, unsigned> steps_memo;

public:
  unsigned get_collatz(long long n) {
    if (steps_memo.find(n) != steps_memo.end()) {
      return steps_memo[n];
    }

    if (n < 2) {
      return 1;
    }

    if ((n & 1) == 0) {
      return 1 + get_collatz(n / 2);
    } else {
      return 1 + get_collatz(3 * n + 1);
    }
  }
};


int main() {
  RecurCollatz mem;
  long long n = 0;
  int steps = 0;
  while (n < LLONG_MAX) {
    steps = mem.get_collatz(n);
    printf("%llu : %u\n", n, steps);
    n += 1;
  }
}
