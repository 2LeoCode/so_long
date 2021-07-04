#include <garbage.h>

int	garbage(void *data, t_destructor destructor, t_gbaction action)
{
	static t_action_fun	gb_action[3] = {
		[push] = gb_action_push,
		[pop] = gb_action_pop,
		[clear] = gb_action_clear
	};
	static t_gblst				*lst = NULL;

	if ((*gb_action[action])(&lst, data, destructor))
	{
		(*destructor)(data);
		return (gb_error());
	}
	return (0);
}
