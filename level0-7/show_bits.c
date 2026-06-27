# include <unistd.h>

void show_bits(unsigned char octet)
{
    int i = 8;
    char buff[9];
    while(i)
    {
        if(octet & 1)
            buff[i] = '1';
        else
            buff[i] = '0';
        octet = octet >> 1;
        i--;
    }
    write(1, buff, 9);
}
int main()
{
    show_bits(200);
}
