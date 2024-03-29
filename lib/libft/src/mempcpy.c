/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mempcpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:33:04 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/22 12:33:04 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void	*_ft_mempcpy(unsigned char *dst, const unsigned char *src, size_t n)
{
	if (n)
		dst[0] = src[0];
	if (n > 1)
		dst[1] = src[1];
	if (n > 2)
		dst[2] = src[2];
	if (n > 3)
		dst[3] = src[3];
	if (n > 4)
		dst[4] = src[4];
	if (n > 5)
		dst[5] = src[5];
	if (n > 6)
		dst[6] = src[6];
	return ((void *)dst + n);
}

void	*ft_mempcpy(void *dst, const void *src, size_t n)
{
	unsigned long	*qword_dst;
	unsigned long	*qword_src;

	if (!(dst || src) || !n)
		return (dst);
	qword_dst = (unsigned long *)dst;
	qword_src = (unsigned long *)src;
	while (n >= sizeof(long))
	{
		*(qword_dst++) = *(qword_src++);
		n -= sizeof(long);
	}
	return (_ft_mempcpy((unsigned char *)qword_dst, (unsigned char *)qword_src,
			n));
}
