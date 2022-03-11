#pragma once
#define RGBA_TO_FLOAT(r,g,b,a) (float)r/255.0f, (float)g/255.0f, (float)b/255.0f, (float)a/255.0f

namespace vars {
	namespace aim {
		inline bool enabled = true, no_recoil = true, smooth = true, bullet_prediction = true;
		
		inline float aim_distance = 200.f;

		inline int bone = 0, fov = 60, smoothing = 1, key = 1, no_recoil_intensivity = 90;
	}

	namespace visuals {
		inline bool enabled = true, player_glow = true, item_glow = true;

		namespace colors {
			inline sdk::color player_glow_vis = { 0.f, 255.f, 0.f, 255.f }, player_glow_invis = { 255.f, 0.f, 0.f, 255.f };
		}
	}
	
	namespace misc {
		inline bool enabled = false, fakelag = false, rapidfire = false;

		inline int fakelag_factor = 1, rapidfire_factor = 0;
	}

	namespace cfg {
		inline int selected_cfg = 0;
	}
}