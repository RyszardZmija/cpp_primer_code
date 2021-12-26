#ifndef MESSAGE_H
#define MESSAGE_H

#include <set>
#include <string>

class Folder;

class Message {

	friend class Folder;
	friend void swap(Message &, Message &);

public:
	// folders is implicitly initialized to the empty set
	explicit Message(const std::string &str = std::string()) :
		contents(str) {}

	// copy control to manage pointers to this Message
	Message(const Message &);
	Message &operator=(const Message &);
	~Message();
	Message(Message &&);
	Message &operator=(Message &&);

	// add/remove this message from the specified Folder's set of messages
	void save(Folder &);
	void remove(Folder &);

	void add_folder(Folder *);
	void rem_folder(Folder *);

private:
	std::string contents; // actual message text
	std::set<Folder *> folders; // folders that have this message

	// utility functions used by copy constructor, copy assignment and destructor

	// add this Message to the Folders that point to the parameter
	void add_to_folders(const Message &);

	// remove this message from every Folder in folders
	void remove_from_folders();

	void move_folders(Message*);
};

void swap(Message &, Message &);
#endif