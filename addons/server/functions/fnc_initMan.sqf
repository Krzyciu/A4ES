/*
 * Author: SzwedzikPL
 *
 * Init man obj on server
 */
#include "script_component.hpp"

params ["_unit"];

//Disable score
_unit addEventHandler ["HandleScore", {false}];
