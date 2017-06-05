// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "Logging/MessageLog.h"

//不要把LOCTEXT_NAMESPACE Define在这里，在对应的CPP中定义，在CPP结尾undefine掉,否则会有可能跟引擎内部的LOCTEXT_NAMESPACE冲突
//#define LOCTEXT_NAMESPACE "DAWA_CoolGameLog"
#define COLLISION_BOOM ECC_GameTraceChannel1
extern FName LoggerName;