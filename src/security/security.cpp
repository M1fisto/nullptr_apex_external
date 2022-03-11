#pragma once
#include "../includes.h"
#include <Psapi.h>
#include <signal.h>
#include <Shlwapi.h>
#include <winternl.h>

bool security::hide_thread(HANDLE hThread) {
	typedef NTSTATUS(NTAPI* pNtSetInformationThread)
		(HANDLE, UINT, PVOID, ULONG);

	NTSTATUS Status;

	// Get NtSetInformationThread
	pNtSetInformationThread NtSIT = (pNtSetInformationThread)
		GetProcAddress(GetModuleHandle(TEXT(xorstr_("ntdll.dll"))), xorstr_("NtSetInformationThread"));
	// Shouldn't fail
	if (NtSIT == NULL)
		return false;

	// Set the thread info
	if (hThread == NULL)
		Status = NtSIT(GetCurrentThread(),
			0x11, //ThreadHideFromDebugger
			0, 0);
	else
		Status = NtSIT(hThread, 0x11, 0, 0);

	if (Status != 0x00000000)
		return false;
	else
		return true;
}

bool security::start() {
	return is_remote_session();
}

typedef NTSTATUS(__stdcall* t_NtQuerySystemInformation)(IN ULONG, OUT PVOID, IN ULONG, OUT PULONG);
bool security::check_sign_mod() {
	HMODULE ntdll = GetModuleHandleA(xorstr_("ntdll.dll"));

	auto NtQuerySystemInformation = (t_NtQuerySystemInformation)GetProcAddress(ntdll, xorstr_("NtQuerySystemInformation"));

	SYSTEM_CODEINTEGRITY_INFORMATION cInfo;
	cInfo.Length = sizeof(cInfo);

	NtQuerySystemInformation(
		SystemCodeIntegrityInformation,
		&cInfo,
		sizeof(cInfo),
		NULL
	);

	return (cInfo.CodeIntegrityOptions & CODEINTEGRITY_OPTION_TESTSIGN)
		|| (cInfo.CodeIntegrityOptions & CODEINTEGRITY_OPTION_DEBUGMODE_ENABLED);
}
typedef VOID(_stdcall* RtlSetProcessIsCritical) (IN BOOLEAN NewValue, OUT PBOOLEAN OldValue, IN BOOLEAN IsWinlogon);
BOOL security::make_critical() {
	HANDLE hDLL;
	RtlSetProcessIsCritical fSetCritical;

	hDLL = LoadLibraryA(xorstr_("ntdll.dll"));
	if (hDLL != NULL) {
		privileges(SE_DEBUG_NAME);

		(fSetCritical) = (RtlSetProcessIsCritical)GetProcAddress((HINSTANCE)hDLL, (xorstr_("RtlSetProcessIsCritical")));
		
		if (!fSetCritical) 
			return 0;

		fSetCritical(1, 0, 0);
		return 1;
	}
	else
		return 0;
}
void security::shutdown() {
	raise(11);
}