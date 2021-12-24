#include "Folder.h"

void Folder::add_msg(Message *m) {
	messages.insert(m);
}

void Folder::rem_msg(Message *m) {
	messages.erase(m);
}

void Folder::remove_messages_link() {
	for (const auto &x : messages) {
		x->rem_folder(this);
	}
}

void Folder::create_messages_link(Folder &f) {
	for (const auto &x : f.messages) {
		x->add_folder(this);
	}
}

Folder::~Folder() {
	remove_messages_link();
}

Folder::Folder(const Folder &f) :
	messages(f.messages) {

	create_messages_link(*this);
}

Folder &Folder::operator=(const Folder &f) {
	remove_messages_link();
	messages = f.messages;
	create_messages_link(*this);

	return *this;
}

void swap(Folder &lhs, Folder &rhs) {
	using std::swap;
	
	lhs.remove_messages_link();
	rhs.remove_messages_link();

	swap(lhs.messages, rhs.messages);

	lhs.create_messages_link(lhs);
	rhs.create_messages_link(rhs);
}