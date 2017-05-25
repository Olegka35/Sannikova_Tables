#pragma once
#include "Table.h"

//NodeTable
TableNode::TableNode() {
	word = "";
	count = 0;
}

TableNode::TableNode(TableNode& r) {
	word = r.GetKey();
	count = r.GetCount();
}

TableNode::TableNode(string word_, int count_) {
	word = word_;
	count = count_;
}

TableNode& TableNode::operator=(const TableNode& r) {
	if (this == &r) {
		return *this;
	}
	word = r.GetKey();
	count = r.GetCount();
	return *this;
}

bool TableNode::operator==(const TableNode& r)
{
	return GetKey() == r.GetKey();
}

std::string TableNode::GetKey() const 
{
	return word;
}
int TableNode::GetCount() const 
{
	return count;
}