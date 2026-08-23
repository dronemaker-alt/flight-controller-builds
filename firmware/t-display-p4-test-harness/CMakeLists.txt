cmake_minimum_required(VERSION 3.16)

set(VENDOR_ROOT "${CMAKE_CURRENT_LIST_DIR}/.pio/vendor/T-Display-P4")
set(EXTRA_COMPONENT_DIRS
    "${VENDOR_ROOT}/libraries/cpp_bus_driver"
    "${VENDOR_ROOT}/libraries/lilygo_device_driver"
    "${VENDOR_ROOT}/libraries/usp_cpp_bus_driver"
    "${VENDOR_ROOT}/libraries/ST25R3916"
    "${VENDOR_ROOT}/libraries/NFC-RFAL")

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(t_display_p4_test_harness)

