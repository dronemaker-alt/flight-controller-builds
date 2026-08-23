#pragma once

#include <cstdint>
#include "lvgl.h"

namespace harness::ui {

enum class Action { kNext, kSelect };

struct StatusModel {
  const char* title = "P4 TEST HARNESS";
  const char* link = "STANDBY";
  const char* source = "BENCH";
  float supply_volts = 0.0F;
  uint32_t uptime_seconds = 0;
  uint32_t packets = 0;
};

void Init();
void Handle(Action action);
void Update(const StatusModel& model);

}  // namespace harness::ui

