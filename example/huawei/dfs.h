#pragma once
#include<stack>
#include<iostream>
struct Node {
	int self;     // ����
	Node *left;   // ���c
	Node *right;  // �ҹ��c
};
const int TREE_SIZE = 9;
std::stack<Node *> unvisited;
Node nodes[TREE_SIZE];
Node *current;
void DES() {
	//��ʼ����
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

	unvisited.push(&nodes[0]); //�Ȱ�0����UNVISITED stack
							   // �����ȃ��������ڶ����������£����Ƕ����������v�������@�e��ʹ��ѭ�h���F)
							   // ֻ��UNVISITED����
	while (!unvisited.empty()) {
		current = (unvisited.top()); //��ǰ��ԓ�L����
		unvisited.pop();
		if (current->right != NULL)
			unvisited.push(current->right);
		if (current->left != NULL)
			unvisited.push(current->left);
		std::cout << current->self << std::endl;
	}
}
