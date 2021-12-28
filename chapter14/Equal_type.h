#ifndef EQUAL_TYPE_H
#define EQUAL_TYPE_H

class Equal_type {
public:
	Equal_type(int val, bool equality = true) :
		equality(equality), val(val) {}

	bool operator()(int param) const {
		if (equality) {
			return param == val;
		}
		else {
			return param != val;
		}
	}

	void set_equality(bool new_eq) { equality = new_eq; }
	void set_val(int new_val) { val = new_val; }

private:
	bool equality;
	int val;
};
#endif