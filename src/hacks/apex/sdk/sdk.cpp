#include "../../../includes.h"

namespace sdk {
	namespace weapone {
		float projectile_scale;
		float projectile_speed;
		float zoom_fov;

		void update(uintptr_t player) {
			uint64_t weapone_handle = read<uint64_t>(player + OFFSET_WEAPON);
				weapone_handle &= 0xffff;

			uint64_t entity = read<uint64_t>(globals::m_base + OFFSET_ENTITYLIST + (weapone_handle << 5)); {
				projectile_speed = read<float>(entity + OFFSET_BULLET_SPEED);
				projectile_scale = read<float>(entity + OFFSET_BULLET_SCALE);
				zoom_fov = read<float>(entity + OFFSET_ZOOM_FOV);
			}
		}

		float get_projectile_speed() {
			return projectile_speed;
		}

		float get_projectile_gravity() {
			return 750.0f * projectile_scale;
		}

		float get_zoom_fov() {
			return zoom_fov;
		}
	}
	
	namespace entity {
		//uintptr_t get_client_state() {
		//	return read<uintptr_t>(globals::m_base + OFFSET_CLIENT_STATE); //dwClientState
		//}

		//bool is_in_game() {
		//	return read<int>(get_client_state() + OFFSET_CLIENTSTATE_STATE) == 6; //dwClientState_State
		//}

		uintptr_t get_local_player() {
			return read<uintptr_t>(globals::m_base + OFFSET_LOCAL_ENT);
		}
		bool is_player(uintptr_t player) {
			return (read<uintptr_t>(player + OFFSET_NAME) == 125780153691248);
		}

		//int get_choked_commands() {
		//	return read<int>(get_client_state() + OFFSET_CLIENTSTATE_CHOKED); //clientstate_choked_commands
		//}
		//bool is_packets_sending() {
		//	return read<bool>(globals::m_base + OFFSET_SEND_PACKET); //dwbSendPackets
		//}
		//void send_packets(bool state) {
		//	write<bool>(globals::m_base + OFFSET_SEND_PACKET, state);	//dwbSendPackets
		//}



		bool is_alive(uintptr_t player) {
			return read<int>(player + OFFSET_LIFE_STATE) == 0 && read<int>(player + OFFSET_BLEED_OUT_STATE) == 0;
		}
		int get_health(uintptr_t player) {
			return read<int>(player + OFFSET_HEALTH);
		}
		int get_sheld(uintptr_t player) {
			return read<int>(player + OFFSET_SHIELD);
		}

		int get_team(uintptr_t player) {
			return read<int>(player + OFFSET_TEAM);
		}

		vec3_t get_view_angles(uintptr_t player) {
			return read<vec3_t>(player + OFFSET_VIEWANGLES);
		}
		void set_view_angles(uintptr_t player, vec3_t angle) {
			write<vec3_t>(player + OFFSET_VIEWANGLES, angle);
		}

		vec3_t get_aim_punch(uintptr_t player) {
			return read<vec3_t>(player + OFFSET_AIMPUNCH);
		}
		vec3_t get_breath_angles(uintptr_t player) {
			return read<vec3_t>(player + OFFSET_BREATH_ANGLES);
		}

		vec3_t get_origin(uintptr_t player) {
			return read<vec3_t>(player + OFFSET_ORIGIN);
		}
		vec3_t get_bone_pos(uintptr_t player, int id) {
			vec3_t origin_pos = get_origin(player);
			uintptr_t bones_array = read<uintptr_t>(player + OFFSET_BONES);
			vec3_t bone_pos{};

			bone_pos.x = read<float>(bones_array + 0xCC + (id * 0x30)) + origin_pos.x;
			bone_pos.y = read<float>(bones_array + 0xDC + (id * 0x30)) + origin_pos.y;
			bone_pos.z = read<float>(bones_array + 0xEC + (id * 0x30)) + origin_pos.z;

			return bone_pos;
		}

		vec3_t get_abs_velocity(uintptr_t player) {
			return read<vec3_t>(player + OFFSET_ABS_VELOCITY);
		}

		vec3_t get_cam_pos(uintptr_t player) {
			return read<vec3_t>(player + OFFSET_CAMERAPOS);
		}

		int get_item_id(uintptr_t entity) {
			return read<int>(entity + OFFSET_SCRIPT_ID);
		}

		std::string get_signifier(uintptr_t entity) {
			uintptr_t sig_addr = read<uintptr_t>(entity + OFFSET_SIGNIFIER);
				return read_string(sig_addr, 0xF);
		}
		
		float last_vis_time(uintptr_t player) {
			return read<float>(player + OFFSET_VISIBLE_TIME);
		}
		float oVisTime[100];
		bool is_visible(uintptr_t player, int id) {
			const auto vis_check = last_vis_time(player);
			const auto is_vis = vis_check > oVisTime[id] || vis_check < 0.f && oVisTime[id] > 0.f;

			oVisTime[id] = vis_check;
			return is_vis;
		}
	}

	bool world_to_screen(float* view_matrix, vec3_t world, vec2_t& screen) {
		float* m_vMatrix = view_matrix;
		float w = m_vMatrix[12] * world.x + m_vMatrix[13] * world.y + m_vMatrix[14] * world.z + m_vMatrix[15];

		if (w < 0.01f) 
			return false;

		screen.x = m_vMatrix[0] * world.x + m_vMatrix[1] * world.y + m_vMatrix[2] * world.z + m_vMatrix[3];
		screen.y = m_vMatrix[4] * world.x + m_vMatrix[5] * world.y + m_vMatrix[6] * world.z + m_vMatrix[7];

		float invw = 1.0f / w;
		screen.x *= invw;
		screen.y *= invw;

		float x = globals::width / 2;
		float y = globals::height / 2;

		x += 0.5 * screen.x * globals::width + 0.5;
		y -= 0.5 * screen.y * globals::height + 0.5;

		screen.x = x;
		screen.y = y;

		return true;
	}
}