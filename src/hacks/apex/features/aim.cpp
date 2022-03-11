#include "../../../includes.h"
/*
Bones:
0, 1: Groin
2: Waist
3: Center Chest
4: Right Hand
5: Low Neck
6, 7: High Neck
8: Head
9: Heart
*/
vec3_t m_old_punch = { 0.f, 0.f, 0.f };
void aimbot::no_recoil() {
	if (GetAsyncKeyState(VK_LBUTTON)) {
		vec3_t m_angle = sdk::entity::get_view_angles(globals::apex::m_local) + (m_old_punch - sdk::entity::get_aim_punch(globals::apex::m_local));

		m_angle.normalize();
		sdk::entity::set_view_angles(globals::apex::m_local, { m_angle.x, m_angle.y, m_angle.z });

		m_old_punch = sdk::entity::get_aim_punch(globals::apex::m_local);
	}
}

void aimbot::aim() {
	if (!vars::aim::enabled && !globals::apex::m_local)
		return;

	auto entity = this->get_best_target();
	if (!entity)
		return;

	if (!sdk::entity::is_alive(globals::apex::m_local))
		return;

	auto view_matrix = read<sdk::view_matrix_t>(globals::apex::m_view_matrix);
	if (GetAsyncKeyState(this->keys()) & 0x8000) {
		vec3_t hitbox = sdk::entity::get_bone_pos(entity, this->hitboxes());
		vec2_t hitbox_pos_2d{};

		{
			if (vars::aim::no_recoil) {
				this->no_recoil();
			}

			if (vars::aim::bullet_prediction) {
				this->prediction(entity, hitbox);
			}
		}

		if (!sdk::world_to_screen(view_matrix.matrix, hitbox, hitbox_pos_2d))
			return;

		if (hitbox_pos_2d.x != 0 || hitbox_pos_2d.y != 0) {
			this->move_to(hitbox_pos_2d.x, hitbox_pos_2d.y);
		}
	}
}

int aimbot::keys() {
	int m_key{};
	switch (vars::aim::key) {
		case 0:
			m_key = VK_LBUTTON;
			break;
		case 1:
			m_key = VK_RBUTTON;
			break;
	}
	return m_key;
}

int aimbot::hitboxes() {
	int m_bone{};
	switch (vars::aim::bone) {
		case 0:
			m_bone = 8;
			break;
		case 1:
			m_bone = 7;
			break;
		case 3:
			m_bone = 3;
			break;
	}
	return m_bone;
}

uintptr_t aimbot::get_best_target() {
	float best_dist = vars::aim::aim_distance;
	uintptr_t best_target = 0;

	if (!sdk::entity::is_player(globals::apex::m_local))
		return 0;

	auto view_matrix = read<sdk::view_matrix_t>(globals::apex::m_view_matrix);
	for (int i = 0; i <= 60; i++) {
		auto entity = read<uintptr_t>((globals::m_base + OFFSET_ENTITYLIST) + ((uintptr_t)i << 5));
		if (!entity || entity == globals::apex::m_local)
			continue;

		if (!sdk::entity::is_alive(entity))
			continue;

		vec3_t hitbox = sdk::entity::get_bone_pos(entity, this->hitboxes());
		vec2_t hitbox_pos_2d{};

		if (!sdk::world_to_screen(view_matrix.matrix, hitbox, hitbox_pos_2d))
			continue;

		hitbox_pos_2d.x -= globals::width / 2.f;
		hitbox_pos_2d.y -= globals::height / 2.f;

		float crosshair_dist = sqrtf((hitbox_pos_2d.x * hitbox_pos_2d.x) + (hitbox_pos_2d.y * hitbox_pos_2d.y));
		if (crosshair_dist <= FLT_MAX && crosshair_dist <= best_dist) {
			if (crosshair_dist > vars::aim::fov)
				continue;

			if (!sdk::entity::is_visible(entity, i))
				continue;

			best_dist = crosshair_dist;
			best_target = entity;
		}
	}
	return best_target;
}

//uintptr_t aimbot::get_best_target() {
//	float best_dist = FLT_MAX;
//	uintptr_t best_target = 0;
//
//	sdk::view_matrix_t view_matrix = read<sdk::view_matrix_t>(globals::apex::m_view_matrix);
//	for (int i = 0; i <= 60; i++) {
//		uintptr_t entity = read<uintptr_t>(globals::m_base + OFFSET_ENTITYLIST + ((uintptr_t)i << 5));
//		if (!entity || entity == globals::apex::m_local)
//			continue;
//
//		if (!sdk::entity::is_player(entity))
//			continue;
//
//		if (!sdk::entity::is_alive(entity))
//			continue;
//
//		if (sdk::entity::get_team(entity) != sdk::entity::get_team(globals::apex::m_local)) {
//			vec3_t m_hitbox = sdk::entity::get_bone_pos(entity, 8/*this->hitboxes()*/);
//			vec2_t m_hitbox_pos_2d{};
//			if (!sdk::world_to_screen(view_matrix.matrix, m_hitbox, m_hitbox_pos_2d))
//				continue;
//
//			m_hitbox_pos_2d.x -= globals::width / 2.f;
//			m_hitbox_pos_2d.y -= globals::height / 2.f;
//
//			if (sdk::entity::is_visible(entity, i)) {
//				float crosshair_dist = sqrtf((m_hitbox_pos_2d.x * m_hitbox_pos_2d.x) + (m_hitbox_pos_2d.y * m_hitbox_pos_2d.y));
//				if (crosshair_dist <= FLT_MAX && crosshair_dist <= best_dist) {
//					if (crosshair_dist > vars::aim::fov)
//						continue;
//
//					best_dist = crosshair_dist;
//					best_target = entity;
//				}
//			}
//		}
//	}
//	return best_target;
//}

void aimbot::prediction(uintptr_t angle, vec3_t m_hitbox) {
	sdk::weapone::update(globals::apex::m_local);

	if (sdk::weapone::projectile_speed > 1.f) {
		float time = std::fabsf(sdk::entity::get_cam_pos(globals::apex::m_local).distance_to(m_hitbox) / sdk::weapone::projectile_speed);

		//vec3_t delta = (read<vec3_t>(entity + OFFSET_ORIGIN - 0xC) * time);
		vec3_t delta = sdk::entity::get_abs_velocity(globals::apex::m_local) * time;
		m_hitbox.x += delta.x;
		m_hitbox.y += delta.y;
		m_hitbox.z += delta.z + (700.f * sdk::weapone::projectile_scale * 0.5f) * (time * time);																	 // / 2.0f
	}
}