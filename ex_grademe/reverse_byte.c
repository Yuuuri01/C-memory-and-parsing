unsigned char reverse_bits(unsigned char byte)
{
	return (((byte & 1) << 7) | ((byte & 2) << 5) | ((byte & 4) << 3) | ((byte & 8) << 1) | ((byte & 16) >> 1) | ((byte & 32) >> 3) | ((byte & 64) >> 5)  | ((byte & 128) >> 7));
}   
# include <stdio.h>
int main()
{
    printf("%d\n", reverse_bits(2));
}