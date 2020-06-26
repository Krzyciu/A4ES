class Cfg3DEN {
	class Attributes {
        class Default;
        class Title: Default {
			class Controls {
				class Title: ctrlStatic {};
                class EGVAR(modules,description): ctrlStructuredText {};
			};
		};
        class Slider: Title {
			class Controls: Controls {
				class Title: Title {};
				class Value: ctrlXSliderH {};
				class Edit: ctrlEdit {};
                class EGVAR(modules,description): EGVAR(modules,description) {};
			};
		};
        class Skill: Slider {
            onLoad = QUOTE(_this call FUNC(skill_onLoad););
            h = "10 * (pixelH * pixelGrid * 0.50)";

            class Controls: Controls {
                class Title: Title {};
                class Value: Value {
                    sliderRange[] = {0, 1};
                };
                class Edit: Edit {};
                class EGVAR(modules,description): EGVAR(modules,description) {
                    idc = 105;
                    y = "5 * (pixelH * pixelGrid * 	0.50)";
                    h = "5 * (pixelH * pixelGrid * 	0.50)";
                };
            };
        };
    };
    class Object {
        class AttributeCategories {
            class State {
                class Attributes {
                    class Skill {
						displayName = CSTRING(skill_displayName);
						tooltip = CSTRING(skill_tooltip);
					};
                };
            };
        };
    };
};