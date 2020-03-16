#pragma once
#include<stack>
#include<iostream>
struct Node {
	int self;     // 數據
	Node *left;   // 左節點
	Node *right;  // 右節點
};
const int TREE_SIZE = 9;
std::stack<Node *> unvisited;
Node nodes[TREE_SIZE];
Node *current;
void DES() {
	//初始化樹
	for (int i = 0; i < TREE_SIZE; i++) {
		nodes[i].self = i;
		int child = i * 2 + 1;
		if (child < TREE_SIZE) // Left child
			nodes[i].left = &nodes[child];
		else
			nodes[i].left = NULL;
		child++;
		if (child < TREE_SIZE) // Right child
			nodes[i].right = &nodes[child];
		else
			nodes[i].right = NULL;
	}

	unvisited.push(&nodes[0]); //先把0放入UNVISITED stack
							   // 樹的深度優先搜索在二叉樹的特例下，就是二叉樹的先序遍歷操作（這裡是使用循環實現)
							   // 只有UNVISITED不空
	while (!unvisited.empty()) {
		current = (unvisited.top()); //當前應該訪問的
		unvisited.pop();
		if (current->right != NULL)
			unvisited.push(current->right);
		if (current->left != NULL)
			unvisited.push(current->left);
		std::cout << current->self << std::endl;
	}
}
