#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_insert_left - inserts a node as the left child of another node
 * @parent: a pointer to the node to insert the left child in
 * @value: the value to store in the new node
 *
 * Return: a pointer to the created node
 * OR NULL on failure, or if parent is NULL.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = binary_tree_node(parent, value);

	if (parent == NULL || new_node == NULL)
	{
		free(new_node);
		return (NULL);
	}

	new_node->left = parent->left;
	if (parent->left)
	{
		new_node->left->parent = new_node;
	}
	parent->left = new_node;

	return (new_node);
}
