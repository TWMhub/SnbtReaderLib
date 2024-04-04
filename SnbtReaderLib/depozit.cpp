#include "SnbtReader.h"
namespace depozit {
	std::string typeToString(Type type) {
		switch (type) {
		case Type::title:
			return "title";
		case Type::subtitle:
			return "subtitle";
		case Type::description:
			return "description";
		default:
			return "Unknown";
		}
	}
}