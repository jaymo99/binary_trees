#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_trees_ancestor - finds lowest common ancestor of two nodes.
 * @first: pointer to first node
 * @second: pointer to second node
 *
 * Return: pointer to the lowest common ancestor of the two nodes.
 * OR NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *first_ancestor;
	binary_tree_t *second_ancestor;

	if (first == NULL || second == NULL)
	{
		return (NULL);
	}

	if (first->parent == NULL || second->parent == NULL)
	{
		return (NULL);
	}

	first_ancestor = (binary_tree_t *)first;
	while (first_ancestor)
	{
		second_ancestor = (binary_tree_t *)second;
		while (second_ancestor)
		{
			if (first_ancestor == second_ancestor)
			{
				return (first_ancestor);
			}
			second_ancestor = second_ancestor->parent;
		}
		first_ancestor = first_ancestor->parent;
	}
	return (NULL);
}
