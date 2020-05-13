/*  
 *  5.2_structs.cpp
 *
 *  author : Sreejith S
 *  email  : echo $(base64 -d <<< NDQ0bGhjCg==)@gmail.com
 *  date   : Sat 05 Aug 2017 03:37:19 IST
 *  ver    : 
 *   
 */

#include <iostream>
#include <ctime>
#include <cstring>

using namespace std;

struct message{
	string message_body;
	string recipent_id;
	string sender_id;
	long int timestamp;
	bool received_status;

};

long int GetTime()
{
	//time_t now = time(0);
	long int time_now = static_cast<long int>(time(NULL));
	return time_now;
}

void PrintMessage( message new_message)
{

	//printing confirm status
	cout << endl;
	cout << "----------Message Sent Successfully----------" << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "To: " << new_message.recipent_id << endl;
	cout << "Time: " << new_message.timestamp << endl;
	cout << "--------------------------------------------------" << endl;
	cout << new_message.message_body << endl;
}

int main()
{
	string username;
	
	cout << "Username: ";
	cin >> username;
	message welcome{ "Hi User, welcome to kMail!",
		username, 
		"kMail Team",
		GetTime(),
		true};
	//PrintMessage(welcome);
	//compose new message
	message new_message;
	cout << "Recipeint: ";
	cin >> new_message.recipent_id;
	cout << "Message : ";
	getline(cin, new_message.message_body);
	//NOT WORKING
	new_message.timestamp = GetTime();
	
	//sending message...
	new_message.received_status = true;
	PrintMessage(new_message);





	return 0;
}

