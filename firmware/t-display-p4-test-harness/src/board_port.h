#pragma once

#include <functional>
#include "ui.h"

namespace harness::board {

using ActionHandler = std::function<void(ui::Action)>;

bool InitDisplay();
void StartUiTask();
void StartButtonTask(ActionHandler handler);
void LockUi();
void UnlockUi();

}  // namespace harness::board

