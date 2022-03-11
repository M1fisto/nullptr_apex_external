#include "../includes.h"

uintptr_t utillity::m_get_pid(const wchar_t* name) {
	PROCESSENTRY32W ProcEntry32;
	uintptr_t m_pip = 0;

	ProcEntry32.dwSize = sizeof(PROCESSENTRY32W);

	HANDLE hProcSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

	if (!hProcSnap || hProcSnap == INVALID_HANDLE_VALUE)
		return 0;

	while (Process32NextW(hProcSnap, &ProcEntry32)) {
		if (!wcscmp(name, ProcEntry32.szExeFile)) {
			m_pip = ProcEntry32.th32ProcessID;

			CloseHandle(hProcSnap);
		}
	}
	CloseHandle(hProcSnap);
	return m_pip;
}

std::string utillity::m_random_string(const int len) {
	const std::string m_alpha_numeric(xorstr_("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890"));

	std::default_random_engine m_generator{ std::random_device{}() };
	const std::uniform_int_distribution< std::string::size_type > m_distribution{ 0, m_alpha_numeric.size() - 1 };

	std::string str(len, 0);
	for (auto& it : str)
		it = m_alpha_numeric[m_distribution(m_generator)];

	return str;
}

bool utillity::m_rename_file(std::string& path) {
	std::string m_path = (m_random_string(16) + xorstr_(".exe"));

	SetConsoleTitleA(m_random_string(16).c_str());
	SetLayeredWindowAttributes(GetConsoleWindow(), 0, 210, LWA_ALPHA);

	if (std::rename(path.c_str(), m_path.c_str()))
		return false;

	path = m_path;
	return true;
}