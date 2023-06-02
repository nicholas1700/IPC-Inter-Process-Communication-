#include <Windows.h>

#include "sender/sender.hpp"


int main()
{
	Sleep(50);

	sender::comm.send_message("womp womp");

	system("pause");
}