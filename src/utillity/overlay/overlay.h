#pragma once
#undef DrawText

struct window_rect_data_t
	: public RECT
{
public:
	int GetWidth() const {
		return (right - left);
	}

	int GetHeight() const {
		return (bottom - top);
	}
};

enum TextFlags
	: unsigned
{
	TextLeft = 0x00,
	TextRight = 0x01,
	TextCenterV = 0x02,
	TextCenterH = 0x04,
	TextCenter = (TextCenterV | TextCenterH),
};

class dx_overlay: public c_singleton< dx_overlay >
{
private:
	window_rect_data_t m_target_window_size = { };

	virtual bool direct_create();
	static LRESULT WINAPI message_manager(HWND window, UINT message, WPARAM wparam, LPARAM lparam);
public:
	virtual ImDrawList* get_draw_list();
	bool create_overlay(const std::wstring& class_name);

public:
	virtual bool begin();
	virtual void end();

public:
	virtual window_rect_data_t& get_rect_data();
};
#define m_overlay dx_overlay::instance()