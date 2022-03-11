#pragma once

namespace sdk {
	struct view_matrix_t {
		float matrix[16];
	};

	struct bone_t {
		BYTE pad[0xCC];
		float x;
		BYTE pad2[0xC];
		float y;
		BYTE pad3[0xC];
		float z;
	};

	struct glow_settings { 
		BYTE glow_mode, 
		border_mode,
		border_size, 
		transparent_level; 
	};

	struct color {
		float r, g, b, a;
		color operator+(color add_color) {
			return { r + add_color.r, g + add_color.g, b + add_color.b, a + add_color.a };
		}

		color operator-(color add_color) {
			return { r - add_color.r, g - add_color.g, b - add_color.b, a - add_color.a };
		}

		color operator*(float multiplier) {
			return { r * multiplier, g * multiplier, b * multiplier, a * multiplier };
		}

		color operator/(float dividend) {
			return { r / dividend, g / dividend, b / dividend, a / dividend };
		}

		color floor() {
			return { floorf(r), floorf(g), floorf(b), floorf(a) };
		}
	};


	namespace weapone {
		extern float projectile_scale;
		extern float projectile_speed;
		extern float zoom_fov;

		void update(uintptr_t player);

		float get_projectile_speed();
		float get_projectile_gravity();
		float get_zoom_fov();
	}

	namespace entity {
		uintptr_t get_local_player();
		bool is_player(uintptr_t player);

		bool is_alive(uintptr_t player);
		int get_health(uintptr_t player);
		int get_sheld(uintptr_t player);

		int get_team(uintptr_t player);

		vec3_t get_view_angles(uintptr_t player);
		void set_view_angles(uintptr_t player, vec3_t angle);

		vec3_t get_aim_punch(uintptr_t player);
		vec3_t get_breath_angles(uintptr_t player);

		vec3_t get_origin(uintptr_t player);
		vec3_t get_bone_pos(uintptr_t ent, int id);

		vec3_t get_abs_velocity(uintptr_t player);

		vec3_t get_cam_pos(uintptr_t player);

		int get_item_id(uintptr_t entity);
		
		std::string get_signifier(uintptr_t entity);
		
		float last_vis_time(uintptr_t player);
		bool is_visible(uintptr_t player, int id);
	}

	bool world_to_screen(float* view_matrix, vec3_t world, vec2_t& screen);
}