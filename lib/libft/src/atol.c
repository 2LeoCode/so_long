/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atol.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:31:39 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/22 12:31:40 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

long	ft_atol(const char *s)
{
	const long long	n = ft_atoll(s);

	if ((n >= LLONG_MAX) || (n < LLONG_MIN))
		return (-1L);
	if ((n > LONG_MAX) || (n < LONG_MIN))
		return (0L);
	return ((long)n);
}
