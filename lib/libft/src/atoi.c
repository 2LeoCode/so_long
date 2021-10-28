/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:31:35 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/22 12:31:36 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_atoi(const char *s)
{
	const long long	n = ft_atoll(s);

	if ((n >= LONG_MAX) || (n < LONG_MIN))
		return (-1);
	if ((n > INT_MAX) || (n < INT_MIN))
		return (0);
	return ((int)n);
}
