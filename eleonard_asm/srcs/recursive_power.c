int 	recursive_power(int n, int pow)
{
	if (pow == 0)
		return 1;
	return (n * recursive_power(n, pow - 1));
}
