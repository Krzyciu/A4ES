#include "script_component.hpp"
/*
 * Author: Krzyciu, SzwedzikPL
 * setAnimation module function
 */

params ["_mode", "_input"];
TRACE_2(QUOTE(EXEC_MODULE_NAME),_mode,_input);

if (
  (_mode isEqualTo "attributesChanged3DEN") ||
  {_mode isEqualTo "registeredToWorld3DEN"}
) exitWith {
  _input params ["_logic"];
  _logic call FUNC(setAnimation_moduleExecEditor);
};

// Exit if module executed inside editor, not on server or not in init mode
if (is3DEN || !(isServer) || (_mode isNotEqualTo "init")) exitWith {};
_input params [
  ["_logic", objNull, [objNull]],
  ["_isActivated", false, [true]],
  ["_isCuratorPlaced", false, [true]]
];
// Exit if module is null or placed by zeus (should not happen)
if (isNull _logic || _isCuratorPlaced) exitWith {};

LOG('Starting execution of EXEC_MODULE_NAME.');

if (is3DENPreview) then {
  [_logic, true] call EFUNC(debug,updateModuleStatus);
};

private _units = (synchronizedObjects _logic) select {(_x isKindOf "CAManBase")};

private _animType = _logic getVariable [QGVAR(mode), 0];
private _anim = [_logic getVariable [QGVAR(predefinedAnim), ""], _logic getVariable [QGVAR(customAnim), ""]] select _animType;
private _loopAnimation = _logic getVariable [QGVAR(loopAnimation), false];
private _loopCondition = false;

if (_loopAnimation) then {
  _loopCondition = compile (_logic getVariable [QGVAR(loopCondition), "true"]);
};

[FUNC(setAnimation_moduleExec), [_units, _anim, _loopAnimation, _loopCondition], 5] call CBA_fnc_waitAndExecute;

// Delete logic
deleteVehicle _logic;

LOG('Execution of EXEC_MODULE_NAME finished.');