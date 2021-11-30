#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (s != NULL)
	{
		while (s[len])
			len++;
	}
	return (len);
}

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		i;

	i = 0;
	dest = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!dest)
		return (NULL);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	int		j;
	int		i;

    if (!s1 || !s2)
        return (NULL);
	dest = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)+ 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		dest[i] = s2[j];
		i++;
		j++;
	}
	dest[i] = 0;
	free(s1);
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	char			*src;
	unsigned char	ch;
	int				i;

    if (s == NULL)
        return (NULL);
	src = (char *)s;
	ch = (unsigned char)c;
	i = 0;
	while (src[i])
	{
		if (src[i] == ch)
			break ;
		i++;
	}
	if (src[i] == ch)
		return (&src[i]);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if ((long int)len < 0)
		return (NULL);
	if (len > s_len)
		len = s_len;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	i = 0;
	if (start < s_len)
	{
		while (i < len && s[start])
		{
			dest[i++] = s[start];
			start++;
		}
	}
	dest[i] = 0;
	return (dest);
}


char    *get_line(char *res)
{
    char *line;
    int     len;

    if (res[0] == '\0')
        return (NULL);
    len = 0;
    while (res[len] != '\n' && res[len] !='\0' )
        len++;
    if (res[len] == '\n')
        len++;
    
    line = ft_substr(res, 0, len);
    return (line);
}

char *res_update(char *res)
{
    char *tmp;
    size_t start;
    size_t len;
    int i;

    start = 0;
    i = 0;
    while (res[start] != '\n' && res[start] !='\0' )
        start++;
    if (res[start] == '\n')
        start++;
    if (res[start] == '\0')
    {
        free (res);
        return NULL;
    }
    tmp = malloc(sizeof(char) * (ft_strlen(res) - start + 1));
    if (tmp == NULL)
        return (NULL);
    while (res[start] != '\0')
    {
        tmp[i++] = res[start++];
    }
    tmp[i] = '\0';
    free(res);
    return (tmp);
}


char *ft_read(int fd, char *res)
{
    char *buf;
    int n;

    buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
    if (buf == NULL)
        return (NULL);
    if (res == NULL)
        res = ft_strdup("");
    n = 1;
    while (n != 0 && ft_strchr(res ,'\n') == NULL)
    {
        n = read(fd, buf, BUFFER_SIZE);
        if (n < 0)
        {
            free(res);
            free(buf);
            return (NULL);
        }
        buf[n] = '\0';
        res = ft_strjoin(res, buf);
    }
    free(buf);
    return(res);

}