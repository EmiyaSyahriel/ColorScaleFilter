cmake_minimum_required (VERSION 3.8)

file(GLOB_RECURSE ColorScaleFilter_CPP *.cpp)
file(GLOB_RECURSE ColorScaleFilter_H *.h)

# AviSynth FilterSDK 2.6.0
include_directories("C:\\Program Files (x86)\\AviSynth\\FilterSDK\\include")

add_library (ColorScaleFilter SHARED ${ColorScaleFilter_CPP} ${ColorScaleFilter_H})
