#pragma once

#include "Application.h"
#include "Log.h"
#include "MessageDialog.h"

namespace Viscos {

	extern Application* CreateApplication();

}

int main(int argc, char** argv)
{
	try 
	{
		auto app = Viscos::CreateApplication();

		app->Run();

		delete app;
	}
	catch (const Viscos::ViscosException& e)
	{
        std::fprintf(stderr, "[%s]\n%s", e.GetType(), e.what());

        try
        {
            Viscos::MessageDialog::Show(
                e.GetType(),
                e.what(),
                Viscos::MessageDialog::Type::Error
            );
        }
        catch (const std::exception& dialogError)
        {
            std::fprintf(
                stderr,
                "Failed to display error dialog: %s\n",
                dialogError.what()
            );
        }
	}

	return 0;
}
