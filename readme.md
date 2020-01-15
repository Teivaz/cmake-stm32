# Basic CMake project for STM32

This is a basic development setup for the microcontroller STM32L011F4 with CMake.

This project was targeted for macOS X platform though other platforms should not be hard to add.

# Setup

## CMake
Minimal version is 3.12. If you have any problems with it - upgrade your CMake already it's 2020.

## Toolchain - `arm-none-eabi-gcc`
The toolchain provided by [ArmMbed](https://www.mbed.com/en/).
I'll be using this formulae for homebrew https://github.com/ARMmbed/homebrew-formulae 
```
brew tap ArmMbed/homebrew-formulae
brew install arm-none-eabi-gcc
```

## Hardware debugger - `STLINK-V3`
The debugging probe and programmer - [STLINK-V3](https://www.st.com/en/development-tools/stlink-v3set.html)

## Debugging - `openocd`
For interacting with tool I will be using [OpenOCD](http://openocd.org/) instead of their IDE and tools that repel me.

## IDE - `Visual Studio Code`
Instead of IDE I will be using VSCode because it is a simple, versatile, and reliable tool.

## VSCode extensions
I will be using a couple of extensions for the IDE:
- [CMake Tools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools) for building
- [Cortex-Debug](https://marketplace.visualstudio.com/items?itemName=marus25.cortex-debug) for debugging
- [C/C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools) for C language support

# Credits
Huge thanks to [geokon](https://github.com/geokon-gh) for his article on the topic [Bluepill: a GCC/CMake build environment ..
](https://geokon-gh.github.io/bluepill) that really helped me get this going.
