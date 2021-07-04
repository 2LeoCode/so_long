#include <so_long.h>

t_vec2	*make_vec2(int x, int y)
{
	t_vec2	*vec;

	vec = malloc(sizeof(t_vec2));
	if (!vec)
		return (NULL);
	vec->x = x;
	vec->y = y;
	return (vec);
}

int	vec2_cmp(const void *a, const void *b)
{
	const t_vec2	*va = (t_vec2 *)a;
	const t_vec2	*vb = (t_vec2 *)b;

	if (va->x < vb->x)
		return (-1);
	if (va->x > vb->x)
		return (1);
	if (va->y < vb->y)
		return (-1);
	if (va->y > vb->y)
		return (1);
	return (0);
}
