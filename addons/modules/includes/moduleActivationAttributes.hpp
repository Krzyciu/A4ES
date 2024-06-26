
class GVAR(activationSettingsSubCategory): GVAR(moduleSubCategory) {
    displayName = CSTRING(Attributes_activationSettingsSubCategory);
    property = QGVAR(activationSettingsSubCategory);
};

class GVAR(addPreActivation): GVAR(dynamicCheckbox) {
    displayName = CSTRING(Attributes_addPreActivation);
    tooltip = CSTRING(Attributes_addPreActivation_tooltip);
    property = QGVAR(addPreActivation);
    ATTRIBUTE_LOCAL;
};

class GVAR(preActivationFlags): GVAR(dynamicLogicFlagCondPreActivator) {
    displayName = CSTRING(Attributes_preActivationFlags);
    tooltip = CSTRING(Attributes_preActivationFlags_Tooltip);
    property = QGVAR(preActivationFlags);
    defaultValue = QUOTE('[]');
    GVAR(conditionActive) = QUOTE((_this getVariable QQGVAR(addPreActivation)) isEqualTo true);
    ATTRIBUTE_LOCAL;
};

class GVAR(activationMode): Default {
    displayName = CSTRING(Attributes_activationMode);
    tooltip = CSTRING(Attributes_activationMode_Tooltip);
    property = QGVAR(activationMode);
    typeName = "NUMBER";
    GVAR(observeValue) = 1;
    ATTRIBUTE_LOCAL;

    #ifdef MODULE_ACTIVATOR_CONTROL
        control = MODULE_ACTIVATOR_CONTROL;
        #undef MODULE_ACTIVATOR_CONTROL
    #else
        control = QGVAR(dynamicToolboxActivationMode);
    #endif

    #ifdef MODULE_ACTIVATOR_DEFAULT_VALUE
        defaultValue = MODULE_ACTIVATOR_DEFAULT_VALUE;
        #undef MODULE_ACTIVATOR_DEFAULT_VALUE
    #else
        defaultValue = "0";
    #endif
};
class GVAR(activationNearestPlayerDistance): GVAR(dynamicSlider) {
    displayName = CSTRING(Attributes_activationNearestPlayerDistance);
    tooltip = CSTRING(Attributes_activationNearestPlayerDistance_Tooltip);
    property = QGVAR(activationNearestPlayerDistance);
    defaultValue = "800";
    typeName = "NUMBER";
    GVAR(range[]) = {1, 3000};
    GVAR(valueUnit) = "m";
    GVAR(conditionActive) = QUOTE((_this getVariable QQGVAR(activationMode)) isEqualTo 0);
    ATTRIBUTE_LOCAL;
};
class GVAR(activationIgnoreHelicopters): GVAR(dynamicCheckbox) {
    displayName = CSTRING(Attributes_activationIgnoreHelicopters);
    tooltip = CSTRING(Attributes_activationIgnoreHelicopters_tooltip);
    property = QGVAR(activationIgnoreHelicopters);
    defaultValue = "true";
    GVAR(observeValue) = 0;
    GVAR(conditionActive) = QUOTE((_this getVariable QQGVAR(activationMode)) isEqualTo 0);
    ATTRIBUTE_LOCAL;
};
class GVAR(activationIgnorePlanes): GVAR(dynamicCheckbox) {
    displayName = CSTRING(Attributes_activationIgnorePlanes);
    tooltip = CSTRING(Attributes_activationIgnorePlanes_tooltip);
    property = QGVAR(activationIgnorePlanes);
    defaultValue = "true";
    GVAR(observeValue) = 0;
    GVAR(conditionActive) = QUOTE((_this getVariable QQGVAR(activationMode)) isEqualTo 0);
    ATTRIBUTE_LOCAL;
};
class GVAR(activationFlags): GVAR(dynamicLogicFlagCondActivator) {
    displayName = CSTRING(Attributes_activationFlags);
    tooltip = CSTRING(Attributes_activationFlags_Tooltip);
    property = QGVAR(activationFlags);
    defaultValue = QUOTE('[]');
    GVAR(conditionActive) = QUOTE((_this getVariable QQGVAR(activationMode)) isEqualTo 1);
    ATTRIBUTE_LOCAL;
};
class GVAR(activationCondition): GVAR(dynamicEditCodeMulti5) {
    displayName = CSTRING(Attributes_activationCondition);
    tooltip = CSTRING(Attributes_activationCondition_Tooltip);
    property = QGVAR(activationCondition);
    defaultValue = "'true'";
    typeName = "STRING";
    validate = "condition";
    GVAR(conditionActive) = QUOTE((_this getVariable QQGVAR(activationMode)) isEqualTo 2);
    ATTRIBUTE_LOCAL;
};
class GVAR(activationDelay): GVAR(dynamicCheckbox) {
    displayName = CSTRING(Attributes_activationDelay);
    tooltip = CSTRING(Attributes_activationDelay_tooltip);
    property = QGVAR(activationDelay);
    GVAR(conditionActive) = QUOTE((_this getVariable QQGVAR(activationMode)) isNotEqualTo -1);
    ATTRIBUTE_LOCAL;
};
class GVAR(activationDelayTime): GVAR(dynamicEdit) {
    displayName = CSTRING(Attributes_activationDelayTime);
    tooltip = CSTRING(Attributes_activationDelayTime_Tooltip);
    property = QGVAR(activationDelayTime);
    defaultValue = "'0'";
    typeName = "NUMBER";
    validate = "number";
    GVAR(conditionActive) = QUOTE(((_this getVariable QQGVAR(activationDelay)) isEqualTo true) &&((_this getVariable QQGVAR(activationMode)) isNotEqualTo -1));
    ATTRIBUTE_LOCAL;
};
