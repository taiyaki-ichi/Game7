#include"SpaceDivisionTree2.hpp"
#include<string>


using namespace dev;

struct Node {
	std::string nameTag;
	Node(std::string&& name)
		:nameTag(std::move(name))
	{}
};


struct aaaPolicy {
	void operator()(Node* node1, Node* node2) {
		std::cout << node1->nameTag << " vs " << node2->nameTag << "\n";
	}
};

int main()
{
	
	SpaceDivisionTree<Node> tree;

	Node* node1 = new Node("node1");
	LinerObject<Node> linerObj1(node1);
	tree.Regist(&linerObj1, 11);

	Node* node2 = new Node("node2");
	LinerObject<Node> linerObj2(node2);
	tree.Regist(&linerObj2, 0);

	Node* node3 = new Node("node3");
	LinerObject<Node> linerObj3(node3);
	tree.Regist(&linerObj3, 1);

	tree.PrintArray();

	tree.SearchTree<aaaPolicy>();

	tree.DeleteSpaceCell();
	tree.PrintArray();
	
	delete node1;
	delete node2;
	delete node3;

	return 0;
}