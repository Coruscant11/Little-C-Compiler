extern int printd( int i );

int main() {
  int i,j,k;
  i = 45000;
  j = -123;
  k = 43;
  printd(((i+j)*k/100+j*k*i-j<<k)/(k-j>>2));
  return 0;
}
