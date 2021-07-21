#include "binary_trees.h"

/**
 * binary_tree_uncle - This function finds the uncle of a node.
 * @node: A pointer to the node to find the uncle.
 * Return: A pointer to the uncle node
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node && node->parent)
	{
		return (binary_tree_sibling(node->parent));
	}
	return (NULL);
}

/**
 * binary_tree_sibling - This function finds the sibling of a node.
 * @node: A pointer to the node to find the sibling.
 * Return: A pointer to the sibling node.
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node && node->parent)
	{
		if (node->parent->left && node->parent->right)
		{
			if (node->parent->left == node)
				return (node->parent->right);
			else
				return (node->parent->left);
		}
	}
	return (NULL);
}
