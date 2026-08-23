#include "ui.h"

#include <cstdio>

namespace harness::ui {
namespace {
constexpr int kPageCount = 3;
int current_page = 0;
lv_obj_t* page_label = nullptr;
lv_obj_t* title_label = nullptr;
lv_obj_t* primary_label = nullptr;
lv_obj_t* detail_label = nullptr;
lv_obj_t* hint_label = nullptr;
StatusModel latest;

void Render() {
  char line[128];
  std::snprintf(line, sizeof(line), "%d/%d", current_page + 1, kPageCount);
  lv_label_set_text(page_label, line);
  lv_label_set_text(title_label, latest.title);

  if (current_page == 0) {
    lv_label_set_text(primary_label, latest.link);
    std::snprintf(line, sizeof(line),
                  "SOURCE  %s\nSUPPLY  %.2f V\nUPTIME  %lu s",
                  latest.source, static_cast<double>(latest.supply_volts),
                  static_cast<unsigned long>(latest.uptime_seconds));
  } else if (current_page == 1) {
    lv_label_set_text(primary_label, "INPUT TEST");
    std::snprintf(line, sizeof(line),
                  "BOOT short press: next page\nBOOT hold: select\nPackets: %lu",
                  static_cast<unsigned long>(latest.packets));
  } else {
    lv_label_set_text(primary_label, "TELEMETRY SLOT");
    std::snprintf(line, sizeof(line),
                  "StatusModel is the UI boundary.\nReplace the demo producer;\nkeep this page code unchanged.");
  }
  lv_label_set_text(detail_label, line);
}
}  // namespace

void Init() {
  lv_obj_t* screen = lv_screen_active();
  lv_obj_set_style_bg_color(screen, lv_color_hex(0x071018), 0);
  lv_obj_set_style_text_color(screen, lv_color_hex(0xD9F6FF), 0);

  title_label = lv_label_create(screen);
  lv_obj_set_style_text_font(title_label, &lv_font_montserrat_20, 0);
  lv_obj_align(title_label, LV_ALIGN_TOP_LEFT, 24, 24);

  page_label = lv_label_create(screen);
  lv_obj_align(page_label, LV_ALIGN_TOP_RIGHT, -24, 28);

  primary_label = lv_label_create(screen);
  lv_obj_set_style_text_font(primary_label, &lv_font_montserrat_28, 0);
  lv_obj_set_style_text_color(primary_label, lv_color_hex(0x58E6FF), 0);
  lv_obj_align(primary_label, LV_ALIGN_CENTER, 0, -100);

  detail_label = lv_label_create(screen);
  lv_obj_set_style_text_align(detail_label, LV_TEXT_ALIGN_CENTER, 0);
  lv_obj_align(detail_label, LV_ALIGN_CENTER, 0, 20);

  hint_label = lv_label_create(screen);
  lv_label_set_text(hint_label, "PRESS: NEXT     HOLD: SELECT");
  lv_obj_set_style_text_color(hint_label, lv_color_hex(0x78919B), 0);
  lv_obj_align(hint_label, LV_ALIGN_BOTTOM_MID, 0, -24);
  Render();
}

void Handle(Action action) {
  if (action == Action::kNext) current_page = (current_page + 1) % kPageCount;
  if (action == Action::kSelect) latest.packets++;
  Render();
}

void Update(const StatusModel& model) {
  latest = model;
  Render();
}

}  // namespace harness::ui

