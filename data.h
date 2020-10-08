#pragma once
#include "dataTypes.h"
#include <iostream>
#include <memory>
#include <sstream>

namespace HeterogeneousTree {
	namespace DataTypes {

		class Data;
		using DataPtr = std::shared_ptr<Data>;

		class Data {
		public:
			Data() = default;
			virtual ~Data() = default;
			virtual int getId() const = 0;
			virtual void print(std::ostream&) const = 0;
			// bool operator==(const Data& other) const {
			// 	std::ostringstream lhs;
			// 	std::ostringstream rhs;
			// 	this->write(lhs);
			// 	other.write(rhs);
			// 	return lhs.str() == rhs.str();
			// }

			virtual void write(std::ostream&) const = 0;
			virtual void read(std::istream&) = 0;
		private:
		};

	}
}
