#include "stringc.h"

int main() {
  StringC str("Hello ");
  str.join("World");
  str.ptrstr();
  return 0;
}
