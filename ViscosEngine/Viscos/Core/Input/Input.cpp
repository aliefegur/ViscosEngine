#include "Input.h"
#include "InputProvider.h"

namespace Viscos {

	InputProvider* Input::s_Provider = nullptr;

	bool Input::IsKeyPressed(KeyCode key)
	{
		assert(s_Provider && "Input provider has not been initialized!");
		return s_Provider->IsKeyPressed(key);
	}

	void Input::SetProvider(InputProvider* provider)
	{
		assert(provider && "Input provider cannot be null");
		s_Provider = provider;
	}

}
