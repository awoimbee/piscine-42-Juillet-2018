/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 18:20:55 by awoimbee          #+#    #+#             */
/*   Updated: 2018/07/25 22:30:24 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex00/ft_btree.h"

void	btree_apply_prefix(t_btree *root, void (*applyf)(void *));
void	btree_apply_infix(t_btree *root, void (*applyf)(void *));
void	btree_apply_suffix(t_btree *root, void (*applyf)(void *));
void	btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *));
void	*btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *, void *));
int		btree_level_count(t_btree *root);
void	btree_apply_by_level(t_btree *root, void (*applyf)(void *item, int current_level, int is_first_elem));

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

void	print_elem(void *elem)
{
	printf("%s", elem);
	printf("%s", " ");
}

int		cmp(void *a, void *b)
{
	return (strcmp((char*)a, (char*)b));
}
int		atoi_cmp(void *a, void *b)
{
	return ( atoi((char*)a) - atoi((char*)b) );
}
void	ex7_applyf(void *item, int current_level, int is_first_elem)
{
	char *itemc = item;
	if (is_first_elem == 1)
		*itemc = (char)35;
	else
		*itemc = (char)36;
	printf("%s", "\nis first & current level: ");
	printf("%d", is_first_elem);
	printf("%s", " - ");
	printf("%d", current_level);
}

int		main(int argc, char **argv)
{
	
	printf("%s", "A crash here means a problem with btree_insert_data:");
	t_btree	*tree;
	char testdata[][13] = {"1", "2", "3", "4", "1", "2", "3", "4", "1", "2", "3", "4", "-1"};
	for (int i = 0; i < 13; ++i)
		btree_insert_data(&tree, testdata[i], &atoi_cmp);
	t_btree	*tree2;
	char testdata2[19][19] = {"1", "2", "3", "4", "1", "2", "3", "4", "1", "2", "3", "4", "-1", "-9", "-1", "-100", "-10", "-11", "-58"};
	for (int i = 0; i < 19; ++i)
		btree_insert_data(&tree2, testdata2[i], &atoi_cmp);
	printf("%s", " all good\n");


	printf("%s", "\n##### btree_apply_infix (ex02) #####\n");
	btree_apply_infix(tree, &print_elem);
	printf("%s", "\n-1 1 1 1 2 2 2 3 3 3 4 4 4 <- these 2 should match\n");
	btree_apply_infix(0, &print_elem);


	printf("%s", "\n##### btree_apply_prefix (ex01) #####\n");
	btree_apply_prefix(tree, &print_elem);
	printf("%s", "\n1 -1 2 1 1 3 2 2 4 3 3 4 4 <- these 2 should match\n");
	btree_apply_prefix(tree2, &print_elem);
	printf("%s", "\n1 -1 -9 -100 -10 -11 -58 -1 2 1 1 3 2 2 4 3 3 4 4 <- these 2 should match\n");
	btree_apply_prefix(0, &print_elem);


	printf("%s", "\n##### btree_apply_suffix (ex03) #####\n");
	btree_apply_suffix(tree, &print_elem);
	printf("%s", "\n-1 1 1 2 2 3 3 4 4 4 3 2 1 <- these 2 should match\n");
	btree_apply_suffix(tree2, &print_elem);
	printf("%s", "\n-58 -11 -10 -100 -9 -1 -1 1 1 2 2 3 3 4 4 4 3 2 1 <- these 2 should match\n");
	btree_apply_suffix(0, &print_elem);


	printf("%s", "\n##### SEARCH (ex05) #####\n");
	printf("%s", "should print \"4\": ");
	printf("%s", btree_search_item(tree, (void*)"4", &cmp));
	printf("%s", "\nshould print \"-1\": ");
	printf("%s", btree_search_item(tree, (void*)"-1", &cmp));
	printf("%s", "\nshould print \"(null)\": ");
	printf("%s", btree_search_item(tree, (void*)"42", &cmp));
	if (btree_search_item(0, (void*)"42", &cmp) != 0)
		printf("%s", "ERROR WITH NULL POINTER");


	printf("%s", "\n\n##### btree_level_count (ex06) #####\n");
	printf("%s", "should print \"6\": ");
	printf("%d", btree_level_count(tree));
	printf("%s", "\nshould print \"7\": ");
	printf("%d", btree_level_count(tree2));
	printf("%s", "\nshould print \"0\": ");
	printf("%d", btree_level_count(0));
	

	printf("%s", "\n\n##### btree_apply_by_level (ex07) #####\n");
	btree_apply_by_level(tree2, ex7_applyf);
	printf("%s", "\n empty pointer should return nothing :\n");
	btree_apply_by_level(0, ex7_applyf);

	write(1, "\n", 1);

	(void)argc;
	(void)argv;
	return (0);
}
