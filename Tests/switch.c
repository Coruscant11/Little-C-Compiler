extern int printd(int i);

int main() {
   int i,j;
   i=3;
   switch(i) {
      case 0: printd(0); break;
      case 1: printd(1); break;
      case 2: printd(2); break;
      case 3: printd(3); 
      case 4: printd(4);
      default: printd(-1);
   }
}
