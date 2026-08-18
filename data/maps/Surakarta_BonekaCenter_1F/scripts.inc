Surakarta_BonekaCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SurakartaBonekaCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

SurakartaBonekaCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_SURAKARTA
	end
	
SurakartaBonekaCenter1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_SURAKARTA_NURSE
	call Common_EventScript_JavaBnkaCenterNurse
	waitmessage
	waitbuttonpress
	release
	end
