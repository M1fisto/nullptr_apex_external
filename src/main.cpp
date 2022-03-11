#include "includes.h"

LONG WINAPI simplest_crash_handler(EXCEPTION_POINTERS* exception_info) {
	std::cout << xorstr_("[!!] Crash at addr 0x") << exception_info->ExceptionRecord->ExceptionAddress << xorstr_(" by 0x") << std::hex << exception_info->ExceptionRecord->ExceptionCode << std::endl;

	return EXCEPTION_EXECUTE_HANDLER;
}

void run_security() {
	SetUnhandledExceptionFilter(simplest_crash_handler);

	m_security->hide_thread(GetCurrentThread);
	std::cout << xorstr_("[+] Hide thread") << std::endl; std::cout << std::endl;

	if (m_security->check_sign_mod())
		m_security->shutdown();

	while (true) {
		if (m_security->start()) {
			m_security->make_critical();
			m_security->shutdown();
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
}

int main() {
	std::thread(run_security).detach();


	if (!m_utillity->m_get_pid(xorstr_(L"EasyAntiCheat.exe"))) {
		std::cout << xorstr_("[(>_-)] Cheat status: Undetected ") << std::endl; std::cout << std::endl;

		std::cout << xorstr_("[0] Run SPOOFER") << std::endl;
		std::cout << xorstr_("[1] Run APEX hack") << std::endl;

		switch (_getch()) {
		case '0': {
			std::cout << xorstr_("[>] Launching the cheat ") << std::endl;
			system(xorstr_("sc stop mhyprot2")); std::this_thread::sleep_for(std::chrono::milliseconds(50));
			system(xorstr_("cls"));
			std::cout << xorstr_("[~] Wait please ") << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(2));
			system(xorstr_("cls"));
			std::this_thread::sleep_for(std::chrono::seconds(5));


		}break;
		case '1': {
			std::cout << xorstr_("[>] Launching the cheat ") << std::endl;
			system(xorstr_("sc stop mhyprot2")); std::this_thread::sleep_for(std::chrono::milliseconds(50));
			system(xorstr_("cls"));
			std::cout << xorstr_("[~] Wait please ") << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(2));
			system(xorstr_("cls"));

			m_apex->main();
		}break;
		
		}
	}
	else {
		std::cout << xorstr_("[!] Please close the game and restart the loader! ") << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(2));
		m_security->shutdown();
	}

	return 0;
}