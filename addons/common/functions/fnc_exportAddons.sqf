/*
 * Author: SzwedzikPL
 * Exports all loaded addons
 */
#include "script_component.hpp"

diag_log text format ["//==   %1 %2 %3   ==//", productVersion select 0, productVersion select 2, productVersion select 4];
diag_log text "//======================================//";
diag_log text "//                ADDONS                //";
diag_log text "//======================================//";
diag_log text "";

private _configs = "true" configClasses (configFile >> "CfgPatches");
{
    private _configName = configname _x;
    diag_log _configName;
} foreach _configs;
