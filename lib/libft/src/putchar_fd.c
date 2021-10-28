/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putchar_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:33:48 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/22 12:33:48 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_putchar_fd(int c, int fd)
{
	const unsigned char	ch = (unsigned char)c;

	return (write(fd, &ch, sizeof(char)));
}
