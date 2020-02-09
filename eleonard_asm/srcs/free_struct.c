#include "asm.h"

void	free_struct(t_s *s)
{
	int i;
	int k;

	ft_strdel(&s->byte_code);
	i = 0;
	while (i < s->size)
	{
		ft_strdel(&s->op[i]->name);
		k = 0;
		while (s->op[i]->l[k])
			ft_strdel(&s->op[i]->l[k++]);
		ft_memdel((void**)&s->op[i]->l);
		k = 0;
		while (s->op[i]->value[k])
		{
			ft_strdel(&s->op[i]->value[k]);
			k++;
		}
		ft_strdel((char**)&s->op[i]->value);
		ft_memdel((void**)&s->op[i]);
		i++;
	}
	ft_memdel((void**)&s->op);
	k = 0;
	while (k < s->labels->label_index)
		ft_strdel(&s->labels->labels[k++]);
	ft_memdel((void**)&s->labels->line);
	ft_memdel((void**)&s->labels->labels);
	ft_memdel((void**)&s->labels);
	ft_memdel((void**)&s);
}