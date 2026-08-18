Semarang_BonekaCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SemarangBonekaCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

SemarangBonekaCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_SEMARANG
	end
	
SemarangBonekaCenter1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_SEMARANG_NURSE
	call Common_EventScript_JavaBnkaCenterNurse
	waitmessage
	waitbuttonpress
	release
	end
