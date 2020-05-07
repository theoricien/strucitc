struct T {};

struct T {
	int x;
};

int direct_declarator(int *a, int *(*)(), int);

int
main()
{
	struct T v;

	int a = 3,b,c;

	{ struct T { int z; }; }
	v.x = 2;
	if(v.x != 2)
		return 1;
	return 0;
}
