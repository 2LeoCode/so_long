#include <libft.h>void	ft_destroy_array(void **ar, unsigned int size){	unsigned int	i;	i = (unsigned int)(-1);	if (size == NULL_ENDED)	{		while (ar[++i])		{			free(ar[i]);			ar[i] = NULL;		}	}	else	{		while (++i < size)		{			free(ar[i]);			ar[i] = NULL;		}	}	free(ar);}