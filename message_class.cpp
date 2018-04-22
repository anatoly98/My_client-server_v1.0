
#include "message_class.h"
#include "iostream"

void message::set_type_msg(int type) {
	type_msg = type;
}

void message::setMSG(char* msg) {
	strcpy(payload, msg);
}

void message::set_from(int ptr) {
	from = ptr;
}

void message::set_to(int ptr) {
	to = ptr;
}

//получить нечто

int message::get_type_msg() {
	return type_msg;
}

int message::get_from() {
	return from;
}

int message::get_to() {
	return to;
}

char* message::getMSG() {
	return payload;
}