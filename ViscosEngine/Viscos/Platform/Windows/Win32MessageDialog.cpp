
#include "Viscos/Core/MessageDialog.h"

namespace Viscos {

    namespace {

        std::wstring ToWide(std::string_view text)
        {
            if (text.empty())
                return {};

            if (text.size() > static_cast<size_t>((std::numeric_limits<int>::max)()))
                throw std::length_error("MessageBox text is too long");

            const int length = static_cast<int>(text.size());

            const int required = MultiByteToWideChar(
                CP_UTF8,
                MB_ERR_INVALID_CHARS,
                text.data(),
                length,
                nullptr,
                0
            );

            if (required == 0)
                throw std::runtime_error("UTF-8 conversion failed");

            std::wstring result(required, L'\0');

            if (MultiByteToWideChar(
                CP_UTF8,
                MB_ERR_INVALID_CHARS,
                text.data(),
                length,
                result.data(),
                required
            ) == 0)
                throw std::runtime_error("UTF-8 conversion failed");

            return result;
        }

    }

    void MessageDialog::Show(
        std::string_view title,
        std::string_view message,
        Type type)
    {
        UINT flags = MB_OK | MB_TASKMODAL;

        switch (type)
        {
        case Type::Info:    flags |= MB_ICONINFORMATION;    break;
        case Type::Warning: flags |= MB_ICONWARNING;        break;
        case Type::Error:   flags |= MB_ICONERROR;          break;
        }

        const std::wstring wideTitle = ToWide(title);
        const std::wstring wideMessage = ToWide(message);

        if (MessageBoxW(nullptr, wideMessage.c_str(), wideTitle.c_str(), flags) == 0)
        {
            throw std::runtime_error("MessageBoxW failed");
        }
    }

}
