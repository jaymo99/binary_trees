#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree.
 * @tree: a pointer to the root node of the tree to measure height.
 *
 * Return: the height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height = 0;
	size_t left_h = 0;
	size_t right_h = 0;

	if (!tree)
	{
		return (0);
	}
	if (tree->left || tree->right)
	{
		height += 1;
	}
	left_h = binary_tree_height(tree->left);
	right_h = binary_tree_height(tree->right);

	if (left_h > right_h)
	{
		return (left_h + height);
	}
	return (right_h + height);
}
