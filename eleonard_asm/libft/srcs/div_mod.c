void	ft_div_mod(int a, int b, int *div, int *mod)
{
	if (b != 0)
	{
		*div = a / b;
		*mod = a % b;
		if (a < 0 && b > 0 && *mod)
		{
			*div = *div - 1;
			*mod += b;
		}
		else if (a < 0 && b < 0 && *mod)
		{
			*div = (a + b) / b;
			*mod = *div * -b + a;
		}
	}
}