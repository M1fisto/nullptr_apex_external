#pragma once

class apex : public c_singleton<apex> {
private:
	void display_execute();
public:
	void main();

};
#define m_apex apex::instance()