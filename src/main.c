#include "fillit.h"
#include "libft.h"

int	main(int argc, char **argv)
{
	t_list	*list;
	int	fd;

	list = NULL;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (!(ft_read(fd, list)))
			ft_putstr_fd("Error\n", 2);
		ft_lstdelall(&list);
	}
	return (1);
}
