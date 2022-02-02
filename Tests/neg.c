extern int printd( int i );

int main() {
  int j;
  j = 123;
  printd(-j);
  printd(-123);
  printd(-(123+0));
  printd(-(j+0));
  return 0;
}
