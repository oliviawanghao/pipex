/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hwang <hwang@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/18 16:02:51 by hwang         #+#    #+#                 */
/*   Updated: 2022/04/18 16:02:54 by hwang         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*ret;
	char		d;

	d = (char)c;
	ret = s;
	while (*s != '\0')
		s++;
	while (s >= ret)
	{
		if (*s == d)
			return ((char *)s);
		s--;
	}
	return (0);
}
