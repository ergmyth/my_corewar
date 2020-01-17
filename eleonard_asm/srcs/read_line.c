#include "asm.h"

static int      is_label(char *label)
{
    int i;

    i = 0;
    while (label[i])
    {

        i++;
    }
}

void            read_line(char *line, t_s *s)
{
    char    *label;
    int     label_c_index;
    char    *end_of_string;
    char    *str;

    label_c_index = get_symbol_index(line, LABEL_CHAR); //Удалять первые пробелы?
    label = ft_strsub(line, 0, label_c_index);
    if (is_label(label))
    end_of_string = ft_strsub(line, label_c_index + 1, ft_strlen(line) - label_c_index - 1);
}
