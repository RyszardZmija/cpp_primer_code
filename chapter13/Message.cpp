#include "Message.h"
#include "Folder.h"

void Message::save(Folder &f) {
	folders.insert(&f);
	f.add_msg(this);
}

void Message::remove(Folder &f) {
	folders.erase(&f);
	f.rem_msg(this);
}

void Message::add_to_folders(const Message &m) {
	for (const auto &x : m.folders) { // for each Folder that holds m
		x->add_msg(this); // add a pointer to this Message to that Folder
	}
}

void Message::remove_from_folders() {
	for (const auto &x : folders) {
		x->rem_msg(this);
	}
}

Message::Message(const Message &m) :
	contents(m.contents), folders(m.folders) {

	add_to_folders(m);
}

Message::~Message() {
	remove_from_folders();
}

Message &Message::operator=(const Message &rhs) {
	remove_from_folders();
	contents = rhs.contents;
	folders = rhs.folders;
	add_to_folders(rhs);

	return *this;
}

void swap(Message &lhs, Message &rhs) {
	using std::swap;

	lhs.remove_from_folders();
	rhs.remove_from_folders();

	swap(lhs.contents, rhs.contents);
	swap(lhs.folders, rhs.folders);

	lhs.add_to_folders(lhs);
	rhs.add_to_folders(rhs);
}

void Message::add_folder(Folder *f) {
	folders.insert(f);
}

void Message::rem_folder(Folder *f) {
	folders.erase(f);
}