#include "../../includes.h"
#include "../../mhyprot/mhyprot.hpp"

void apex::display_execute() {
    RECT rect = { };
    GetClientRect(globals::m_hwnd, &rect);

    globals::overley::m_display_size[0] = static_cast<float>(rect.right - rect.left);
    globals::overley::m_display_size[1] = static_cast<float>(rect.bottom - rect.top);
}

void apex::main() {
	std::cout << xorstr_("[>] PLS Open Apex Legends") << std::endl; std::cout << std::endl;
    while (!(globals::m_hwnd = FindWindow(nullptr, xorstr_("Apex Legends"))))
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
  
    globals::m_pid = GetProcessId(xorstr_("r5apex.exe"));
    ASSERT(globals::m_pid, xorstr_("failed to find pid"));
 
    if (!mhyprot::init()) {
        std::cout << xorstr_("[!] failed to initialize vulnerable driver") << std::endl;
    }

    if (!mhyprot::driver_impl::driver_init(false, false)) {
        std::cout << xorstr_("[!] failed to initialize driver properly") << std::endl;

        mhyprot::unload();
    }

    globals::m_base = globals::m_base = GetProcessBase(globals::m_pid);
    ASSERT(globals::m_base, xorstr_("failed to find module base"));

    {
        std::cout << xorstr_("[-] log") << std::endl;
        std::cout << xorstr_("	[~] pid:  ") << std::hex << globals::m_pid << std::endl;
        std::cout << xorstr_("	[~] base: " )<< std::hex << globals::m_base << std::endl;
        std::cout << xorstr_("  [~] create: overlay 'Respawn001'") << std::endl; std::cout << std::endl;
    }

	std::cout << xorstr_("[+] successfully launching cheat") << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));


    m_overlay->create_overlay(xorstr_(L"Respawn001")); // overlay magic
    while (!GetAsyncKeyState(VK_END)) {
        MSG message = { };
        do {
            {
                globals::apex::m_local = sdk::entity::get_local_player();

                globals::apex::m_view_renderer = read<uintptr_t>(globals::m_base + OFFSET_VIEWRENDER);
                globals::apex::m_view_matrix = read<uintptr_t>(globals::apex::m_view_renderer + OFFSET_MATRIX);
            }

            if (PeekMessage(&message, globals::overley::m_overlay_window, 0, 0, PM_REMOVE)) {
                TranslateMessage(&message);
                DispatchMessage(&message);
            }

            if (m_overlay->begin()) {
                display_execute();

                if (!globals::apex::m_view_renderer ||
                    !globals::apex::m_view_matrix)
                    continue;

                m_aim->aim();
                m_esp->esp();

                m_menu->present();
                m_overlay->end();
            }

            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        } while (message.message != WM_QUIT);
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}