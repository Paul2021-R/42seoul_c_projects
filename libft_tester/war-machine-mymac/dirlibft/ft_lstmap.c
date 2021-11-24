/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:02:03 by haryu             #+#    #+#             */
/*   Updated: 2021/11/24 15:28:59 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*temp;	

	result = ft_lstnew(f(lst -> content));
	if (!lst || !f || !result)
		return (NULL);
	temp = result;
	lst = lst -> next;
	while (lst)
	{
		temp -> next = ft_lstnew(f(temp -> content));
		if (!temp)
		{
			ft_lstclear(&result, del);
			return (0);
		}
		temp = temp -> next;
		lst = lst -> next;
	}
	return (result);
}
/*
필요한 부분, list 사이즈에 맞춰서 새로운 t_list ㅂ생성 
신규 리스트 생성
최초에 실행시, 이후 값을 집어 넣을 때, 제대로 작동 안할시 list 전체를 싹 지우는 용도로 ft_lstclear사용
신규 리스트에 값 f() 집어 넣기. 

*/
