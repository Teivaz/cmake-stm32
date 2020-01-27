# Cross compiling. "Generic" is used for embedded platforms
set(CMAKE_SYSTEM_NAME "Generic")

# Compilers
set(CMAKE_C_COMPILER "arm-none-eabi-gcc")

# tells CMake not to try to link executables during its interal checks
# things are not going to link properly without a linker script
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

set(CMAKE_OBJCOPY "arm-none-eabi-objcopy")
