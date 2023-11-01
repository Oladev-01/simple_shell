#include <stdio.h>
#include <unistd.h>
#define BIT_SIZE (sizeof(int) * 8)
/**
 * get_bit - this function returns the bit at any given index
 *@n: this is the integer passed
 *@index: this is the given index, starting from 0
 *Return: value of the bit at the index for success
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int bit;
	unsigned int index_check = BIT_SIZE - 1;

	if (index > index_check)
		return (-1);
	return ((n >> index) & 1);
}

