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
_logic set3DENAttribute [QGVAR(data), _anim];

private _loopAnimation = _logic getVariable [QGVAR(loopAnimation), false];
private _animDoneEH = -1;

{ 
  private _unit = _x#1;
  _unit enableSimulation true;
  _unit switchMove _anim;

  _unit setVariable [QGVAR(loopCondition), _loopCondition];

  _animDoneEH = _unit addEventHandler ["AnimDone", {
    params ["_unit", "_anim"];
    _unit switchMove _anim;
  }];

  _unit setVariable [QGVAR(animDoneEH), _animDoneEH];
} forEach _units;