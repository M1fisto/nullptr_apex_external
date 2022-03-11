#pragma once

class menu : public c_singleton<menu> {
private:
	bool m_render = false;
public:
	void present();
};
#define m_menu menu::instance()
