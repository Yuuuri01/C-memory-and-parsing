# include <unistd.h>
# include <stdio.h>


unsigned int lcm(unsigned int a, unsigned int b)
{
    if(a == 0 || b == 0)
        return 0;
    unsigned int s1 = a;
    unsigned int s2 = b;
    unsigned int total = 0;

    while(b)
    {
        total = a % b;
        a = b;
        b = total;
    }
    return (s1 * s2) / a;
}
int main()
{
    printf("%d\n", lcm(4, 6));
}