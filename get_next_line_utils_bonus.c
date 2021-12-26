/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 20:29:37 by aboumadi          #+#    #+#             */
/*   Updated: 2021/12/10 00:22:17 by aboumadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen_bonus(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin_bonus(char *str, char *buff)
{
	unsigned int	i;
	unsigned int	j;
	char			*s3;

	if (!str)
	{
		str = (char *) malloc(1 * sizeof(char));
		str[0] = '\0';
	}
	s3 = (char *)malloc((ft_strlen_bonus(str) + ft_strlen_bonus(buff) + 1));
	if (s3 == NULL)
		return (NULL);
	j = ft_strlen_bonus(str);
	i = 0;
	while (str[i] != '\0')
	{
		s3[i] = str[i];
		i++;
	}
	i = 0;
	while (buff[i] != '\0')
		s3[j++] = buff[i++];
	s3[j] = '\0';
	free(str);
	return ((char *)s3);
}

char	*ft_strchr_bonus(char *str, char c)
{
	int		i;
	char	c2;

	c2 = c;
	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != c2 && str[i] != '\0')
		i++;
	if (str[i] == c2)
		return ((char *)str + i);
	return (0);
}
