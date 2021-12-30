#ifndef BASKET_H
#define BASKET_H

#include <memory>
#include <iostream>
#include <set>
#include "Quote.h"

class Basket {
public:
	// synthesized default constructor and copy control members

	void add_item(const Quote &);
	void add_item(Quote &&);

	double total_receipt(std::ostream &) const;
private:
	static bool compare(const std::shared_ptr<Quote> &lhs,
		const std::shared_ptr<Quote> &rhs) {

		return lhs->isbn() < rhs->isbn();
	}

	std::multiset<std::shared_ptr<Quote>, decltype(compare) *> items{ compare };
};
#endif