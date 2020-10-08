#pragma once
#include "data.h"
#include "serialization.h"

namespace HeterogeneousTree {
	namespace DataTypes {
		class StringData;
		using StringDataPtr = std::shared_ptr<StringData>;

		class StringData : public Data {
		public:
			StringData() = default;
			StringData(std::string iData) : data_(std::move(iData)) {
			}
			~StringData() = default;

			int getId() const override {
				return static_cast<int>(DataTypeId::stringData);
			}

			void print(std::ostream& out) const override{
				out << '"' << data_ << '"' << '\n';
			}

			void write(std::ostream& out) const override {
				Serialize(data_, out);
			}

			void read(std::istream& in) override {
				Deserialize(in, data_);
			}

		private:
			std::string data_;
		};

	}
}
