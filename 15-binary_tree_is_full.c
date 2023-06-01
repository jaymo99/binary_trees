#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full.
 * @tree: pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is full,
 * 0, otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int tree_status = 0;

	if (!tree)
	{
		return (0);
	}

	if (node_is_balanced(tree) && tree->left)
	{
		tree_status = binary_tree_is_full(tree->left);
		if (tree_status == 0)
		{
			return (0);
		}

		tree_status = binary_tree_is_full(tree->right);
		if (tree_status == 0)
		{
			return (0);
		}
	}
	else if (node_is_balanced(tree))
	{
		return (1);
	}
	return (tree_status);
}

/**
 * node_is_balanced - checks if a node is balanced.
 * @node: pointer to the node being examined
 *
 * Description: A balanced node is one which either has exactly
 * two child nodes, or none at all.
 * Return: 1 if a node is balanced, 0 otherwise.
 */
int node_is_balanced(const binary_tree_t *node)
{
	if (node->left && node->right)
	{
		return (1);
	}

	if (node->left == NULL && node->right == NULL)
	{
		return (1);
	}
	return (0);
}
