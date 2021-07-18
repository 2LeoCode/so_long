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
