int main() {
    int j;
    int i = 0;
    {
        int a = 2;
    }
    int b = 3;
    int (*ptr)(int, int) = sum;
    b = (i + 1) + 3;
    return a + b;
}
