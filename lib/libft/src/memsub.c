/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memsub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:33:08 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/22 12:33:08 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memsub(const void *s, size_t len, unsigned start, size_t n)
{
	if (len < start)
		return (ft_memdup("", 0));
	return (ft_memndup(s + start, len - start, n));
}
