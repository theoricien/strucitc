int sum (int, int);

int main (void)
{
  int (*ptr)(int, int) = sum;
  printf("%d", ptr(1, 2));
}

int sum (int a, int b)
{
  return a+b;
}
