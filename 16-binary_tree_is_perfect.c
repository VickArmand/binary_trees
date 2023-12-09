#include "binary_trees.h"
int height_binary_tree(const binary_tree_t *tree);
int nodes_binary_tree(const binary_tree_t *tree);
/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: is a pointer to the root node of the tree to check
 * Return: If tree is NULL, your function must return 0
 *
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int num_of_nodes, height_of_tree, expected_num_of_nodes, i;

	if (tree == NULL)
		return (0);
	num_of_nodes = nodes_binary_tree(tree);
	height_of_tree = height_binary_tree(tree);
	expected_num_of_nodes = 1;
	for (i = 0; i < height_of_tree + 1; i++)
		expected_num_of_nodes *= 2;
	expected_num_of_nodes -= 1;
	if (num_of_nodes == expected_num_of_nodes)
		return (1);
	return (0);
}
/**
 * height_binary_tree - finds the height of the tree
 * @tree: is a pointer to the root node of the tree
 * Return: height of tree
 */
int height_binary_tree(const binary_tree_t *tree)
{
	int height_r = 0, height_l = 0;

	if (tree == NULL)
		return (0);
	height_l = tree->left ? 1 + height_binary_tree(tree->left) : 0;
	height_r = tree->right ? 1 + height_binary_tree(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}
/**
 * nodes_binary_tree - finds the number of nodes in a tree
 * @tree: is a pointer to the root node of the tree
 * Return: number of nodes in the tree
 */
int nodes_binary_tree(const binary_tree_t *tree)
{
	int nodes = 0;

	if (tree == NULL)
		return (0);
	nodes += 1;
	nodes += nodes_binary_tree(tree->left);
	nodes += nodes_binary_tree(tree->right);
	return (nodes);
}
