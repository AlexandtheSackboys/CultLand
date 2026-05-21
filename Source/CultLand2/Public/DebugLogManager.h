// Fill out your copyright notice in the Description page of Project Settings.

// ----------------------------------------------------------	
// Script (Header and Source files) Name: [DebugLogManager]
// 
// Author: [Alex Costin]
// 
// Editors: []
// 
// Description: [this class is responsible for managing log categories that can be used throughout the project]
// 
// creation Date: [21/05/26]
// 
// last edited: [21/05/26 by Alex Costin]
// 
// Editors Contributions: []
// ----------------------------------------------------------	
#pragma once

#include "CoreMinimal.h"

// ERROR CATEGORIES



// hit scan error log category
DECLARE_LOG_CATEGORY_EXTERN(HitScanError, Error, All);

// weapon error log category
DECLARE_LOG_CATEGORY_EXTERN(WeaponError, Error, All);

// player error log category
DECLARE_LOG_CATEGORY_EXTERN(PlayerError, Error, All);

// progression error (e.g., Door) log category
DECLARE_LOG_CATEGORY_EXTERN(ProgressionError, Error, All);

// Log category for projectile errors
DECLARE_LOG_CATEGORY_EXTERN(ProjectileError, Error, All);

// WARNING CATEGORIES

// progression warning log category
DECLARE_LOG_CATEGORY_EXTERN(ProgressionWarning, Warning, All);

// player warning log category
DECLARE_LOG_CATEGORY_EXTERN(PlayerWarning, Warning, All);

// hit scan warning log category
DECLARE_LOG_CATEGORY_EXTERN(HitScanWarning, Warning, All);

// weapon warning log category
DECLARE_LOG_CATEGORY_EXTERN(WeaponWarning, Warning, All);

// Log category for projectile warnings
DECLARE_LOG_CATEGORY_EXTERN(ProjectileWarning, Warning, All);

/**
 * 
 */
class CULTLAND2_API DebugLogManager
{
public:
	DebugLogManager();
	~DebugLogManager();


};
