#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>

char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);
int		ft_strchr(const char *s, int c, int out);
char	*get_next_line(int fd);
int		ft_strlen(char *str);
char	*ft_substr(char const *s, int start, size_t len);

#endif