#pragma once

#include "dataTypes.h"
#include "data.h"

#include "intData.h"
#include "doubleData.h"
#include "stringData.h"

HeterogeneousTree::DataTypes::DataPtr createDataObject(int type_id) {
	switch(type_id) {
	case 1:
		return std::make_shared<HeterogeneousTree::DataTypes::IntData>();
	case 2:
		return std::make_shared<HeterogeneousTree::DataTypes::DoubleData>();
	case 3:
		return std::make_shared<HeterogeneousTree::DataTypes::StringData>();
	default:
		throw std::invalid_argument("type_id not found");
	}
}
