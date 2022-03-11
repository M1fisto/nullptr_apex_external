#pragma once

class miscellanea : public c_singleton<miscellanea> {
private:
	float m_last_time_scale = 1.f;
private:
	void rapidfire();
	void fakelags();
public:
	void misc();
};
#define m_misc miscellanea::instance()