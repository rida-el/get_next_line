/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-maza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:30:03 by rel-maza          #+#    #+#             */
/*   Updated: 2021/12/01 11:05:32 by rel-maza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*res;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	res = ft_read(fd, res);
	if (res == NULL)
		return (NULL);
	line = get_line(res);
	res = res_update(res);
	return (line);
}

// int	main(int ac, char **av){
// 	int fd;
// 	int i;

// 	i = 0;
// 	if (!ac)
// 		return (0);
// 	fd = open(av[1], O_RDONLY);
// 	printf("%d\n", fd);
// 	char *ret;
// 	while ((ret = get_next_line(fd)) != NULL ){
// 		printf("GNL=%s", ret);
// 		i++;
// 	}
// }