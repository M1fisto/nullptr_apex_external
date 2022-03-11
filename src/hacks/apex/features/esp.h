#pragma once

class visuals : public c_singleton<visuals> {
private:
	void player_glow(uintptr_t player, bool visible);
	void item_glow(uintptr_t entity);
public:
	void esp();
};
#define m_esp visuals::instance()