#include "binary_trees.h"
/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: is a pointer to the root node of the tree to measure the height.
 * Return: If tree is NULL, your function must return 0
 *
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_l = 0, height_r = 0;

	if (tree)
	{
		height_l = tree->left ? binary_tree_height(tree->left) + 1 : 0;
		height_r = tree->right ? binary_tree_height(tree->right) + 1 : 0;
		return (height_l > height_r ? height_l : height_r);
	}
	return (0);
}
