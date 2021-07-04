#include <garbage.h>

int	gblst_push(t_gblst **lst_ptr, void *data, t_destructor destructor)
{
	t_gblst	*new_member;

	new_member = malloc(sizeof(t_gblst));
	if (!new_member)
		return (-1);
	new_member->data = data;
	new_member->destructor = destructor;
	new_member->next = *lst_ptr;
	*lst_ptr = new_member;
	return (0);
}
