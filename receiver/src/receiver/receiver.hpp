#include <Windows.h>

namespace receiver
{
	class communication
	{
	public:
		DWORD WINAPI create_pipe();
	};

	extern communication comm;
}