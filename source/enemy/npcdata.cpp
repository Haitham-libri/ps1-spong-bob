/*=========================================================================

	npcdata.cpp

	Author:		CRB
	Created:
	Project:	Spongebob
	Purpose:

	Copyright (c) 2000 Climax Development Ltd

===========================================================================*/

#ifndef __SPR_SPRITES_H__
#include <sprites.h>
#endif

#ifndef __ENEMY_NPC_H__
#include "enemy\npc.h"
#endif

#ifndef	__PLAYER_PLAYER_H__
#include "player\player.h"
#endif

#ifndef	__ANIM_CLAM_HEADER__
#include <ACTOR_CLAM_ANIM.h>
#endif

#ifndef	__ANIM_ANENOME_HEADER__
#include <ACTOR_ANENOME_ANIM.h>
#endif

#ifndef __ANIM_BABYOCTOPUS_HEADER__
#include <ACTOR_BABYOCTOPUS_ANIM.h>
#endif

#ifndef __ANIM_CATERPILLAR_HEADER__
#include <ACTOR_CATERPILLAR_ANIM.h>
#endif

#ifndef __ANIM_DUSTDEVIL_HEADER__
#include <ACTOR_DUSTDEVIL_ANIM.h>
#endif

#ifndef __ANIM_FLAMINGSKULL_HEADER__
#include <ACTOR_FLAMINGSKULL_ANIM.h>
#endif

#ifndef __ANIM_FLYINGDUTCHMAN_HEADER__
#include <ACTOR_FLYINGDUTCHMAN_ANIM.h>
#endif

#ifndef __ANIM_GHOST_HEADER__
#include <ACTOR_GHOST_ANIM.h>
#endif

#ifndef __ANIM_HERMITCRAB_HEADER__
#include <ACTOR_HERMITCRAB_ANIM.h>
#endif

#ifndef __ANIM_IRONDOGFISH_HEADER__
#include <ACTOR_IRONDOGFISH_ANIM.h>
#endif

//#ifndef __ANIM_JELLYFISH1_HEADER__
//#include <ACTOR_JELLYFISH1_ANIM.h>
//#endif

#ifndef __ANIM_PUFFAFISH_HEADER__
#include <ACTOR_PUFFAFISH_ANIM.h>
#endif

#ifndef __ANIM_SHARKMAN_HEADER__
#include <ACTOR_SHARKMAN_ANIM.h>
#endif

#ifndef __ANIM_SKELETALFISH_HEADER__
#include <ACTOR_SKELETALFISH_ANIM.h>
#endif

#ifndef __ANIM_SPIDERCRAB_HEADER__
#include <ACTOR_SPIDERCRAB_ANIM.h>
#endif

//#ifndef __ANIM_SQUIDDART_HEADER__
//#include <ACTOR_SQUIDDART_ANIM.h>
//#endif

#ifndef __ANIM_STOMPER_HEADER__
#include <ACTOR_STOMPER_ANIM.h>
#endif

#ifndef __ANIM_SPIKEYANENOME_HEADER__
#include <ACTOR_SPIKEYANENOME_ANIM.h>
#endif

#ifndef __ANIM_BALLBLOB_HEADER__
#include <ACTOR_BALLBLOB_ANIM.h>
#endif

#ifndef	__ANIM_SHARKSUB_HEADER__
#include <ACTOR_SHARKSUB_ANIM.h>
#endif

#ifndef	__ANIM_SEASNAKE_HEADER__
#include <ACTOR_SEASNAKE_ANIM.h>
#endif

CNpcEnemy::NPC_DATA CNpcEnemy::m_data[NPC_UNIT_TYPE_MAX] =
{
	{	// NPC_DUST_DEVIL
		ACTORS_DUSTDEVIL_SBK,
		ANIM_DUSTDEVIL_TWIST,
		NPC_SENSOR_NONE,
		NPC_MOVEMENT_STATIC,
		NPC_CLOSE_NONE,
		NPC_TIMER_NONE,
		false,
		3,
		2048,
		DETECT_NO_COLLISION,
		DAMAGE__NONE,
		0,
		ANIM_DUSTDEVIL_TWIST,
		NPC_SHOT_GENERIC,
		0,
		0,
		false,
		false,
		false,
		true,
		CSoundMediator::NUM_SFXIDS,
		CSoundMediator::NUM_SFXIDS,
	},

	{	// NPC_SMALL_JELLYFISH_1
		0,//ACTORS_JELLYFISH1_SBK,
		FRM_JELLYFISH1_SWIM1,
		NPC_SENSOR_USER_CLOSE,
		NPC_MOVEMENT_FIXED_PATH,
		NPC_CLOSE_NONE,
		NPC_TIMER_NONE,
		false,
		2,
		128,
		DETECT_ALL_COLLISION,
		DAMAGE__SHOCK_ENEMY,
		16,
		FRM_JELLYFISH1_SWIM1,
		NPC_SHOT_GENERIC,
		0,
		FRM_JELLYFISH1_SWIM1,
		true,
		true,
		false,
		false,
		CSoundMediator::NUM_SFXIDS,
		CSoundMediator::NUM_SFXIDS,
	},

	{	// NPC_SMALL_JELLYFISH_2
		ACTORS_CLAM_SBK,
		ANIM_CLAM_SIDESNAP,
		NPC_SENSOR_USER_CLOSE,
		NPC_MOVEMENT_FIXED_PATH,
		NPC_CLOSE_NONE,
		NPC_TIMER_NONE,
		false,
		3,
		128,
		DETECT_ALL_COLLISION,
		DAMAGE__SHOCK_ENEMY,
		32,
		0,
		NPC_SHOT_GENERIC,
		0,
		0,
		false,
		true,
		false,
		false,
		CSoundMediator::NUM_SFXIDS,
		CSoundMediator::NUM_SFXIDS,
	},

	{	// NPC_ANEMONE_1
		ACTORS_ANENOME_SBK,
		ANIM_ANENOME_FIRE,
		NPC_SENSOR_USER_CLOSE,
		NPC_MOVEMENT_STATIC_CYCLE_ANIM,
		NPC_CLOSE_NONE,
		NPC_TIMER_NONE,
		false,
		0,
		16,
		DETECT_NO_COLLISION,
		DAMAGE__NONE,
		16,
		0,
		NPC_SHOT_GENERIC,
		0,
		0,
		false,
		false,
		false,
		false,
		CSoundMediator::SFX_ANEMONE_DEFEATED_LEVEL1,
		CSoundMediator::NUM_SFXIDS,
	},

	{	// NPC_ANEMONE_2
		ACTORS_SPIKEYANENOME_SBK,
		ANIM_SPIKEYANENOME_BODY,
		NPC_SENSOR_USER_CLOSE,
		NPC_MOVEMENT_STATIC_CYCLE_ANIM,
		NPC_CLOSE_NONE,
		NPC_TIMER_NONE,
		false,
		0,
		128,
		DETECT_NO_COLLISION,
		DAMAGE__NONE,
		32,
		0,
		NPC_SHOT_GENERIC,
		0,
		0,
		false,
		false,
		false,
		false,
		CSoundMediator::SFX_ANEMONE_DEFEATED_LEVEL2,
		CSoundMediator::NUM_SFXIDS,
	},

	{	// NPC_ANEMONE_3
		ACTORS_ANENOME_SBK,
		ANIM_ANENOME_FIRE,
		NPC_SENSOR_USER_CLOSE,
		NPC_MOVEMENT_STATIC_CYCLE_ANIM,
		NPC_CLOSE_NONE,
		NPC_TIMER_NONE,
		false,
		0,
		16,
		DETECT_NO_COLLISION,
		DAMAGE__NONE,
		48,
		0,
		NPC_SHOT_GENERIC,
		0,
		0,
		false,
		false,
		false,
		false,
		CSoundMediator::SFX_ANEMONE_DEFEATED_LEVEL3,
		CSoundMediator::NUM_SFXIDS,
	},

	{	// NPC_SKELETAL_FISH
		ACTORS_SKELETALFISH_SBK,
		ANIM_SKELETALFISH_IDLE,
		NPC_SENSOR_GENERIC_USER_VISIBLE,
		NPC_MOVEMENT_FIXED_PATH,
		NPC_CLOSE_NONE,
		NPC_TIMER_NONE,
		false,
		3,
		2048,
		DETECT_ALL_COLLISION,
		DAMAGE__BITE_ENEMY,
		0,
		ANIM_SKELETALFISH_SWIM,
		NPC_SHOT_GENERIC,
		0,
		0,
		false,
		false,
		false,
		true,
		CSoundMediator::NUM_SFXIDS,
		CSoundMediator::NUM_SFXIDS,
	},

	{	// NPC_CLAM_JUMP
		ACTORS_CLAM_SBK,
		ANIM_CLAM_SNAPUP,
		NPC_SENSOR_USER_CLOSE,
		NPC_MOVEMENT_STATIC,
		NPC_CLOSE_NONE,
		NPC_TIMER_NONE,
		false,
		0,
		128,
		DETECT_ATTACK_COLLISION_GENERIC,
		DAMAGE__HIT_ENEMY,
		0,
		0,
		NPC_SHOT_GENERIC,
		0,
		0,
		false,
		false,
		false,
		false,
		CSoundMediator::SFX_CLAM_DEFEATED,
		CSoundMediator::NUM_SFXIDS,
	},

	{	// NPC_CLAM_STATIC
		ACTORS_CLAM_SBK,
		ANIM_CLAM_SIDESNAP,
		NPC_SENSOR_USER_CLOSE,
		NPC_MOVEMENT_STATIC,
		NPC_CLOSE_NONE,
		NPC_TIMER_NONE,
		false,
		0,
		128,
		DETECT_NO_COLLISION,
		DAMAGE__HIT_ENEMY,
		0,
		0,
		NPC_SHOT_GENERIC,
		0,
		0,
		false,
		false,
		false,
		false,
		CSoundMediator::NUM_SFXIDS,
		CSoundMediator::NUM_SFXIDS,
	},

	{	// NPC_SQUID_DART
		0,//ACTORS_SQUIDDART_SBK,
		FRM_SQUIDDART_SWIM0001,
		NPC_SENSOR_USER_CLOSE,
		NPC_MOVEMENT_FIXED_PATH,
		NPC_CLOSE_NONE,
		NPC_TIMER_NONE,
		false,
		2,
		2048,
		DETECT_ALL_COLLISION,
		DAMAGE__HIT_ENEMY,
		14,
		FRM_SQUIDDART_SWIM0001,
		NPC_SHOT_GENERIC,
		0,
		0,
		false,
		false,
		false,
		false,
		CSoundMediator::SFX_SQUIDDART_DEFEATED,
		CSoundMediator::SFX_SQUIDDART_MOVE,
	},

	{	// NPC_FISH_FOLK
		ACTORS_CLAM_SBK,
		ANIM_CLAM_SIDESNAP,
		NPC_SENSOR_NONE,
		NPC_MOVEMENT_FIXED_PATH_WALK,
		NPC_CLOSE_NONE,
		NPC_TIMER_NONE,
		false,
		2,
		2048,
		DETECT_NO_COLLISION,
		DAMAGE__NONE,
		0,
		0,
		NPC_SHOT_GENERIC,
		0,
		0,
		false,
		false,
		false,
		true,
		CSoundMediator::NUM_SFXIDS,
		CSoundMediator::NUM_SFXIDS,
	},

	{	// NPC_PRICKLY_BUG
		ACTORS_CATERPILLAR_SBK,
		ANIM_CATERPILLAR_CRAWL,
		NPC_SENSOR_NONE,
		NPC_MOVEMENT_FIXED_PATH_WALK,
		NPC_CLOSE_NONE,
		NPC_TIMER_NONE,
		false,
		1,
		128,
		DETECT_ALL_COLLISION,
		DAMAGE__POISON_ENEMY,
		9,
		ANIM_CATERPILLAR_CRAWL,
		NPC_SHOT_GENERIC,
		0,
		0,
		false,
		false,
		false,
		true,
		CSoundMediator::SFX_PRICKLY_BUG_DEFEATED,
		CSoundMediator::NUM_SFXIDS,
	},

	{	// NPC_SEA_SNAKE
		ACTORS_CLAM_SBK,
		ANIM_CLAM_SIDESNAP,
		NPC_SENSOR_NONE,
		NPC_MOVEMENT_FIXED_PATH,
		NPC_CLOSE_NONE,
		NPC_TIMER_NONE,
		false,
		3,
		256,
		DETECT_ATTACK_COLLISION_GENERIC,
		DAMAGE__SHOCK_ENEMY,
		56,
		0,
		NPC_SHOT_GENERIC,
		0,
		0,
		false,
		false,
		false,
		true,
		CSoundMediator::NUM_SFXIDS,
		CSoundMediator::NUM_SFXIDS,
	},

	{	// NPC_PUFFA_FISH
		ACTORS_PUFFAFISH_SBK,
		ANIM_PUFFAFISH_PUFFUPIDLE,
		NPC_SENSOR_USER_CLOSE,
		NPC_MOVEMENT_FIXED_PATH,
		NPC_CLOSE_NONE,
		NPC_TIMER_NONE,
		false,
		2,
		128,
		DETECT_ALL_COLLISION,
		DAMAGE__HIT_ENEMY,
		64,
		ANIM_PUFFAFISH_SWIM,
		NPC_SHOT_GENERIC,
		0,
		0,
		false,
		false,
		false,
		true,
		CSoundMediator::NUM_SFXIDS,
		CSoundMediator::NUM_SFXIDS,
	},

	{	// NPC_ANGLER_FISH
		ACTORS_CLAM_SBK,
		ANIM_CLAM_SIDESNAP,
		NPC_SENSOR_NONE,
		NPC_MOVEMENT_FIXED_PATH,
		NPC_CLOSE_NONE,
		NPC_TIMER_NONE,
		false,
		1,
		128,
		DETECT_NO_COLLISION,
		DAMAGE__NONE,
		0,
		0,
		NPC_SHOT_GENERIC,
		0,
		0,
		false,
		false,
		false,
		true,
		CSoundMediator::NUM_SFXIDS,
		CSoundMediator::NUM_SFXIDS,
	},

	{	// NPC_HERMIT_CRAB
		ACTORS_HERMITCRAB_SBK,
		ANIM_HERMITCRAB_IDLE,
		NPC_SENSOR_USER_CLOSE,
		NPC_MOVEMENT_FIXED_PATH_WALK,
		NPC_CLOSE_NONE,
		NPC_TIMER_NONE,
		false,
		2,
		128,
		DETECT_ATTACK_COLLISION_GENERIC,
		DAMAGE__HIT_ENEMY,
		14,
		ANIM_HERMITCRAB_SCUTTLE,
		NPC_SHOT_GENERIC,
		0,
		0,
		false,
		false,
		false,
		true,
		CSoundMediator::NUM_SFXIDS,
		CSoundMediator::NUM_SFXIDS,
	},

	{	// NPC_MINE
		ACTORS_CLAM_SBK,
		ANIM_CLAM_SIDESNAP,
		NPC_SENSOR_NONE,
		NPC_MOVEMENT_STATIC,
		NPC_CLOSE_NONE,
		NPC_TIMER_NONE,
		false,
		0,
		128,
		DETECT_ALL_COLLISION,
		DAMAGE__HIT_ENEMY,
		0,
		0,
		NPC_SHOT_GENERIC,
		0,
		0,
		false,
		false,
		false,
		true,
		CSoundMediator::NUM_SFXIDS,
		CSoundMediator::NUM_SFXIDS,
	},

	{	// NPC_BOOGER_MONSTER
		ACTORS_CLAM_SBK,
		ANIM_CLAM_SIDESNAP,
		NPC_SENSOR_USER_CLOSE,
		NPC_MOVEMENT_STATIC,
		NPC_CLOSE_NONE,
		NPC_TIMER_NONE,
		false,
		0,
		128,
		DETECT_ATTACK_COLLISION_GENERIC,
		DAMAGE__BITE_ENEMY,
		0,
		0,
		NPC_SHOT_GENERIC,
		0,
		0,
		false,
		false,
		false,
		true,
		CSoundMediator::NUM_SFXIDS,
		CSoundMediator::NUM_SFXIDS,
	},

	{	// NPC_SPIDER_CRAB
		ACTORS_SPIDERCRAB_SBK,
		ANIM_SPIDERCRAB_IDLE,
		NPC_SENSOR_USER_CLOSE,
		NPC_MOVEMENT_FIXED_PATH_WALK,
		NPC_CLOSE_NONE,
		NPC_TIMER_NONE,
		false,
		3,
		2048,
		DETECT_ATTACK_COLLISION_GENERIC,
		DAMAGE__PINCH_ENEMY,
		0,
		ANIM_SPIDERCRAB_RUN,
		NPC_SHOT_GENERIC,
		0,
		0,
		false,
		false,
		false,
		true,
		CSoundMediator::NUM_SFXIDS,
		CSoundMediator::SFX_SPIDERCRAB_MOVE,
	},

	{	// NPC_SPIDER_CRAB_SPAWNER
		ACTORS_SPIDERCRAB_SBK,
		ANIM_SPIDERCRAB_IDLE,
		NPC_SENSOR_NONE,
		NPC_MOVEMENT_STATIC,
		NPC_CLOSE_NONE,
		NPC_TIMER_NONE,
		false,
		3,
		2048,
		DETECT_NO_COLLISION,
		DAMAGE__PINCH_ENEMY,
		0,
		ANIM_SPIDERCRAB_RUN,
		NPC_SHOT_NONE,
		0,
		0,
		false,
		false,
		false,
		false,
		CSoundMediator::NUM_SFXIDS,
		CSoundMediator::NUM_SFXIDS,
	},

	{	// NPC_EYEBALL
		0,//ACTORS_EYEBALL_SBK,
		0,
		NPC_SENSOR_USER_CLOSE,
		NPC_MOVEMENT_STATIC,
		NPC_CLOSE_NONE,
		NPC_TIMER_NONE,
		false,
		0,
		128,
		DETECT_NO_COLLISION,
		DAMAGE__HIT_ENEMY,
		32,
		0,
		NPC_SHOT_GENERIC,
		0,
		0,
		false,
		false,
		false,
		false,
		CSoundMediator::NUM_SFXIDS,
		CSoundMediator::NUM_SFXIDS,
	},

	{	// NPC_BABY_OCTOPUS
		ACTORS_BABYOCTOPUS_SBK,
		ANIM_BABYOCTOPUS_SWIM,
		NPC_SENSOR_USER_CLOSE,
		NPC_MOVEMENT_FIXED_PATH,
		NPC_CLOSE_NONE,
		NPC_TIMER_NONE,
		false,
		2,
		512,
		DETECT_ATTACK_COLLISION_GENERIC,
		DAMAGE__HIT_ENEMY,
		32,
		ANIM_BABYOCTOPUS_SWIM,
		NPC_SHOT_GENERIC,
		0,
		0,
		false,
		false,
		false,
		true,
		CSoundMediator::NUM_SFXIDS,
		CSoundMediator::NUM_SFXIDS,
	},

	{	// NPC_ZOMBIE_FISH_FOLK
		ACTORS_CLAM_SBK,
		ANIM_CLAM_SIDESNAP,
		NPC_SENSOR_NONE,
		NPC_MOVEMENT_FIXED_PATH_WALK,
		NPC_CLOSE_NONE,
		NPC_TIMER_NONE,
		false,
		2,
		2048,
		DETECT_ALL_COLLISION,
		DAMAGE__HIT_ENEMY,
		16,
		0,
		NPC_SHOT_GENERIC,
		0,
		0,
		false,
		false,
		false,
		true,
		CSoundMediator::NUM_SFXIDS,
		CSoundMediator::NUM_SFXIDS,
	},

	{	// NPC_NINJA_STARFISH
		ACTORS_CLAM_SBK,
		ANIM_CLAM_SIDESNAP,
		NPC_SENSOR_GENERIC_USER_CLOSE,
		NPC_MOVEMENT_STATIC,
		NPC_CLOSE_GENERIC_USER_SEEK,
		NPC_TIMER_NONE,
		false,
		3,
		64,
		DETECT_ALL_COLLISION,
		DAMAGE__HIT_ENEMY,
		16,
		0,
		NPC_SHOT_GENERIC,
		0,
		0,
		false,
		false,
		false,
		true,
		CSoundMediator::NUM_SFXIDS,
		CSoundMediator::NUM_SFXIDS,
	},

	{	// NPC_GHOST
		ACTORS_GHOST_SBK,
		ANIM_GHOST_IDLE,
		NPC_SENSOR_NONE,
		NPC_MOVEMENT_FIXED_PATH,
		NPC_CLOSE_NONE,
		NPC_TIMER_NONE,
		false,
		2,
		128,
		DETECT_ALL_COLLISION,
		DAMAGE__HIT_ENEMY,
		0,
		ANIM_GHOST_MOVE,
		NPC_SHOT_GENERIC,
		0,
		0,
		false,
		false,
		false,
		true,
		CSoundMediator::NUM_SFXIDS,
		CSoundMediator::NUM_SFXIDS,
	},

	{	// NPC_GHOST_PIRATE
		ACTORS_CLAM_SBK,
		ANIM_CLAM_SIDESNAP,
		NPC_SENSOR_NONE,
		NPC_MOVEMENT_STATIC,
		NPC_CLOSE_NONE,
		NPC_TIMER_NONE,
		false,
		0,
		128,
		DETECT_ALL_COLLISION,
		DAMAGE__HIT_ENEMY,
		160,
		0,
		NPC_SHOT_GENERIC,
		0,
		0,
		false,
		false,
		false,
		true,
		CSoundMediator::NUM_SFXIDS,
		CSoundMediator::NUM_SFXIDS,
	},

	{	// NPC_FLAMING_SKULL
		ACTORS_FLAMINGSKULL_SBK,
		ANIM_FLAMINGSKULL_MOVE,
		NPC_SENSOR_USER_CLOSE,
		NPC_MOVEMENT_STATIC_CYCLE_ANIM,
		NPC_CLOSE_NONE,
		NPC_TIMER_NONE,
		false,
		3,
		128,
		DETECT_ALL_COLLISION,
		DAMAGE__BURN_ENEMY,
		16,
		ANIM_FLAMINGSKULL_MOVE,
		NPC_SHOT_GENERIC,
		0,
		0,
		false,
		false,
		false,
		true,
		CSoundMediator::NUM_SFXIDS,
		CSoundMediator::NUM_SFXIDS,
	},

	{	// NPC_SHARK_MAN
		ACTORS_SHARKMAN_SBK,
		ANIM_SHARKMAN_IDLE1_,
		NPC_SENSOR_GENERIC_USER_VISIBLE,
		NPC_MOVEMENT_STATIC,
		NPC_CLOSE_NONE,
		NPC_TIMER_NONE,
		false,
		3,
		2048,
		DETECT_ALL_COLLISION,
		DAMAGE__BITE_ENEMY,
		16,
		ANIM_SHARKMAN_RUN,
		NPC_SHOT_GENERIC,
		0,
		0,
		false,
		false,
		false,
		true,
		CSoundMediator::NUM_SFXIDS,
		CSoundMediator::NUM_SFXIDS,
	},

	{	// NPC_OIL_BLOB
		ACTORS_CLAM_SBK,
		ANIM_CLAM_SIDESNAP,
		NPC_SENSOR_GENERIC_USER_CLOSE,
		NPC_MOVEMENT_STATIC,
		NPC_CLOSE_GENERIC_USER_SEEK,
		NPC_TIMER_NONE,
		false,
		3,
		64,
		DETECT_ALL_COLLISION,
		DAMAGE__HIT_ENEMY,
		0,
		0,
		NPC_SHOT_GENERIC,
		0,
		0,
		false,
		false,
		false,
		true,
		CSoundMediator::NUM_SFXIDS,
		CSoundMediator::NUM_SFXIDS,
	},

	{	// NPC_SKULL_STOMPER
		ACTORS_STOMPER_SBK,
		ANIM_STOMPER_CRUSH,
		NPC_SENSOR_USER_CLOSE,
		NPC_MOVEMENT_STATIC,
		NPC_CLOSE_NONE,
		NPC_TIMER_NONE,
		false,
		5,
		2048,
		DETECT_ALL_COLLISION,
		DAMAGE__SQUASH_ENEMY,
		0,
		ANIM_STOMPER_CRUSH,
		NPC_SHOT_GENERIC,
		0,
		0,
		false,
		false,
		false,
		false,
		CSoundMediator::NUM_SFXIDS,
		CSoundMediator::NUM_SFXIDS,
	},

	{	// NPC_MOTHER_JELLYFISH
		ACTORS_MOTHERJELLYFISH_SBK,
		ANIM_CLAM_SIDESNAP,
		NPC_SENSOR_NONE,
		NPC_MOVEMENT_STATIC,
		NPC_CLOSE_NONE,
		NPC_TIMER_NONE,
		false,
		3,
		256,
		DETECT_ALL_COLLISION,
		DAMAGE__SHOCK_ENEMY,
		256,
		0,
		NPC_SHOT_GENERIC,
		0,
		0,
		false,
		false,
		false,
		false,
		CSoundMediator::NUM_SFXIDS,
		CSoundMediator::NUM_SFXIDS,
	},

	{	// NPC_SUB_SHARK
		ACTORS_SHARKSUB_SBK,
		ANIM_SHARKSUB_SWIM,
		NPC_SENSOR_NONE,
		NPC_MOVEMENT_STATIC,
		NPC_CLOSE_NONE,
		NPC_TIMER_NONE,
		false,
		3,
		2048,
		DETECT_NO_COLLISION,
		DAMAGE__HIT_ENEMY,
		256,
		0,
		NPC_SHOT_GENERIC,
		0,
		0,
		false,
		false,
		false,
		false,
		CSoundMediator::NUM_SFXIDS,
		CSoundMediator::NUM_SFXIDS,
	},

	{	// NPC_PARASITIC_WORM
		ACTORS_SEASNAKE_SBK,
		ANIM_SEASNAKE_HEADSTATIC,
		NPC_SENSOR_USER_CLOSE,
		NPC_MOVEMENT_STATIC,
		NPC_CLOSE_NONE,
		NPC_TIMER_NONE,
		false,
		3,
		128,
		DETECT_ALL_COLLISION,
		DAMAGE__HIT_ENEMY,
		256,
		0,
		NPC_SHOT_GENERIC,
		0,
		0,
		false,
		false,
		false,
		false,
		CSoundMediator::NUM_SFXIDS,
		CSoundMediator::NUM_SFXIDS,
	},

	{	// NPC_FLYING_DUTCHMAN
		ACTORS_FLYINGDUTCHMAN_SBK,
		ANIM_FLYINGDUTCHMAN_FLY,
		NPC_SENSOR_NONE,
		NPC_MOVEMENT_STATIC,
		NPC_CLOSE_NONE,
		NPC_TIMER_NONE,
		false,
		3,
		2048,
		DETECT_ALL_COLLISION,
		DAMAGE__HIT_ENEMY,
		256,
		ANIM_FLYINGDUTCHMAN_FLY,
		NPC_SHOT_GENERIC,
		0,
		ANIM_FLYINGDUTCHMAN_GETHIT,
		false,
		false,
		false,
		false,
		CSoundMediator::NUM_SFXIDS,
		CSoundMediator::NUM_SFXIDS,
	},

	{	// NPC_IRON_DOGFISH
		ACTORS_IRONDOGFISH_SBK,
		ANIM_IRONDOGFISH_IDLE,
		NPC_SENSOR_USER_CLOSE,
		NPC_MOVEMENT_STATIC,
		NPC_CLOSE_NONE,
		NPC_TIMER_NONE,
		false,
		3,
		2048,
		DETECT_ATTACK_COLLISION_GENERIC,
		DAMAGE__HIT_ENEMY,
		256,
		ANIM_IRONDOGFISH_WALK,
		NPC_SHOT_GENERIC,
		0,
		ANIM_IRONDOGFISH_GETHIT,
		false,
		false,
		false,
		false,
		CSoundMediator::NUM_SFXIDS,
		CSoundMediator::NUM_SFXIDS,
	},

	{	// NPC_PARASITIC_WORM_SEGMENT
		ACTORS_SEASNAKE_SBK,
		ANIM_SEASNAKE_BODYSTATIC,
		NPC_SENSOR_NONE,
		NPC_MOVEMENT_STATIC,
		NPC_CLOSE_NONE,
		NPC_TIMER_NONE,
		false,
		3,
		2048,
		DETECT_ALL_COLLISION,
		DAMAGE__HIT_ENEMY,
		256,
		0,
		NPC_SHOT_GENERIC,
		0,
		0,
		false,
		false,
		false,
		false,
		CSoundMediator::NUM_SFXIDS,
		CSoundMediator::NUM_SFXIDS,
	},

	{	// NPC_BALL_BLOB
		ACTORS_BALLBLOB_SBK,
		ANIM_BALLBLOB_IDLE,
		NPC_SENSOR_NONE,
		NPC_MOVEMENT_STATIC,
		NPC_CLOSE_NONE,
		NPC_TIMER_NONE,
		false,
		3,
		128,
		DETECT_ALL_COLLISION,
		DAMAGE__BURN_ENEMY,
		16,
		ANIM_BALLBLOB_IDLE,
		NPC_SHOT_GENERIC,
		0,
		0,
		false,
		false,
		false,
		true,
		CSoundMediator::NUM_SFXIDS,
		CSoundMediator::NUM_SFXIDS,
	},

	{	// NPC_SHELL
		0,//ACTORS_SHELL_SBK,
		0,
		NPC_SENSOR_NONE,
		NPC_MOVEMENT_STATIC,
		NPC_CLOSE_NONE,
		NPC_TIMER_NONE,
		false,
		3,
		128,
		DETECT_NO_COLLISION,
		DAMAGE__BURN_ENEMY,
		16,
		0,
		NPC_SHOT_GENERIC,
		0,
		0,
		false,
		true,
		true,
		false,
		CSoundMediator::NUM_SFXIDS,
		CSoundMediator::NUM_SFXIDS,
	},

	{	// NPC_PROJECTILE_JELLYFISH
		0,//ACTORS_JELLYFISH1_SBK,
		FRM_JELLYFISH1_SWIM1,
		NPC_SENSOR_USER_CLOSE,
		NPC_MOVEMENT_FIXED_PATH,
		NPC_CLOSE_NONE,
		NPC_TIMER_NONE,
		false,
		2,
		128,
		DETECT_ALL_COLLISION,
		DAMAGE__SHOCK_ENEMY,
		16,
		FRM_JELLYFISH1_SWIM1,
		NPC_SHOT_GENERIC,
		0,
		FRM_JELLYFISH1_SWIM1,
		true,
		true,
		false,
		false,
		CSoundMediator::NUM_SFXIDS,
		CSoundMediator::NUM_SFXIDS,
	},

	{	// NPC_MOTHER_JELLYFISH_BACKGROUND
		ACTORS_MOTHERJELLYFISH_SBK,
		ANIM_CLAM_SIDESNAP,
		NPC_SENSOR_NONE,
		NPC_MOVEMENT_FIXED_PATH,
		NPC_CLOSE_NONE,
		NPC_TIMER_NONE,
		false,
		2,
		128,
		DETECT_NO_COLLISION,
		DAMAGE__SHOCK_ENEMY,
		256,
		0,
		NPC_SHOT_GENERIC,
		0,
		0,
		false,
		false,
		false,
		false,
		CSoundMediator::NUM_SFXIDS,
		CSoundMediator::NUM_SFXIDS,
	},

	{	// NPC_SMALL_JELLYFISH_BACKGROUND
		0,//ACTORS_JELLYFISH1_SBK,
		FRM_JELLYFISH1_SWIM1,
		NPC_SENSOR_USER_CLOSE,
		NPC_MOVEMENT_FIXED_PATH,
		NPC_CLOSE_NONE,
		NPC_TIMER_NONE,
		false,
		2,
		128,
		DETECT_NO_COLLISION,
		DAMAGE__NONE,
		16,
		FRM_JELLYFISH1_SWIM1,
		NPC_SHOT_GENERIC,
		0,
		FRM_JELLYFISH1_SWIM1,
		true,
		false,
		false,
		false,
		CSoundMediator::NUM_SFXIDS,
		CSoundMediator::NUM_SFXIDS,
	},

	{	// NPC_SMALL_JELLYFISH_2_BACKGROUND
		0,//ACTORS_JELLYFISH1_SBK,
		FRM_JELLYFISH1_SWIM1,
		NPC_SENSOR_USER_CLOSE,
		NPC_MOVEMENT_FIXED_PATH,
		NPC_CLOSE_NONE,
		NPC_TIMER_NONE,
		false,
		2,
		128,
		DETECT_ALL_COLLISION,
		DAMAGE__SHOCK_ENEMY,
		16,
		FRM_JELLYFISH1_SWIM1,
		NPC_SHOT_GENERIC,
		0,
		FRM_JELLYFISH1_SWIM1,
		true,
		false,
		false,
		false,
		CSoundMediator::NUM_SFXIDS,
		CSoundMediator::NUM_SFXIDS,
	},

	{	// NPC_BUTTERFLY_BACKGROUND
		0,//ACTORS_BUTTERFLY_SBK,
		FRM_JELLYFISH1_SWIM1,
		NPC_SENSOR_USER_CLOSE,
		NPC_MOVEMENT_FIXED_PATH,
		NPC_CLOSE_NONE,
		NPC_TIMER_NONE,
		false,
		2,
		128,
		DETECT_NO_COLLISION,
		DAMAGE__NONE,
		16,
		FRM_JELLYFISH1_SWIM1,
		NPC_SHOT_GENERIC,
		0,
		FRM_JELLYFISH1_SWIM1,
		false,
		false,
		false,
		false,
		CSoundMediator::NUM_SFXIDS,
		CSoundMediator::NUM_SFXIDS,
	},
};

CNpcEnemy::NPC_UNIT_TYPE CNpcEnemy::mapEditConvertTable[NPC_UNIT_TYPE_MAX] =
{
	NPC_SMALL_JELLYFISH_1,
	NPC_SMALL_JELLYFISH_2,
	NPC_MOTHER_JELLYFISH,
	NPC_ANEMONE_1,
	NPC_ANEMONE_2,
	NPC_ANEMONE_3,
	NPC_BABY_OCTOPUS,
	NPC_BALL_BLOB,
	NPC_BOOGER_MONSTER,
	NPC_PRICKLY_BUG,
	NPC_CLAM_JUMP,
	NPC_CLAM_STATIC,
	NPC_EYEBALL,
	NPC_FLAMING_SKULL,
	NPC_FLYING_DUTCHMAN,
	NPC_GHOST,
	NPC_PARASITIC_WORM,
	NPC_HERMIT_CRAB,
	NPC_IRON_DOGFISH,
	NPC_PUFFA_FISH,
	NPC_SEA_SNAKE,
	NPC_SHARK_MAN,
	NPC_SUB_SHARK,
	NPC_SKELETAL_FISH,
	NPC_SPIDER_CRAB,
	NPC_SQUID_DART,
	NPC_SKULL_STOMPER,
	NPC_DUST_DEVIL,
	NPC_SPIDER_CRAB_SPAWNER,
	NPC_SHELL,

	//
	NPC_FISH_FOLK,
	NPC_ANGLER_FISH,
	NPC_MINE,
	NPC_ZOMBIE_FISH_FOLK,
	NPC_NINJA_STARFISH,
	NPC_GHOST_PIRATE,
	NPC_OIL_BLOB,
	NPC_PARASITIC_WORM_SEGMENT,
	NPC_MOTHER_JELLYFISH_BACKGROUND,
};
