/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:33:00 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/22 12:33:00 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned long	*qword_dst;
	unsigned long	*qword_src;
	unsigned char	*byte_dst;
	unsigned char	*byte_src;

	if (!(dst || src))
		return (dst);
	if (dst < src)
		return (ft_memcpy(dst, src, len));
	qword_dst = (unsigned long *)(dst + len);
	qword_src = (unsigned long *)(src + len);
	while (len >= sizeof(long))
	{
		*(--qword_dst) = *(--qword_src);
		len -= sizeof(long);
	}
	byte_dst = (unsigned char *)qword_dst;
	byte_src = (unsigned char *)qword_src;
	while (len--)
		*(--byte_dst) = *(--byte_src);
	return (dst);
}
