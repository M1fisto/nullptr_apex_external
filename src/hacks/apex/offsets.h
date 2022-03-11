#pragma once
#define ENTITY_SIZE_DEF				0x42E0					//biggest entity offset

//#define OFFSET_CMD				0x11e3040
//#define OFFSET_INPUT				0x01cca130				//AVCInput
//#define OFFSET_GLOBALVARS			0x12c0450				//0x12AE340	
#define OFFSET_ENTITYLIST			0x194cb58
#define OFFSET_LOCAL_ENT			0x1cfbdb8				//LocalPlayer
#define OFFSET_NAME_LIST            0xb9c9360
#define OFFSET_SIGNIFIER			0x0580					// m_iSignifierName

#define OFFSET_THIRDPERSON          0x01932920 + 0x6c		//thirdperson_override + 0x6c

#define OFFSET_NAME_INDEX			0x38
#define OFFSET_SCRIPT_ID			0x1698					// m_customScriptInt//
#define OFFSET_TEAM					0x448					//m_iTeamNum
#define OFFSET_HEALTH				0x438					//m_iHealth
#define OFFSET_SHIELD				0x170					//m_shieldHealth
#define OFFSET_NAME					0x589					//m_iName
#define OFFSET_SIGN_NAME			0x580					//m_iSignifierName
#define OFFSET_ABS_VELOCITY         0x140					//m_vecAbsVelocity
#define OFFSET_VISIBLE_TIME         0x1af4					//CPlayer!lastVisibleTime
#define OFFSET_ZOOMING      		0x1c31					//m_bZooming
#define OFFSET_MAX_SHIELD			OFFSET_SHIELD + 0x4		//m_shieldHealth +0x4

#define OFFSET_IN_ATTACK			0x41f7630
#define OFFSET_IN_JUMP				0x41f76a8
#define OFFSET_IN_RELOAD			0x41f7650

#define OFFSET_ORIGIN				0x14c					//m_vecAbsOrigin
#define OFFSET_BONES				0xF38					//m_bConstrainBetweenEndpoints
#define OFFSET_AIMPUNCH				0x2480					//m_currentFrameLocalPlayer.m_vecPunchWeapon_Angle
#define OFFSET_CAMERAPOS			0x1f20					//CPlayer!camera_origin
#define OFFSET_VIEWANGLES			0x257c - 0x14			//m_ammoPoolCapacity - 0x14
#define OFFSET_BREATH_ANGLES		OFFSET_VIEWANGLES - 0x10
#define OFFSET_OBSERVER_MODE		0x33dc					//m_iObserverMode
#define OFFSET_OBSERVING_TARGET		0x33e8					//m_hObserverTarget

#define OFFSET_MATRIX               0x1b3bd0  
#define OFFSET_VIEWRENDER			0x74e7b28 				//  0x41e3588  

#define OFFSET_ITEM_GLOW            0x2c0					//m_highlightFunctionBits

#define OFFSET_WEAPON				0x1a8c					//m_latestPrimaryWeapons
#define OFFSET_BULLET_SPEED         0x1ef0					//CWeaponX!m_flProjectileSpeed
#define OFFSET_BULLET_SCALE         0x1ef8					//CWeaponX!m_flProjectileScale
#define OFFSET_ZOOM_FOV             0x1700 + 0xb8			//m_playerData + m_curZoomFOV

#define OFFSET_LIFE_STATE			0x798					//m_lifeState, >0 = dead
#define OFFSET_BLEED_OUT_STATE		0x2718					//m_bleedoutState, >0 = knocked

#define OFFSET_BREATH_ANGLES		OFFSET_VIEWANGLES - 0x10

#define OFFSET_ABS_VELOCITY         0x140					//m_vecAbsVelocity

// DT_HighlightSettings
#define OFFSET_GLOW_DISTANCE		0x3b4
#define OFFSET_GLOW_COLOR			0x1d0					// m_highlightParams + 0x18
#define OFFSET_GLOW_MODE			0x2C4					// m_highlightFunctionBits + 0x4
#define OFFSET_GLOW_ENABLE			0x3c8
#define OFFSET_GLOW_THROUGH_WALLS	0x3d0