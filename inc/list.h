#ifndef LIST_H
# define LIST_H

# include <stdlib.h>
# include <stdbool.h>
# include <stdint.h>
# include <stddef.h>
# include <stdio.h>

typedef int		(*t_cmpf)(void *, void *);
typedef void	(*t_destructor)(void *);

typedef struct s_list
{
	struct s_list	*prev;
	struct s_list	*next;
	void			*data;
	t_destructor	destructor;
	size_t			*size;
}	t_list;

void	lst_clear(t_list *sentinel);
void	lst_safe_clear(t_list *sentinel);
void	lst_destroy(void *sentinel);
void	lst_safe_destroy(t_list *sentinel);
int		lst_failure(t_list *sentinel, void *cur_data,
			t_destructor cur_destructor);

t_list	*lst_find(t_list *sentinel, void *dataref, t_cmpf cmp_fun);
t_list	*lst_rfind(t_list *sentinel, void *dataref, t_cmpf cmp_fun);
int		lst_init(t_list **lst_addr);
t_list	*lst_new(void);
void	lst_pop_front(t_list *sentinel);
void	lst_pop_back(t_list *sentinel);
void	lst_pop(t_list *node);
int		lst_pop_if(t_list *sentinel, void *dataref, t_cmpf cmp_fun);
int		lst_push_front(t_list *sentinel, void *data, t_destructor destructor);
int		lst_push_back(t_list *sentinel, void *data, t_destructor destructor);

#endif
