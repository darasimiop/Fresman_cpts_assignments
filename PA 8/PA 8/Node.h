#pragma once
//Dara Ogunbinu-Peters
//PA 8 - Data Analysis via BST
#include <string>

class NodeBST
{
public:
	NodeBST() { mpLeft = nullptr; mpRight = nullptr; }
	NodeBST(std::string& newString) { mData = newString; mpLeft = nullptr; mpRight = nullptr; }
	//copy constructor 
	NodeBST& operator=(NodeBST& copyNode)
	{
		this->mData = copyNode.mData; this->mpLeft = copyNode.mpLeft; this->mpRight = copyNode.mpLeft; return *this;
	}

	//Accessors - Getters
	std::string getData() const { return mData;  }
	NodeBST*& getLeftPtr() { return mpLeft; }
	NodeBST*& getRightPtr() { return mpRight; }

	//Mutators - Setters
	void setData(std::string& newString) { mData = newString;  }
	void setLeftptr(NodeBST*& newLeft) { mpLeft = newLeft;  }
	void setRightptr(NodeBST*& newRight) { mpRight = newRight;  }

	virtual void printData() = 0;
	//Destructor 
	virtual ~NodeBST() { ; }


protected:
	std::string mData;
	NodeBST* mpLeft;
	NodeBST* mpRight;
};