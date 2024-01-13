#include "script_component.hpp"
/*
 * Author: Krzyciu, SzwedzikPL
 * Validator for setAnimation module
 */

params ["_module", "_values"];

private _warnings = [];

private _syncedUnits = (get3DENConnections _module) select {
  ((_x #0) isEqualTo "Sync") && {(_x #1) isKindOf "CAManBase"}
};

if ((count _syncedUnits) isNotEqualTo 1) then {
  _warnings pushBack [
    LLSTRING(setAnimation_Warning_SyncError),
    LLSTRING(setAnimation_Warning_SyncError_Desc)
  ];
};

_warnings