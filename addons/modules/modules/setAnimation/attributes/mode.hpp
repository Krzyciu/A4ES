class GVAR(setAnimation_mode): GVAR(dynamicToolbox) {
    class Controls: Controls {
        class Title: Title {};
        class Value: Value {
            columns = 2;
            strings[] = {
                CSTRING(setAnimation_Attributes_mode_predefined),
                CSTRING(setAnimation_Attributes_mode_custom)
            };
            tooltips[] = {"", ""};
            GVAR(descriptions[]) = {
                CSTRING(setAnimation_Attributes_mode_predefined_desc),
                CSTRING(setAnimation_Attributes_mode_custom_desc)
            };
            values[] = {0, 1};
        };
        class GVAR(description): GVAR(description) {};
    };
};