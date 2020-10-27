#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

typedef struct Node
{
	int left = 0;
	int right = 0;
}TreeNode;

TreeNode *T = new TreeNode[10000];

// void create_node(TreeNode *T)
// {
// 	T = new TreeNode;
// 	T->val = n;
// 	create_node(T->left);
// 	create_node(T->right);
// }

void Postorder(TreeNode *T, int n)
{
	if (T[n].left != 0)
		Postorder(T,T[n].left);
	if (T[n].right != 0)
		Postorder(T,T[n].right);

	cout << n <<" ";

}
int main(int argc, char const *argv[])
{
	int n;
	int u,v;
	cin >> n;
	while(--n)
	{
		cin >> u >> v;
		if(T[u].left ==0)
		{
			T[u].left = v;
		}
		else
		{
			T[u].right = v;
		}
	}
	Postorder(T,1);
	return 0;
}