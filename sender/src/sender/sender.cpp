#include "sender.hpp"

namespace sender
{
	bool communication::send_message(std::string message, ...)
	{

        char buffer[1024] = { };
        va_list args;

        HANDLE hPipe = INVALID_HANDLE_VALUE;

        hPipe = CreateFileA("\\\\.\\pipe\\athena_pipe_communication",
            GENERIC_READ | GENERIC_WRITE,
            0,
            NULL,
            OPEN_EXISTING,
            0,
            NULL);

        va_start(args, message);
        vsprintf_s(buffer, message.c_str(), args);
        va_end(args);

        unsigned long ulBytesWritten = 0;

        WriteFile(hPipe,
            buffer,
            sizeof(buffer),
            &ulBytesWritten,
            NULL);

        CloseHandle(hPipe);

        Sleep(10);

        return true;
	}

	communication comm;
}
