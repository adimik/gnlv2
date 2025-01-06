#include "get_next_line.h"

static char	*put_nl(char **st, int fd)
{
	char	*nl;
	int		i;
	char	*t;

	if (st[fd] == NULL)
		return (NULL);
	i = ft_strchr(st[fd], '\n', 1);
	nl = ft_substr(st[fd], 0, i);
	if (st[fd][i] != '\0')
	{
		t = ft_strdup(&st[fd][i]);
		free(st[fd]);
		st[fd] = t;
		if (st[fd][0] == '\0')
		{
			free(st[fd]);
			st[fd] = NULL;
		}
	}
	else
	{
		free(st[fd]);
		st[fd] = NULL;
	}
	return (nl);
}

static char	*update_st(char *buf, int fd, int size)
{
	static char	*st[4096];
	char		*t;

	while (size > 0)
	{
		buf[size] = '\0';
		if (st[fd] != NULL)
		{
			t = ft_strjoin(st[fd], buf);
			free(st[fd]);
			st[fd] = t;
		}
		else
			st[fd] = ft_strdup(buf);
		if (ft_strchr(st[fd], '\n', 0) != 0)
			break ;
		size = read(fd, buf, BUFFER_SIZE);
	}
	return (put_nl(st, fd));
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	int			size;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	size = read(fd, buf, BUFFER_SIZE);
	return (update_st(buf, fd, size));
}
