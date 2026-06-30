// Fill out your copyright notice in the Description page of Project Settings.


#include "DebugLogManager.h"

// HITSCAN LOG CATEGORIES
DEFINE_LOG_CATEGORY(HitScanError);
DEFINE_LOG_CATEGORY(HitScanWarning);

// WEAPON LOG CATEGORIES
DEFINE_LOG_CATEGORY(WeaponError);
DEFINE_LOG_CATEGORY(WeaponWarning);
// PLAYER LOG CATEGORIES
DEFINE_LOG_CATEGORY(PlayerError);
DEFINE_LOG_CATEGORY(PlayerWarning);
// PROGRESSION LOG CATEGORIES
DEFINE_LOG_CATEGORY(ProgressionError);
DEFINE_LOG_CATEGORY(ProgressionWarning);

// PROJECTILE LOG CATEGORIES
DEFINE_LOG_CATEGORY(ProjectileError);
DEFINE_LOG_CATEGORY(ProjectileWarning);

// PICKUPS LOG CATEGORIES
DEFINE_LOG_CATEGORY(PickupError);
DEFINE_LOG_CATEGORY(PickupWarning);
DebugLogManager::DebugLogManager()
{
}

DebugLogManager::~DebugLogManager()
{
}


