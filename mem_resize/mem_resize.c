#include <stdlib.h>
#include <stddef.h>


size_t min(size_t old, size_t new_size)
{
	return (old > new_size) ? new_size : old;
}
void	*mem_resize(void *ptr, size_t old_size, size_t new_size)
{
	unsigned char *str;
	unsigned char *ptr2 = (unsigned char *)ptr;
	size_t i = 0;
	str = malloc((new_size + 1) * sizeof(char)); 
	if(!str)
		return NULL;
	if(!ptr)
	{
		return (void *)str;
	}

	size_t mini = min(old_size, new_size);
	while(i < mini)
	{
		str[i] = ptr2[i];
		i++;
	}
	return str;
}