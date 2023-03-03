/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hwang <hwang@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/16 14:00:08 by hwang         #+#    #+#                 */
/*   Updated: 2022/03/16 14:00:10 by hwang         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strcheck(const char *haystack, const char *needle,
						size_t h, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	n;
	char	*ret;

	i = 0;
	j = 0;
	ret = (char *)haystack;
	while (i + h <= len && len != 0)
	{
		j = 0;
		n = i;
		while (haystack[n] == needle[j] && j < h)
		{
			n++;
			j++;
		}
		if (needle[j] == '\0')
			return (ret);
		ret++;
		i++;
	}
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	h;

	if (!*needle)
		return ((char *)haystack);
	if (!*haystack)
		return (0);
	h = ft_strlen(needle);
	return (ft_strcheck(haystack, needle, h, len));
}
