#include "receiver.hpp"
#include <stdio.h>
#include <iostream>

namespace receiver
{
	DWORD __stdcall communication::create_pipe()
	{
		std::string output = "";

		HANDLE hPipe;
		char buffer[999999];

		DWORD dwRead;
		hPipe = CreateNamedPipe(TEXT("\\\\.\\pipe\\athena_pipe_communication"),
			PIPE_ACCESS_DUPLEX | PIPE_TYPE_BYTE | PIPE_READMODE_BYTE,
			PIPE_WAIT,
			1,
			999999,
			999999,
			NMPWAIT_USE_DEFAULT_WAIT,
			NULL);


		printf("opened pipe\n");


		while (hPipe != INVALID_HANDLE_VALUE)
		{
			if (ConnectNamedPipe(hPipe, NULL) != FALSE)
			{
				while (ReadFile(hPipe, buffer, sizeof(buffer) - 1, &dwRead, NULL) != FALSE)
				{
					printf("...\n");

					buffer[dwRead] = '\0';

					output = output + buffer;
				}

				std::cout << output.c_str() << std::endl;
				output.clear();
			}

			DisconnectNamedPipe(hPipe);
		}
	}

	communication comm;
}
