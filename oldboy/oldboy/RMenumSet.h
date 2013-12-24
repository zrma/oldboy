﻿#pragma once

enum SceneType
{
	SCENE_NONE,

	SCENE_OPENING,
	SCENE_TITLE,
	SCENE_SELECT_MUSIC,
	SCENE_PLAY,
	SCENE_RESULT,

	SCENE_MAX
};

enum LayerType
{
	LAYER_NONE,

	LAYER_BACKGROUND,

	LAYER_JUDGE_GAUGE,		// Judge 판정링과 게이지가 들어가는 레이어
	LAYER_ITEM,				// item 카드와 Item Display가 들어가는 레이어
	LAYER_CARD,

	LAYER_NOTE1,
	LAYER_NOTE2,
	LAYER_NOTE_HIT,

	LAYER_EFFECT,

	LAYER_SHUTTER,

	LAYER_LABEL,
	LAYER_MEMORY_POOL,

	
	LAYER_TOOLTIP,
	LAYER_ALBUM_IMAGE,
	LAYER_UI,
	LAYER_PAUSE,

	LAYER_MAX
};

enum AlbumImageType
{
	ALBUM_IMAGE_NONE,

	ALBUM_IMAGE_STATIC,
	ALBUM_IMAGE_DYNAMIC,

	ALBUM_IMAGE_MAX
};

enum WidgetType
{
	WIDGET_NONE,

	WIDGET_BG_IMAGE_TITLE,
	WIDGET_BG_IMAGE_SELECT,
	WIDGET_BG_IMAGE_PLAY,
	WIDGET_BG_IMAGE_RESULT,

	WIDGET_PAUSE_IMAGE_PLAY_CANCEL,
	WIDGET_PAUSE_IMAGE_PLAY_OK,
	WIDGET_PAUSE_IMAGE_TITLE_CANCEL,
	WIDGET_PAUSE_IMAGE_TITLE_OK,

	WIDGET_UI_IMAGE_SELECT_BAR_0,
	WIDGET_UI_IMAGE_SELECT_BAR_1,
	WIDGET_UI_IMAGE_SELECT_BAR_2,
	WIDGET_UI_IMAGE_SELECT_BAR_3,
	WIDGET_UI_IMAGE_SELECT_BAR_4,
	WIDGET_UI_IMAGE_SELECT_BAR_5,

	WIDGET_UI_IMAGE_RESULT_WIN_CLEAR,
	WIDGET_UI_IMAGE_RESULT_WIN_FAIL,
	WIDGET_UI_IMAGE_RESULT_LOSE_CLEAR,
	WIDGET_UI_IMAGE_RESULT_LOSE_FAIL,

	WIDGET_UI_IMAGE_PLAY_CPU_MODE,

	WIDGET_TITLE_MODE_SINGLE,
	WIDGET_TITLE_MODE_DUAL,
	WIDGET_TITLE_MODE_TUTORIAL,
	WIDGET_TITLE_MODE_EXIT,

	WIDGET_JUDGE_RING,
	WIDGET_GAUGE_1P,
	WIDGET_GAUGE_2P,
	WIDGET_PLAY_JUDGE_PERFECT,
	WIDGET_PLAY_JUDGE_GOOD,
	WIDGET_PLAY_JUDGE_MISS,
	WIDGET_PLAY_JUDGE_NONE,

	WIDGET_PLAY_ALERT_GROW_BLUE,
	WIDGET_PLAY_ALERT_GROW_RED,

	WIDGET_ITEM_CARD_NONE,

	WIDGET_ITEM_T1_SCORE_UP_CARD,
	WIDGET_ITEM_T1_MIST_CARD,
	WIDGET_ITEM_T1_DUPLICATE_CARD,
	WIDGET_ITEM_T2_DELAY_CARD,
	WIDGET_ITEM_T2_ROTATE_CARD,
	WIDGET_ITEM_T2_GAUGE_CLEAR_CARD,
	WIDGET_ITEM_T2_BARRIER_CARD,
	WIDGET_ITEM_T3_REVERSE_CARD,
	WIDGET_ITEM_T3_RECOVERY_CARD,

	WIDGET_ITEM_COLOR_MIN,

	WIDGET_ITEM_T1_SCORE_UP_COLOR,		// 점수 부스터
	WIDGET_ITEM_T1_MIST_COLOR,			// 안개
	WIDGET_ITEM_T1_DUPLICATE_COLOR,		// 따다닥
	WIDGET_ITEM_T2_DELAY_COLOR,			// 노트 밀림
	WIDGET_ITEM_T2_ROTATE_COLOR,		// 노트 빙글 회전
	WIDGET_ITEM_T2_GAUGE_CLEAR_COLOR,	// 상대방 공격 게이지 클리어
	WIDGET_ITEM_T2_BARRIER_COLOR,		// 보호막
	WIDGET_ITEM_T3_REVERSE_COLOR,		// 노트가 계속 반전
	WIDGET_ITEM_T3_RECOVERY_COLOR,		// 셔터 회복
	
	WIDGET_ITEM_COLOR_MAX,


	WIDGET_ITEM_T1_SCORE_UP_COLOR_OUT,		// 점수 부스터
	WIDGET_ITEM_T1_MIST_COLOR_OUT,			// 안개
	WIDGET_ITEM_T1_DUPLICATE_COLOR_OUT,		// 따다닥
	WIDGET_ITEM_T2_DELAY_COLOR_OUT,			// 노트 밀림
	WIDGET_ITEM_T2_ROTATE_COLOR_OUT,		// 노트 빙글 회전
	WIDGET_ITEM_T2_GAUGE_CLEAR_COLOR_OUT,	// 상대방 공격 게이지 클리어
	WIDGET_ITEM_T2_BARRIER_COLOR_OUT,		// 보호막
	WIDGET_ITEM_T3_REVERSE_COLOR_OUT,		// 노트가 계속 반전
	WIDGET_ITEM_T3_RECOVERY_COLOR_OUT,		// 셔터 회복


	WIDGET_ITEM_T1_SCORE_UP_GRAY,
	WIDGET_ITEM_T1_MIST_GRAY,
	WIDGET_ITEM_T1_DUPLICATE_GRAY,
	WIDGET_ITEM_T2_DELAY_GRAY,
	WIDGET_ITEM_T2_ROTATE_GRAY,
	WIDGET_ITEM_T2_GAUGE_CLEAR_GRAY,
	WIDGET_ITEM_T2_BARRIER_GRAY,
	WIDGET_ITEM_T3_REVERSE_GRAY,
	WIDGET_ITEM_T3_RECOVERY_GRAY,

	WIDGET_NOTE_NORMAL_1,
	WIDGET_NOTE_NORMAL_2,
	WIDGET_EFFECT,
	WIDGET_NOTE_HIT,
	WIDGET_SHUTTER,

	WIDGET_ALBUM_IMAGE,
	WIDGET_MOVING_ALBUM_IMAGE,

	WIDGET_TOOLTIP_1,
	WIDGET_TOOLTIP_2,
	WIDGET_TOOLTIP_3,

	WIDGET_MAX
};

enum SoundType
{
	SOUND_NONE,

	SOUND_BG_TITLE,
	SOUND_BG_PLAY,
	SOUND_BG_RESULT,

	SOUND_EFFECT_SELECT_MUSIC_CALL,
	SOUND_EFFECT_SELECT_MUSIC_FLIP,
	SOUND_EFFECT_SELECT_MUSIC_START,
	SOUND_EFFECT_RESULT_CLEAR,
	SOUND_EFFECT_RESULT_FAIL,
	SOUND_EFFECT_PAUSE_CANCEL,
	SOUND_EFFECT_PAUSE_FLIP,
	SOUND_EFFECT_PAUSE_OK,
	SOUND_EFFECT_PAUSE_OPEN,

	SOUND_NOTE_1,
	SOUND_NOTE_2,
	SOUND_NOTE_EFFECT,
	SOUND_SHUTTER,

	SOUND_MAX
};

enum PlayerNumber
{
	PLAYER_NONE,

	PLAYER_ONE,
	PLAYER_TWO,

	PLAYER_MAX
};

enum CountType
{
	COUNT_NONE,

	COUNT_PERFECT,
	COUNT_GOOD,
	COUNT_MISS,
	COUNT_COMBO,
	COUNT_MAX_COMBO,
	COUNT_COMBO_SCORE,
	COUNT_SCORE,

	COUNT_MAX
};

enum JudgeType
{
	JUDGE_NONE,

	JUDGE_PERFECT,
	JUDGE_GOOD,
	JUDGE_MISS,

	JUDGE_MAX
};

enum KeyStatus
{
	KEY_STATUS_NONE,

	KEY_STATUS_DOWN,
	KEY_STATUS_PRESSED,
	KEY_STATUS_UP,
	KEY_STATUS_NOT_PRESSED,

	KEY_MAX
};

enum ItemType
{
	ITEM_TYPE_NONE,
	//////////////////////////////////////////////////////////////////////////
	// 1 Tier
	ITEM_T1_NONE,

	ITEM_T1_SCORE_UP,	// 점수 부스터
	ITEM_T1_MIST,		// 안개
	ITEM_T1_DUPLICATE,	// 따다닥
	
	ITEM_T1_MAX,
	//////////////////////////////////////////////////////////////////////////
	// 2 Tier
	ITEM_T2_NONE,

	ITEM_T2_DELAY,		// 노트 밀림
	ITEM_T2_ROTATE,		// 노트 빙글 회전
	ITEM_T2_GAUGE_CLEAR,// 상대방 공격 게이지 클리어
	ITEM_T2_BARRIER,	// 보호막

	ITEM_T2_MAX,
	//////////////////////////////////////////////////////////////////////////
	// 3 Tier
	ITEM_T3_NONE,

	ITEM_T3_REVERSE,	// 노트가 계속 반전
	ITEM_T3_RECOVERY,	// 셔터 회복

	ITEM_T3_MAX,
	//////////////////////////////////////////////////////////////////////////
	// END
	ITEM_TYPE_MAX
}; // 추후 아이템 구현에 맞게 수정합시다.

enum ItemTierType
{
	TIER_NONE,

	TIER_1P_ONE,
	TIER_1P_TWO,
	TIER_1P_THREE,

	TIER_1P_2P_DIVIDE,

	TIER_2P_ONE,
	TIER_2P_TWO,
	TIER_2P_THREE,

	TIER_MAX
};

enum ModeType
{
	MODE_NONE,

	MODE_SINGLE,
	MODE_DUAL,
	MODE_TUTORIAL,
	MODE_EXIT,

	MODE_MAX
};