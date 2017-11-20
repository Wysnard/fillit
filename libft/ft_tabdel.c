#include "libft.h"

void	ft_tabdel(char **tab)
{
	char	**tmp;

	tmp = tab;
	while (tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(tmp);
	tab = NULL;
}
