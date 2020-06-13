#include"SpaceDivisionTree2.hpp"

using namespace dev;


struct Node {

};

int main()
{
	Node* node1 = new Node;

	SpaceDivisionTree<Node> tree;

	tree.Regist(LinerObject<Node>(node1), 5);
	tree.PrintArray();
	


	return 0;
}