#pragma once
#include "components.hpp"

class InputComponent : public Component {
	public:
		InputComponent();
		void execute(Entity*);
		virtual void handleA() = 0;
};
