#include "binary_trees.h"

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check.
 *
 * Description: a perfect tree of height `h` has (2^(h + 1)) - 1 nodes.
 *
 * Return: 1 if tree is perfect,
 * 0, otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t tree_height = 0;
	size_t node_count = 0;
	size_t expected_count = 0;

	if (!tree)
	{
		return (0);
	}
	tree_height = binary_tree_height(tree);
	expected_count = _pow(2, (tree_height + 1)) - 1;
	node_count = binary_tree_node_count(tree);
	if (node_count == expected_count)
	{
		return (1);
	}
	return (0);
}

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

/**
 * binary_tree_node_count - counts num of nodes in tree
 * @tree: a pointer to the root node of the binary tree.
 *
 * Return: the number of nodes in the binary tree.
 */
size_t binary_tree_node_count(const binary_tree_t *tree)
{
	size_t node_count = 0;

	if (!tree)
	{
		return (0);
	}
	node_count += 1;
	node_count += binary_tree_node_count(tree->left);
	node_count += binary_tree_node_count(tree->right);
	return (node_count);
}

/**
 * _pow - find the value of `x` raised to the power `y`
 * @base: base value
 * @exp: exponent value
 * Return: `base` raised to the power `exp`
 */
int _pow(int base, int exp)
{
	int res;

	if (exp == 0)
	{
		return (1);
	}

	res = base;
	res *= _pow(base, exp - 1);
	return (res);
}
