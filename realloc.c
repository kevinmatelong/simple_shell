#include "shell.h"

/**
 **_memset - fills memory with a constant byte
 *@t: the pointer to the memory area
 *@c: the byte to fill *t with
 *@m: the amount of bytes to be filled
 *Return: (t) a pointer to the memory area t
 */
char *_memset(char *t, char c, unsigned int m)
{
	unsigned int i;

	for (i = 0; i < m; i++)
		t[i] = c;
	return (t);
}

/**
 * ffree - frees a string of strings
 * @pp: string of strings
 */
void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * _realloc - reallocates a block of memory
 * @ptr: pointer to previous malloc'ated block
 * @old_size: byte size of previous block
 * @new_size: byte size of new block
 *
 * Return: pointer to da ol'block nameen.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *o;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!o)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		o[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (o);
}
