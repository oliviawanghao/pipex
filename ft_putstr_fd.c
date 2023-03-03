/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: hwang <hwang@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/16 13:59:50 by hwang         #+#    #+#                 */
/*   Updated: 2022/03/16 13:59:52 by hwang         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}
