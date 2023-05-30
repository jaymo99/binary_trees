#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree.
 * @tree: a pointer to the root node of the tree to measure size.
 *
 * Return: the size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t tree_size = 1;

	if (!tree)
	{
		return (0);
	}

	tree_size += binary_tree_size(tree->left);
	tree_size += binary_tree_size(tree->right);
	return (tree_size);
}
