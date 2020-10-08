#pragma once

#include "dataTypes.h"
#include "data.h"

#include "intData.h"
#include "doubleData.h"
#include "stringData.h"

HeterogeneousTree::DataTypes::DataPtr createDataObject(int type_id) {
	auto data_type = static_cast<HeterogeneousTree::DataTypes::DataTypeId>(type_id);
	switch(data_type) {
	case HeterogeneousTree::DataTypes::DataTypeId::intData:
		return std::make_shared<HeterogeneousTree::DataTypes::IntData>();
	case HeterogeneousTree::DataTypes::DataTypeId::doubleData:
		return std::make_shared<HeterogeneousTree::DataTypes::DoubleData>();
	case HeterogeneousTree::DataTypes::DataTypeId::stringData:
		return std::make_shared<HeterogeneousTree::DataTypes::StringData>();
	default:
		throw std::invalid_argument("type_id not found");
	}
}
