extern int printd( int i );

int main() {
  int i,j;
  i = 45000;
  j = 3;
  printd(i>>j);
  printd(45000>>j);
  printd(i>>3);
  printd(45000>>3);
  printd(i>>(j+0));
  printd((i+0)>>j);
  printd((i+0)>>(j+0));
  printd((i+0)>>3);
  printd(45000>>(j+0));
  return 0;
}
