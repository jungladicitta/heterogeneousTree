#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include "data.h"
#include "createDataObject.h"



namespace HeterogeneousTree {
	class Node;
	using NodePtr = std::shared_ptr<Node>;

	class Node {
	public:
		Node() = default;
		Node(DataTypes::DataPtr value) : node_value_(value) {
		}
		~Node() = default;

		DataTypes::DataPtr getNodeValuePtr() const {
			return node_value_;
		}

		bool isChild(const DataTypes::Data& data_to_check) const {
			for (auto& child : childs_) {
				if (*(child->getNodeValuePtr()).get() == (data_to_check)) {
					return true;
				}
			}
			return false;
		}

		NodePtr& addChild(NodePtr child) {
			//
			childs_.push_back(child);
			return childs_.back();
		}

		void serialize(std::ostream& out) const {
			size_t id = node_value_->getId();
			Serialize(id, out);
			node_value_->write(out);

			size_t childs_num = childs_.size();
			Serialize(childs_num, out);

			for (auto item : childs_) {
				item->serialize(out);
			}
		}

		void deserialize(std::istream& in) {
			size_t type_id;
			Deserialize(in, type_id);

			node_value_ = std::shared_ptr<DataTypes::Data>(createDataObject(type_id));
			node_value_->read(in);

			size_t childs_size;
			Deserialize(in, childs_size);
			childs_ = std::vector<NodePtr>(childs_size);

			for (auto& item : childs_) {
				item = std::make_shared<Node>();
				item->deserialize(in);
			}
		}

		void print(std::ostream& out, size_t prefix = 0) const {
			out << std::string(prefix, ' ');
			node_value_->print(out);

			for (auto item : childs_) {
				item->print(out, prefix + 4);
			}
		}
	private:
		DataTypes::DataPtr node_value_;
		std::vector<NodePtr> childs_;
	};
}
