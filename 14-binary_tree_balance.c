#include "binary_trees.h"

/**
* binary_tree_balance - This function
* measures the balance factor of a binary tree.
* @tree: The binary tree to measure.
* Return: 0 if tree is NULL.
*/

int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
}

/**
 * binary_tree_height - measures the height of a binary tree.
 * @tree: Is a pointer to the root node of the tree to traverse.
 * Return: 0 if tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_left;
	size_t height_right;

	if (!tree)
		return (0);
	if (tree->left)
		height_left = 1 + binary_tree_height(tree->left);
	else
		height_left = 1;
	if (tree->right)
		height_right = 1 + binary_tree_height(tree->right);
	else
		height_right = 1;
	if (height_left > height_right)
		return (height_left);
	else
		return (height_right);
}
