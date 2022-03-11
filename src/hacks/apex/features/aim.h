#pragma once

class aimbot : public c_singleton<aimbot> {
private:
	inline auto move_to(float x, float y) -> void {
		float center_x = globals::width / 2;
		float center_y = globals::height / 2;

		float smooth = 1;

		if (vars::aim::smoothing > 0 && vars::aim::smooth)
			smooth = vars::aim::smoothing;

		float target_x = 0.f;
		float target_y = 0.f;

		if (x != 0.f) {
			if (x > center_x) {
				target_x = -(center_x - x);
				target_x /= smooth;
				if (target_x + center_x > center_x * 2.f) target_x = 0.f;
			}

			if (x < center_x) {
				target_x = x - center_x;
				target_x /= smooth;
				if (target_x + center_x < 0.f) target_x = 0.f;
			}
		}

		if (y != 0.f) {
			if (y > center_y) {
				target_y = -(center_y - y);
				target_y /= smooth;
				if (target_y + center_y > center_y * 2.f) target_y = 0.f;
			}

			if (y < center_y) {
				target_y = y - center_y;
				target_y /= smooth;
				if (target_y + center_y < 0.f) target_y = 0.f;
			}
		}

		mouse_event(MOUSEEVENTF_MOVE, static_cast<DWORD>(target_x), static_cast<DWORD>(target_y), 0, 0);
	}

	int keys();
	int hitboxes();
	uintptr_t get_best_target();
	void prediction(uintptr_t angle, vec3_t m_hitbox);
public:
	void no_recoil();
	void aim();
};
#define m_aim aimbot::instance()