#include "script_component.hpp"
/*
 * Author: Krzyciu
 * setAnimation moduleExecEditor function
 */
params ["_logic"];

private _units = (get3DENConnections _logic) select {
  ((_x #0) isEqualTo "Sync") && {(_x #1) isKindOf "CAManBase"}
};

private _animType = _logic getVariable [QGVAR(mode), 0];
private _anim = [_logic getVariable [QGVAR(predefinedAnim), ""], _logic getVariable [QGVAR(customAnim), ""]] select _animType;

if (_anim isEqualTo "") then {
  _anim = (_logic get3DENAttribute QGVAR(data))#0;
};

_logic set3DENAttribute [QGVAR(data), _anim];

{_x#1 switchMove _anim} forEach _units;