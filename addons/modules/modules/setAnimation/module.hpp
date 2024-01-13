class GVAR(setAnimation): GVAR(base) {
    scope = 2;
    author = "Krzyciu";
    displayName = CSTRING(setAnimation_displayName);
    icon = QUOTE(\a3\ui_f\data\igui\cfg\simpletasks\types\Use_ca.paa);
    category = QGVAR(ambient);
    function = QFUNC(setAnimation_module);
    isTriggerActivated = 0;
    GVAR(validator) = QFUNC(setAnimation_validate);

    class Attributes: AttributesBase {
        class GVAR(moduleShortDescription): GVAR(moduleShortDescription) {};
        class GVAR(moduleWarnings): GVAR(moduleWarnings) {};

        // Attributes for module activator
        #include "\z\a4es\addons\modules\includes\moduleActivationAttributes.hpp"

        class GVAR(mode): Default {
            displayName = CSTRING(setAnimation_Attributes_mode);
            tooltip = CSTRING(setAnimation_Attributes_mode_Tooltip);
            control = QGVAR(setAnimation_mode);
            property = QGVAR(mode);
            typeName = "NUMBER";
            defaultValue = "0";
            GVAR(observeValue) = 1;
            ATTRIBUTE_LOCAL;
        };

        class GVAR(predefinedAnim): GVAR(dynamicCombo) {
            displayName = CSTRING(setAnimation_Attributes_predefinedAnim);
            tooltip = CSTRING(setAnimation_Attributes_predefinedAnim_Tooltip);
            property = QGVAR(predefinedAnim);
            typeName = "STRING";
            defaultValue = "amovpsitmstpslowwrfldnon";
            GVAR(observeValue) = 1;
            GVAR(conditionActive) = QUOTE((_this getVariable QQGVAR(mode)) isEqualTo 0);
            ATTRIBUTE_LOCAL;
            class values {
                class sit {
                    name = CSTRING(setAnimation_anims_sit);
                    value = "amovpsitmstpslowwrfldnon";
                    default = 1;
                };
                class sitArmed {
                    name = CSTRING(setAnimation_anims_sitArmed);
                    value = "passenger_flatground_3_Idle_Idling";
                };
                class lean {
                    name = CSTRING(setAnimation_anims_lean);
                    value = "Acts_leaning_against_wall";
                };
                class watch {
                    name = CSTRING(setAnimation_anims_watch);
                    value = "inbasemoves_patrolling1";
                };
                class stand {
                    name = CSTRING(setAnimation_anims_stand);
                    value = "HubStanding_idle1";
                };
                class briefing {
                    name = CSTRING(setAnimation_anims_brief);
                    value = "hubbriefing_loop";
                };
                class listen {
                    name = CSTRING(setAnimation_anims_listen);
                    value = "Acts_CivilListening_1";
                };
                class talk {
                    name = CSTRING(setAnimation_anims_talk);
                    value = "Acts_CivilTalking_1";
                };
                class navigate {
                    name = CSTRING(setAnimation_anims_navigate);
                    value = "Acts_ShowingTheRightWay_loop";
                };
                class wounded {
                    name = CSTRING(setAnimation_anims_wounded);
                    value = "acts_injuredangryrifle01";
                };
                class repair {
                    name = CSTRING(setAnimation_anims_repair);
                    value = "inbasemoves_repairvehicleknl";
                };
            };
        };

        class GVAR(customAnim): GVAR(dynamicEdit) {
            displayName = CSTRING(setAnimation_Attributes_customAnim);
            tooltip = CSTRING(setAnimation_Attributes_customAnim_Tooltip);
            property = QGVAR(customAnim);
            defaultValue = "''";
            validate = "STRING";
            GVAR(conditionActive) = QUOTE((_this getVariable QQGVAR(mode)) isEqualTo 1);
            ATTRIBUTE_LOCAL;
        };

        class GVAR(data): GVAR(dynamicHiddenEdit) {
            displayName = "data";
            tooltip = "data";
            property = QGVAR(data);
            defaultValue = "'[]'";
            ATTRIBUTE_LOCAL;
        };

        class GVAR(loopAnimation): GVAR(dynamicCheckbox) {
            displayName = CSTRING(setAnimation_Attributes_loopAnimation);
            property = QGVAR(loopAnimation);
        };

        class GVAR(loopCondition): GVAR(dynamicEditCodeMulti5) {
            displayName = CSTRING(setAnimation_Attributes_loopCondition);
            tooltip = CSTRING(setAnimation_Attributes_loopCondition_Tooltip);
            property = QGVAR(loopCondition);
            defaultValue = "'true'";
            typeName = "STRING";
            validate = "condition";
            GVAR(conditionActive) = QUOTE((_this getVariable QQGVAR(loopAnimation)) isEqualTo true);
            ATTRIBUTE_LOCAL;
        };

        class GVAR(moduleDescription): GVAR(moduleDescription) {};
    };

    class GVAR(moduleDescription): GVAR(moduleDescription) {
        shortDescription = CSTRING(setAnimation_shortDescription);
        description = "";
    };
};