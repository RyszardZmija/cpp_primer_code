#ifndef IF_ELSE_FOBJ_TYPE
#define IF_ELSE_FOBJ_TYPE

#include <string>

class If_else_fobj_type {
public:
	const std::string &operator()
		(bool, const std::string &, const std::string &) const;

private:

};
#endif