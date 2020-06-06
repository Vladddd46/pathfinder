#include "libmx.h"

/*
Данная функция сортирует связной список по принципу:
1) При route_list->start == route->list->end => сравнивает tmp->c
и route_list->c и зачищает тот узел, у которого значение ->c больше
2) Зачищает повторения =>  tmp->c == route_list->c 
						   tmp->a == route_list->a && tmp->b == route_list->b
						   tmp->a == route_list->b && tmp->b == route_list->a
*/

void mx_sort_route_list2(r_list *new_route_list)
{

	r_list *tmp = new_route_list;
 	while (tmp)
 	{

 		r_list *tmp_2 = tmp -> next;
 		while(tmp_2)
 		{
 			if (mx_strcmp(tmp_2->s, tmp ->s) == 0 && mx_strcmp(tmp_2->e, tmp ->e) == 0)
 			{
 				if (tmp_2->c > tmp->c)
 				{
 					tmp_2->s = "NULL";
 					tmp_2->m = "NULL";
 					tmp_2->e = "NULL";
 					tmp_2->a = 10000;
 					tmp_2->b = 10000;
 					tmp_2->c = 10000;
 				}
 				else if (tmp_2->c < tmp->c)
 				{
 					tmp->s = "NULL";
 					tmp->m = "NULL";
 					tmp->e = "NULL";
 					tmp->a = 10000;
 					tmp->b = 10000;
 					tmp->c = 10000;
 				}

 				if (tmp->a == tmp_2->a && tmp->b == tmp_2->b && tmp->c == tmp_2->c)
 				{
 					tmp_2->s = "NULL";
 					tmp_2->m = "NULL";
 					tmp_2->e = "NULL";
 					tmp_2->a = 10000;
 					tmp_2->b = 10000;
 					tmp_2->c = 10000;
 				}
 				else if (tmp->a == tmp_2->b && tmp->b == tmp_2->a && tmp->c == tmp_2->c)
 				{
 					tmp_2->s = "NULL";
 					tmp_2->m = "NULL";
 					tmp_2->e = "NULL";
 					tmp_2->a = 10000;
 					tmp_2->b = 10000;
 					tmp_2->c = 10000;
 				}


 			}
 			tmp_2 = tmp_2 -> next;
 		}
 		

 		tmp = tmp -> next;
 	}
}









