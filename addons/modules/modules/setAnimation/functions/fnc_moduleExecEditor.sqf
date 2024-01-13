#include "script_component.hpp"
/*
 * Author: Krzyciu
 * setAnimation moduleExecEditor function
 */
params ["_logic"];

private _unit = (synchronizedObjects _logic) select {_x isKindOf "CAManBase"};
private _animType = _logic getVariable [QGVAR(mode), 0];
private _anim = [_logic getVariable [QGVAR(predefinedAnim), ""], _logic getVariable [QGVAR(customAnim), ""]] select _animType;
_unit#0 switchMove _anim;