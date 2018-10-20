#include <string>

using namespace std;

class TreeNode {
public:
	TreeNode() :value(string()), count(new int(1)), left(nullptr), right(nullptr) {}
	TreeNode(const TreeNode &tn) : value(tn.value), count(tn.count), left(tn.left), right(tn.right) { ++*count; }
	TreeNode& operator=(const TreeNode &tn);
	~TreeNode();

private:
	string value;
	int *count;
	TreeNode *left;
	TreeNode *right;
};

TreeNode & TreeNode::operator=(const TreeNode & tn)
{
	++*tn.count;
	if (--*count == 0) {
		delete left;
		delete right;
		delete count;
	}
	value = tn.value;
	count = tn.count;
	left = tn.left;
	right = tn.right;
	return *this;
}

TreeNode::~TreeNode()
{
	if (--*count == 0) {
		delete left;
		delete right;
		delete count;
	}
}

class BinStrTree {
public:
	BinStrTree() :root(new TreeNode()) {}
	BinStrTree(const BinStrTree &bst) :root(new TreeNode()) { *root = *bst.root; }
	BinStrTree& operator=(const BinStrTree &bst)
	{
		auto nt = new TreeNode();
		*nt = *bst.root;
		delete root;
		root = nt;
		return *this;
	}

	~BinStrTree() { delete root; }

private:
	TreeNode *root;
};