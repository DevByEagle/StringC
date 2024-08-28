#include "StringC.h"

int main() {
  StringC str = strcreat("Hello");
  join(&str, " World");
  ptrstr(&str);
  return 0;
}
