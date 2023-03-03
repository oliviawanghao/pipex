/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hwang <hwang@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/18 16:03:50 by hwang         #+#    #+#                 */
/*   Updated: 2022/04/18 16:03:55 by hwang         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strdup(char *src)
{
	int		i;
	char	*dup;

	i = 0;
	while (src[i])
	{
		i++;
	}
	dup = (char *)malloc(i + 1);
	if (!dup)
		return (0);
	dup[i] = 0;
	while (i > 0)
	{
		i--;
		dup[i] = src[i];
	}
	return (dup);
}
