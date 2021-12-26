/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 20:12:02 by aboumadi          #+#    #+#             */
/*   Updated: 2021/12/11 18:09:21 by aboumadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*check(char *str)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (0);
	}
	tmp = (char *)malloc((ft_strlen(str) - i + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	i++;
	while (str[i])
		tmp[j++] = str[i++];
	tmp[j] = '\0';
	free(str);
	return (tmp);
}

char	*print_line(char *str)
{
	int		i;
	char	*string;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	string = (char *)malloc((i + 2) * sizeof(char));
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		string[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		string[i++] = '\n';
	string[i] = '\0';
	return (string);
}

char	*n_read(int fd, char *str)
{
	int		r;
	char	*buff;

	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	r = 1;
	while (r > 0)
	{
		r = read(fd, buff, BUFFER_SIZE);
		if (r == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[r] = '\0';
		str = ft_strjoin(str, buff);
		if (ft_strchr(str, '\n'))
			break ;
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*tmp;

	if ((fd < 0) || (BUFFER_SIZE <= 0))
		return (NULL);
	str = n_read(fd, str);
	if (!str)
		return (NULL);
	tmp = print_line(str);
	str = check(str);
	if (tmp[0] == '\0')
	{
		free(str);
		free(tmp);
		return (NULL);
	}
	return (tmp);
}
