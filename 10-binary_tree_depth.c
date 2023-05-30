#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a note in a binary tree.
 * @tree: a pointer to the root node of the tree to measure height.
 *
 * Return: the height of the tree
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (!tree)
	{
		return (0);
	}

	if (tree->parent)
	{
		depth += 1;
	}

	depth += binary_tree_depth(tree->parent);
	return (depth);
}
