#include "binary_trees.h"
/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: is a pointer to the root node of the tree
 * to measure the balance factor
 * Return: If tree is NULL, return 0
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int balance, height_l = 0, height_r = 0;

	if (tree == NULL)
		return (0);
	height_r = tree->right ? binary_tree_balance(tree->right) + 1 : 0;
	height_l = tree->left ? binary_tree_balance(tree->left) + 1 : 0;
	balance = height_l - height_r;
	return (balance);
}
