/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:30:34 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/10/22 12:30:35 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCEPTION_H
# define EXCEPTION_H

# include <unistd.h>

typedef void	(*t_exception)(void);

void	bad_alloc(void);
void	runtime_error(void);
void	invalid_arguments(void);
void	invalid_map(void);

int		exception(t_exception except);

#endif
