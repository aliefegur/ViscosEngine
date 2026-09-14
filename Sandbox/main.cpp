#include <Viscos/Viscos.h>

#include <cstdlib>

int main(int argc, char** argv)
{
	Viscos::Log::Initialize();
	VSCS_INFO("Hello World with logging system!");

	return 0;
}
