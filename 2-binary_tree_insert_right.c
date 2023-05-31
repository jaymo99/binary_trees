#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_insert_right - inserts a node as the right child of another node
 * @parent: a pointer to the node to insert the left child in
 * @value: the value to store in the new node
 *
 * Return: a pointer to the created node
 * OR NULL on failure, or if parent is NULL.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = binary_tree_node(parent, value);

	if (parent == NULL || new_node == NULL)
	{
		return (NULL);
	}

	new_node->right = parent->right;
	if (parent->right)
	{
		new_node->right->parent = new_node;
	}
	parent->right = new_node;

	return (new_node);
}
