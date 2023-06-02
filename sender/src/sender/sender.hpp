#include <Windows.h>
#include <string>
#include <filesystem>

namespace sender
{
	class communication
	{
	public:
		bool send_message(std::string message, ...);
	};

	extern communication comm;
}