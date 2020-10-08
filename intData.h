#pragma once
#include "data.h"
#include "serialization.h"


namespace HeterogeneousTree {
	namespace DataTypes {
		class IntData;
		using IntDataPtr = std::shared_ptr<IntData>;

		class IntData : public Data {
		public:
			IntData() = default;
			IntData(int iData) : data_(iData) {
			}
			~IntData() = default;

			int getId() const override {
				return static_cast<int>(DataTypeId::intData);
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
			int data_;
		};

	}
}
