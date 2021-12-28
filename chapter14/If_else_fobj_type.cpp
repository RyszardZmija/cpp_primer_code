#include "If_else_fobj_type.h"

const std::string &If_else_fobj_type::operator()
(bool cond, const std::string &when_true,
	const std::string &when_false) const {

	return cond ? when_true : when_false;
}