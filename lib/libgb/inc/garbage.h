#ifndef GARBAGE_H
# define GARBAGE_H

# include <stdlib.h>
# include <stdbool.h>
# include <stdint.h>

typedef void	*(*t_constructor)(void *);
typedef void	(*t_destructor)(void *);

typedef struct s_garbage_list
{
	void					*data;
	t_destructor			destructor;
	struct s_garbage_list	*next;
}	t_gblst;

typedef int		(*t_action_fun)(t_gblst **, void *, t_destructor);

int	gblst_push(t_gblst **lst_ptr, void *data, t_destructor destructor);
void	gblst_pop(t_gblst **lst_ptr);
void	gblst_clear(t_gblst **lst_ptr);

typedef enum e_garbage_action
{
	push,
	pop,
	clear
}	t_gbaction;

int	garbage(void *data, t_destructor destructor, t_gbaction action);

/*
**	USER OPERATIONS
*/
int	gb_push(void *data, t_destructor destructor);
int	gb_alloc_and_push(void *data_addr, size_t size);
int	gb_calloc_and_push(void *data_addr, size_t size);
int	gb_construct_and_push(void *data_addr, t_constructor constructor,
		void *constr_param, t_destructor destructor);
void	gb_pop(void);
void	gb_clear(void);

/*
**	ACTIONS
*/
int	gb_action_push(t_gblst **lst_ptr, void *data, t_destructor destructor);
int	gb_action_pop(t_gblst **lst_ptr, void *data, t_destructor destructor);
int	gb_action_clear(t_gblst **lst_ptr, void *data, t_destructor destructor);

/*
**	ERROR
*/
int	gb_error(void);

#endif
