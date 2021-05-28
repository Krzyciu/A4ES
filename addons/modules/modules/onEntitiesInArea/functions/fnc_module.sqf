#include "script_component.hpp"
/*
 * Author: SzwedzikPL
 * onEntitiesInArea module function
 */

params ["_mode", "_input"];
TRACE_2(QUOTE(EXEC_MODULE_NAME),_mode,_input);

// Exit if module executed inside editor, not on server or not in init mode
if (is3DEN || !(isServer) || (_mode isNotEqualTo "init")) exitWith {};
_input params [
  ["_logic", objNull, [objNull]],
  ["_isActivated", false, [true]],
  ["_isCuratorPlaced", false, [true]]
];
// Exit if module is null, not local or placed by zeus (should not happen)
if (isNull _logic || !(local _logic) || _isCuratorPlaced) exitWith {};

LOG('Starting execution of EXEC_MODULE_NAME.');

// Get synced objects
private _objects = (synchronizedObjects _logic) select {
  !(_x isKindOf "EmptyDetector") && {!(_x isKindOf "Logic")}
};

// No valid objects
if (_objects isEqualTo []) exitWith {
  ERROR("Execution of EXEC_MODULE_NAME aborted, no valid objects");
};

_logic setVariable [QGVAR(handlerObjects), _objects];

[
  _logic,
  compile (_logic call FUNC(onEntitiesInArea_getCondition)),
  [_logic, _objects],
  QFUNC(onEntitiesInArea_moduleExec),
  0
] call FUNC(addModuleToActivator);

LOG('Execution of EXEC_MODULE_NAME finished - added to activator.');
