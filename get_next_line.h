#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

size_t  ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char    *ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char    *get_line(char *res);
char    *res_update(char *res);
char    *ft_read(int fd, char *res);

#endif