#include "asm.h"

char	*btoh(char *str)
{
	int n;

	n = btoi(str);
	return (pf_hex(n));
}
