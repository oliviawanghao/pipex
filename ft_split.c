/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: hwang <hwang@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/16 13:59:57 by hwang         #+#    #+#                 */
/*   Updated: 2022/04/18 16:26:57 by hwang         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strcount(char *s, char c)
{
	int	n;

	n = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s == '\0')
			break ;
		while (*s != c && *s != '\0')
			s++;
		n++;
	}
	return (n);
}

void	ft_writestr(char **ret, char *tmp, int slen)
{
	int	i;

	*ret = (char *)malloc(slen + 1);
	if (!ret)
		return ;
	i = 0;
	while (i < slen)
	{
		**ret = *tmp;
		(*ret)++;
		tmp++;
		i++;
	}
	**ret = '\0';
	(*ret) -= i;
}

char	**ft_strsplit(char **ret, char const *s, char c, int retc)
{
	int		slen;
	char	*tmp;

	while (*s)
	{
		slen = 0;
		while (*s == c)
			s++;
		tmp = (char *)s;
		while (*s != c && *s != '\0')
		{
			slen++;
			s++;
		}
		ft_writestr(&ret[retc], tmp, slen);
		while (*s == c && *s)
			s++;
		retc++;
	}
	ret[retc] = 0;
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	int		strcount;
	char	**ret;
	int		retc;

	if (!s)
		return (0);
	retc = 0;
	strcount = ft_strcount((char *)s, c);
	ret = malloc((strcount + 1) * sizeof(char *));
	if (!ret)
		return (0);
	if (strcount == 0)
	{
		ret[retc] = 0;
		return (ret);
	}
	else
		return (ft_strsplit(ret, s, c, retc));
}
