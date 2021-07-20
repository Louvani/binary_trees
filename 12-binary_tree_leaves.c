#include "binary_trees.h"

/**
 * binary_tree_leaves - This function counts the leaves in a binary tree.
 * @tree: Is a pointer to the root node of the tree to traverse.
 * Return: 0 tree is NULL.
 * A NULL pointer is not a leaf
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	else
		return (binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right));
}
