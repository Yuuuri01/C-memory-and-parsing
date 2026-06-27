# include <stdio.h>
#include <stddef.h>



size_t	strcspn(const char *s, const char *reject)
{
	size_t i = 0;
	while(s[i])
	{
		if(s[i] == *reject)
			return i;
		i++;
	}
	return i;
}
int main()
{
    printf("%d\n", strcspn("grep found nothing", "xyz"));
    printf("%d\n", strcspn("branch", "aeiou"));
    printf("%d\n", strcspn("", "abc"));
}
