/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hwang <hwang@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/18 14:55:43 by hwang         #+#    #+#                 */
/*   Updated: 2022/04/18 14:56:13 by hwang         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strchr(const char *s, int c)
{
	char	d;

	d = (char)c;
	while (*s && *s != d)
		s++;
	if (*s == d)
		return ((char *)s);
	return (0);
}
