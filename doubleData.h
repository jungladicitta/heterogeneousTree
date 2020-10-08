#pragma once
#include "data.h"
#include "serialization.h"

namespace HeterogeneousTree {
	namespace DataTypes {
		class DoubleData;
		using DoubleDataPtr = std::shared_ptr<DoubleData>;

		class DoubleData : public Data {
		public:
			DoubleData() = default;
			DoubleData(double iData) : data_(iData) {
			}
			~DoubleData() = default;

			int getId() const override {
				return static_cast<int>(DataTypeId::doubleData);
			}

			void print(std::ostream& out) const override{
				out << data_ << '\n';
			}

			void write(std::ostream& out) const override {
				Serialize(data_, out);
			}

			void read(std::istream& in) override {
				Deserialize(in, data_);
			}
		private:
			double data_;
		};

	}
}
