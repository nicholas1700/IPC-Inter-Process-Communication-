#include <Windows.h>
#include <thread>

#include "receiver/receiver.hpp"

int main()
{
	std::thread([] {

		receiver::comm.create_pipe();

	}).detach();

	while(true){} /* replace with system("pause") if u dont want a higher cpu usage */
}