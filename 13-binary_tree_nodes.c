#include "binary_trees.h"

/**
 * binary_tree_nodes - This function counts the nodes with at
 * least 1 child in a binary tree
 * @tree: Is a pointer to the root node of the tree to traverse.
 * Return: 0 tree is NULL.
 * A NULL pointer is not a leaf
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (0);
	else
		return (binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right) + 1);
}