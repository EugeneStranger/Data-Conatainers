#include <iostream>
using namespace std;
class Tree
{
protected:
	class Element
	{
	protected:
		int Data;
		Element* pLeft;
		Element* pRight;
	public:
		Element(int Data, Element* pLeft = nullptr, Element* pRight = nullptr) :Data(Data), pLeft(pLeft), pRight(pRight)
		{
			cout << "EConstructor" << this << endl;
		}
		~Element()
		{
			cout << "EDestuctor" << this << endl;
		}
		friend class Tree;
		friend class UniqueTree;
	}*Root;
public:
	Element* getRoot()
	{
		return Root;
	}
	Tree() :Root(nullptr)
	{
		cout << "Tconstructor"<< this <<endl;
	}
	~Tree()
	{
		cout << "TDestructor" << this << endl;
	}
	void insert(int Data, Element* Root)
	{
		if (this->Root == nullptr) this->Root = new Element(Data);
		if (Root == nullptr) return;
		if (Data < Root->Data)
		{
			if (Root->pLeft == nullptr)Root->pLeft = new Element(Data);
			else insert(Data, Root->pLeft);
		}
		else
		{
			if (Root->pRight == nullptr) Root->pRight = new Element(Data);
			else insert(Data, Root->pRight);
		}
	}
	int minValue(Element* Root)
	{
		if (Root == nullptr) return 0;
		Root->pLeft == nullptr ? Root->Data : minValue(Root->pLeft);

	}
	int maxValue(Element* Root)
	{
		if (Root == nullptr) return 0;
		Root->pRight == nullptr ? Root->Data : maxValue(Root->pRight);
	}
	int Sum(Element* Root)
	{
		return Root == nullptr ? 0 : Sum(Root->pLeft) + Sum(Root->pRight) + Root->Data;

	}
	int Count(Element* Root)
	{
		return Root == nullptr ? 0 : Count(Root->pLeft) + Count(Root->pRight) + 1;
	}
	double Avg()
	{
		return (double)Sum(Root) / Count(Root);
	}
	void print(Element* Root)
	{
		if (Root == nullptr)return;
		print(Root->pLeft);
		cout << Root->Data << "\t";
		print(Root->pRight);
	}
};
class UniqueTree :public Tree
{

public:


	void insert(int Data, Element* Root)
	{
		if (this->Root == nullptr) this->Root = new Element(Data);
		if (Root == nullptr) return;
		if (Data < Root->Data)
		{
			if (Root->pLeft == nullptr)Root->pLeft = new Element(Data);
			else insert(Data, Root->pLeft);
		}
		else
		{
			if (Root->pRight == nullptr) Root->pRight = new Element(Data);
			else insert(Data, Root->pRight);
		}
	}

};
void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите размер дерева: ";
	cin >> n;
	Tree tree;
	for (int i = 0; i < n; i++)
	{
		tree.insert(rand() % 100, tree.getRoot());
	}
	tree.print(tree.getRoot());
	cout << endl;
	cout << "Минимальное значение в дереве: " << tree.minValue(tree.getRoot()) << endl;
	cout << "Максимальное значение в дереве: " << tree.maxValue(tree.getRoot()) << endl;
	cout << "Сумма эл-тов дерева:\t\t" << tree.Sum(tree.getRoot()) << endl;
	cout << "Кол-во эл-тов дерева:\t\t" << tree.Count(tree.getRoot()) << endl;
	cout << "Среднее-арифметическое эл-тов в дереве: " << tree.Avg() << endl;
	UniqueTree u_tree;
	for (int i = 0; i < n; i++)
	{
		u_tree.insert(rand() % 100, u_tree.getRoot());
	}
	u_tree.print(u_tree.getRoot());
	cout << endl;
	cout << "Минимальное значение в дереве: " << u_tree.minValue(u_tree.getRoot()) << endl;
	cout << "Максимальное значение в дереве: " << u_tree.maxValue(u_tree.getRoot()) << endl;
	cout << "Сумма эл-тов дерева:\t\t" << u_tree.Sum(u_tree.getRoot()) << endl;
	cout << "Кол-во эл-тов дерева:\t\t" << u_tree.Count(u_tree.getRoot()) << endl;
	cout << "Среднее-арифметическое эл-тов в дереве: " << u_tree.Avg() << endl;
}