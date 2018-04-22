
#define _CRT_SECURE_NO_WARNINGS


//#include <iostream>
//#include <conio.h>
//#include <stdio.h>

//#include <string>

//using namespace std;

class message {
private:
	int type_msg, from, to;
	char payload[255];
	long int session_key;
	//size_t lenght;
public:
	int get_type_msg();
	void set_type_msg(int type);
	int get_from();
	void set_from(int ptr);
	int get_to();
	void set_to(int ptr);
	char* getMSG();
	void setMSG(char* msg);
};
