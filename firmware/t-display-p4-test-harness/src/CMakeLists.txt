idf_component_register(
    SRCS "main.cpp" "board_port.cpp" "ui.cpp"
    INCLUDE_DIRS "."
    REQUIRES driver esp_timer esp_lcd lvgl lilygo_device_driver)

