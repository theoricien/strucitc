struct x
{
  int a;
}

int main ()
{
  struct x *p;
  int *p1;
  void *p2;
  int *(*p3)();
  void *(*p4)();
  struct x *(*p5)();
  
  return 0;
}
