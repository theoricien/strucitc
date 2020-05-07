struct s {int a;};

/* Valeures de retour correctes */
int f1 ();
int *f2 ();
void f3 ();
struct s *f4();

/* Arguments correctes */
void f5 (int);
void f6 (int *);
void f7 (void *);
void f8 (struct s *);
void f9 (int *(*)());
void f10 (void *(*)());
void f11 (struct s *(*)());

int main ()
{
  return 0;
}
