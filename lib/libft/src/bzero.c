/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzero.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:31:47 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/22 12:31:48 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned long	*qword;
	unsigned char	*byte;

	qword = (unsigned long *)s;
	while (n >= sizeof(long))
	{
		*(qword++) = 0L;
		n -= sizeof(long);
	}
	byte = (unsigned char *)qword;
	while (n--)
		*(byte++) = '\0';
}
