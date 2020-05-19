extern void * malloc (int);
extern int printd (void *);

int main (int argc, int *argv)
{
  int a, b, i;
  a = 1 + 2 * 3 && 4 / 5 * 6 - 7 || 8;

  for (int i = 0; i < 10; i = i + 1)
  {
      printd(i);
  }

  return 0;
}
