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

#ifndef __ANIM_MANRAY_HEADER__
#include <ACTOR_MANRAY_ANIM.h>
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

#ifndef	__ANIM_GIANTWORM_HEADER__
#include <ACTOR_GIANTWORM_ANIM.h>
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
		DETECT_ALL_COLLISION,
		DAMAGE__HIT_ENEMY,
		1,
		ANIM_DUSTDEVIL_TWIST,
		NPC_SHOT_GENERIC,
		0,
		0,
		false,
		false,
		false,
		false,
		CSoundMediator::NUM_SFXIDS,
		CSoundMediator::NUM_SFXIDS,
		false,
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
		1,
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
		false,
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
		1,
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
		false,
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
		1,
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
		false,
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
		1,
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
		false,
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
		1,
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
		false,
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
		1,
		ANIM_SKELETALFISH_SWIM,
		NPC_SHOT_GENERIC,
		0,
		0,
		false,
		false,
		false,
		true,
		CSoundMediator::NUM_SFXIDS,
		CSoundMediator::SFX_FISH_FOLK_MOVE_1,
		false,
	},

	{	// NPC_CLAM_JUMP
		ACTORS_CLAM_SBK,
		ANIM_CLAM_SNAPUP,
		NPC_SENSOR_USER_CLOSE,
		NPC_MOVEMENT_STATIC,
		NPC_CLOSE_NONE,
		NPC_TIMER_NONE,
		false,
		3,
		128,
		DETECT_ATTACK_COLLISION_GENERIC,
		DAMAGE__HIT_ENEMY,
		1,
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
		false,
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
		1,
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
		false,
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
		1,
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
		false,
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
		1,
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
		false,
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
		1,
		ANIM_CATERPILLAR_CRAWL,
		NPC_SHOT_GENERIC,
		ANIM_CATERPILLAR_DIE,
		0,
		false,
		false,
		false,
		true,
		CSoundMediator::SFX_PRICKLY_BUG_DEFEATED,
		CSoundMediator::SFX_PRICKLY_BUG_MOVE,
		true,
	},

	{	// NPC_SEA_SNAKE
		ACTORS_SEASNAKE_SBK,
		ANIM_SEASNAKE_HEADSNAP,
		NPC_SENSOR_USER_CLOSE,
		NPC_MOVEMENT_FIXED_PATH,
		NPC_CLOSE_NONE,
		NPC_TIMER_NONE,
		false,
		3,
		64,
		DETECT_ALL_COLLISION,
		DAMAGE__SHOCK_ENEMY,
		1,
		0,
		NPC_SHOT_GENERIC,
		0,
		0,
		false,
		false,
		false,
		true,
		CSoundMediator::NUM_SFXIDS,
		CSoundMediator::SFX_WORM___SWIM,
		false,
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
		1,
		ANIM_PUFFAFISH_SWIM,
		NPC_SHOT_GENERIC,
		0,
		0,
		false,
		false,
		false,
		true,
		CSoundMediator::NUM_SFXIDS,
		CSoundMediator::SFX_PUFFAFISH_MOVE,
		false,
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
		1,
		0,
		NPC_SHOT_GENERIC,
		0,
		0,
		false,
		false,
		false,
		true,
		CSoundMediator::NUM_SFXIDS,
		CSoundMediator::SFX_ANGLER_FISH_MOVE,
		false,
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
		1,
		ANIM_HERMITCRAB_SCUTTLE,
		NPC_SHOT_GENERIC,
		ANIM_HERMITCRAB_DIE,
		0,
		false,
		false,
		false,
		true,
		CSoundMediator::SFX_PRICKLY_BUG_DEFEATED,
		CSoundMediator::NUM_SFXIDS,
		true,
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
		1,
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
		false,
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
		1,
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
		false,
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
		1,
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
		false,
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
		1,
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
		false,
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
		1,
		ANIM_BABYOCTOPUS_SWIM,
		NPC_SHOT_GENERIC,
		ANIM_BABYOCTOPUS_DIE,
		0,
		false,
		false,
		false,
		true,
		CSoundMediator::NUM_SFXIDS,
		CSoundMediator::SFX_NAUTILUS_MOVE,
		true,
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
		1,
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
		false,
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
		1,
		ANIM_GHOST_IDLE,
		NPC_SHOT_GENERIC,
		0,
		0,
		false,
		false,
		false,
		true,
		CSoundMediator::NUM_SFXIDS,
		CSoundMediator::SFX_GHOST,
		false,
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
		1,
		ANIM_FLAMINGSKULL_MOVE,
		NPC_SHOT_GENERIC,
		0,
		0,
		false,
		false,
		false,
		true,
		CSoundMediator::SFX_FLAMING_SKULL_DEFEATED,
		CSoundMediator::SFX_FLAMING_SKULL_MOVE,
		false,
	},

	{	// NPC_SHARK_MAN
		ACTORS_MANRAY_SBK,
		ANIM_MANRAY_WALK,
		NPC_SENSOR_GENERIC_USER_VISIBLE,
		NPC_MOVEMENT_STATIC,
		NPC_CLOSE_NONE,
		NPC_TIMER_NONE,
		false,
		3,
		2048,
		DETECT_ALL_COLLISION,
		DAMAGE__BITE_ENEMY,
		1,
		ANIM_MANRAY_WALK,
		NPC_SHOT_GENERIC,
		0,
		0,
		false,
		false,
		false,
		true,
		CSoundMediator::NUM_SFXIDS,
		CSoundMediator::NUM_SFXIDS,
		false,
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
		1,
		ANIM_STOMPER_CRUSH,
		NPC_SHOT_NONE,
		0,
		0,
		false,
		false,
		false,
		false,
		CSoundMediator::NUM_SFXIDS,
		CSoundMediator::NUM_SFXIDS,
		false,
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
		50,
		0,
		NPC_SHOT_GENERIC,
		0,
		0,
		false,
		false,
		false,
		false,
		CSoundMediator::SFX_JELLYFISH_DEFEATED,
		CSoundMediator::SFX_BOSS_JELLYFISH_MOVE,
		false,
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
		DETECT_ALL_COLLISION,
		DAMAGE__HIT_ENEMY,
		50,
		0,
		NPC_SHOT_GENERIC,
		ANIM_SHARKSUB_DEATH,
		0,
		false,
		false,
		false,
		false,
		CSoundMediator::NUM_SFXIDS,
		CSoundMediator::SFX_SHARK___SWIM,
		true,
	},

	{	// NPC_PARASITIC_WORM
		ACTORS_GIANTWORM_SBK,
		ANIM_GIANTWORM_HEADSTATIC,
		NPC_SENSOR_USER_CLOSE,
		NPC_MOVEMENT_STATIC,
		NPC_CLOSE_NONE,
		NPC_TIMER_NONE,
		false,
		3,
		128,
		DETECT_ALL_COLLISION,
		DAMAGE__HIT_ENEMY,
		1,
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
		false,
	},

	{	// NPC_FLYING_DUTCHMAN
		ACTORS_FLYINGDUTCHMAN_SBK,
		ANIM_FLYINGDUTCHMAN_FLY,
		NPC_SENSOR_NONE,
		NPC_MOVEMENT_STATIC,
		NPC_CLOSE_NONE,
		NPC_TIMER_NONE,
		false,
		5,
		2048,
		DETECT_ALL_COLLISION,
		DAMAGE__HIT_ENEMY,
		50,
		ANIM_FLYINGDUTCHMAN_FLY,
		NPC_SHOT_GENERIC,
		ANIM_FLYINGDUTCHMAN_DEATH,
		ANIM_FLYINGDUTCHMAN_GETHIT,
		false,
		false,
		false,
		false,
		CSoundMediator::NUM_SFXIDS,
		CSoundMediator::NUM_SFXIDS,
		true,
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
		//DETECT_ALL_COLLISION,
		DETECT_ATTACK_COLLISION_GENERIC,
		DAMAGE__HIT_ENEMY,
		50,
		ANIM_IRONDOGFISH_WALK,
		NPC_SHOT_GENERIC,
		ANIM_IRONDOGFISH_DIE,
		ANIM_IRONDOGFISH_GETHIT,
		false,
		false,
		false,
		false,
		CSoundMediator::NUM_SFXIDS,
		CSoundMediator::SFX_DOGFISH_STOMP,
		true,
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
		1,
		ANIM_BALLBLOB_IDLE,
		NPC_SHOT_GENERIC,
		0,
		0,
		false,
		false,
		false,
		true,
		CSoundMediator::NUM_SFXIDS,
		CSoundMediator::SFX_BALL_BLOB_MOVE,
		false,
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
		1,
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
		false,
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
		1,
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
		false,
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
		1,
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
		false,
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
		1,
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
		false,
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
		1,
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
		false,
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
	NPC_ZOMBIE_FISH_FOLK,
};
