#pragma once

namespace globals {
	extern uintptr_t  	m_pid;
	extern uintptr_t	m_peb;
	extern uintptr_t	m_base;
	extern HWND			m_hwnd;

	extern int width;
	extern int height;

	namespace overley {
		extern int m_display_size[2];

		extern IDirect3D9* m_direct;
		extern IDirect3DDevice9* m_direct_device;

		extern HWND m_overlay_window;
		extern HWND m_target_window;
	}

	namespace apex {
		extern uintptr_t m_local;
		extern uintptr_t m_name_list;
		extern uintptr_t m_entity_list;
		extern uintptr_t m_view_renderer;
		extern uintptr_t m_view_matrix;
	}

	namespace csgo {

	}
}