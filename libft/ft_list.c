#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	list->content = content;
	list->next = NULL;
	return (list);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

int	ft_lstsize(t_list *lst)
{
	int 	cnt;
	t_list	*tmp;
	
	if (!lst)
		return (0);
	cnt = 1;
	tmp = lst;
	while (tmp->next)
	{
		tmp = tmp->next;
		cnt++;
	}
	return (cnt);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp && tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	tmp = ft_lstlast(*lst);
	tmp->next = new;
}

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
	lst = NULL;
}

void	ft_lstdelone_inlist(t_list **lst, t_list *elem, void (*del)(void *))
{
	t_list	*prev;

	prev = *lst;
	while (prev->next != elem)
		prev = prev->next;
	prev->next = elem->next;
	ft_lstdelone(elem, del);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
    t_list  *current;
    t_list  *next;

    if (lst && *lst)
    {
        current = *lst;
        while (current)
        {
            next = current->next;
            ft_lstdelone(current, del);
            current = next;
        }
        *lst = NULL;
    }
}
