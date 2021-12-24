#ifndef FOLDER_H
#define FOLDER_H

#include <string>
#include <set>
#include "Message.h"

class Folder {
	
	friend void swap(Folder &, Folder &);

public:
	void add_msg(Message *);
	void rem_msg(Message *);

	Folder(const Folder &);
	Folder &operator=(const Folder &);
	~Folder();

private:
	std::set<Message *> messages;

	void remove_messages_link();
	void create_messages_link(Folder &);

};

void swap(Folder &, Folder &);

#endif