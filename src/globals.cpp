#include "includes.h"

namespace globals {
	uintptr_t	m_pid;
	uintptr_t	m_peb;
	uintptr_t	m_base;
	HWND		m_hwnd;

	int width = GetSystemMetrics(SM_CXSCREEN);
	int height = GetSystemMetrics(SM_CYSCREEN);

	namespace overley {
		int m_display_size[2] = { 0,0 };

		IDirect3D9* m_direct = nullptr;
		IDirect3DDevice9* m_direct_device = nullptr;

		HWND m_overlay_window = nullptr;
		HWND m_target_window = nullptr;
	}

	namespace apex {
		uintptr_t m_local;
		uintptr_t m_name_list;
		uintptr_t m_entity_list;
		uintptr_t m_view_renderer;
		uintptr_t m_view_matrix;
	}

	namespace csgo {

	}
}