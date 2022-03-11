#pragma once

class security : public c_singleton<security> {
private:
	__forceinline BOOL is_remote_session(void) {
		return GetSystemMetrics(SM_REMOTESESSION);
	}

	__forceinline BOOL privileges(LPCSTR lpszPriv) {
		HANDLE token;
		LUID uid;
		TOKEN_PRIVILEGES privs;
		ZeroMemory(&privs, sizeof(privs));

		if (!OpenProcessToken(GetCurrentProcess(), (TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY), &token))
			return FALSE;

		if (!LookupPrivilegeValue(NULL, lpszPriv, &uid)) {
			CloseHandle(token); return FALSE;
		}

		privs.PrivilegeCount = 1;
		privs.Privileges[0].Luid = uid;
		privs.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

		BOOL bRet = AdjustTokenPrivileges(token, FALSE, &privs, sizeof(privs), NULL, NULL);
		CloseHandle(token);
		return bRet;
	}
public: //other
	bool hide_thread(HANDLE hThread);

	bool check_sign_mod();
	BOOL make_critical();
	void shutdown();
public:
	bool start();

};
#define m_security security::instance()