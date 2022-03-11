#pragma once

class utillity : public c_singleton<utillity> {
private:
	std::string m_random_string(const int len);
public:
	uintptr_t m_get_pid(const wchar_t* name);
	bool m_rename_file(std::string& path);
};
#define m_utillity utillity::instance()