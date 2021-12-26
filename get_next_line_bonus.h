/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 21:03:37 by aboumadi          #+#    #+#             */
/*   Updated: 2021/12/10 00:06:44 by aboumadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line_bonus(int fd);
char	*ft_strjoin_bonus(char *str, char *buff);
int		ft_strlen_bonus(char *str);
char	*ft_strchr_bonus(char *str, char c);
#endif
