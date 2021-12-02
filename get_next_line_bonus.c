/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-maza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:48:51 by rel-maza          #+#    #+#             */
/*   Updated: 2021/12/02 11:48:53 by rel-maza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

char	*get_line(char *res)
{
	char	*line;
	int		len;

	if (res[0] == '\0')
		return (NULL);
	len = 0;
	while (res[len] != '\n' && res[len] != '\0')
		len++;
	if (res[len] == '\n')
		len++;
	line = ft_substr(res, 0, len);
	return (line);
}

char	*res_update(char *res)
{
	char	*tmp;
	size_t	start;
	int		i;

	start = 0;
	i = 0;
	while (res[start] != '\n' && res[start] != '\0')
		start++;
	if (res[start] == '\n')
		start++;
	if (res[start] == '\0')
	{
		free(res);
		return (NULL);
	}
	tmp = malloc(sizeof(char) * (ft_strlen(res) - start + 1));
	if (tmp == NULL)
		return (NULL);
	while (res[start] != '\0')
		tmp[i++] = res[start++];
	tmp[i] = '\0';
	free(res);
	return (tmp);
}

char	*ft_read(int fd, char *res)
{
	char	*buf;
	int		n;

	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buf == NULL)
		return (NULL);
	if (res == NULL)
		res = ft_strdup("");
	n = 1;
	while (n != 0 && ft_strchr(res, '\n') == NULL)
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
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*res[1000];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	//files
	
	res[fd] = ft_read(fd, res[fd]);
	if (res[fd] == NULL)
		return (NULL);
	line = get_line(res[fd]);
	res[fd] = res_update(res[fd]);
	return (line);
}

int	main(int ac, char **av){
	int fd1,fd2;
	int i;

	i = 0;
	if (!ac)
		return (0);
	fd1 = open(av[1], O_RDONLY);
	fd2 = open(av[2], O_RDONLY);
	printf("%d\n%d\n", fd1,fd2);
	char *ret;
	char *s;
	ret = "";
	s = "";
	while ((ret != NULL) || (s != NULL )){
		ret = get_next_line(fd1);
		s = get_next_line(fd2);
		printf("1=%s", ret);
		printf("2=%s", s);
	}
	
}

