# vita_hello
C++ Hello World program for PS-Vita using debugscreen vitasdk taken from vitasdk/samples and modified to be compilable. 

To install:
Install .vpk from bin/release via vitashell


// it is supposed you have already installed vitasdk
To build:

- in Code::Blocks

1. Setup the compiler as follows:

![image](https://user-images.githubusercontent.com/74510763/131345465-43eec63b-660d-4c26-ae5d-f80ab43c95f1.png)

2. Open .cbp project

3. Press Ctrl+F9

- Manually

From the command line execute:
arm-vita-eabi-g++ -std=c++11 -I/usr/local/vitasdk/share/gcc-arm-vita-eabi/samples/common -c /src/main_mod.cpp -o obj/Release/src/main_mod.o

arm-vita-eabi-g++ -L/usr/local/vitasdk/share/gcc-arm-vita-eabi/samples/common -o bin/Release/Hello_World_Vita obj/Release/src/main_mod.o  -Wl,-q  obj/debugScreen.o -lstdc++ -lpthread -lSceDisplay_stub

arm-vita-eabi-strip -g bin/Release/Hello_World_Vita

vita-elf-create bin/Release/Hello_World_Vita bin/Release/Hello_World_Vita.velf

vita-make-fself bin/Release/Hello_World_Vita.velf bin/Release/eboot.bin

vita-mksfoex -s TITLE_ID="VSDK00006" "Hello_World_Vita" bin/Release/param.sfo

vita-pack-vpk -s bin/Release/param.sfo -b bin/Release/eboot.bin --add sce_sys/icon0.png=sce_sys/icon0.png --add sce_sys/livearea/contents/bg.png=sce_sys/livearea/contents/bg.png --add sce_sys/livearea/contents/startup.png=sce_sys/livearea/contents/startup.png --add sce_sys/livearea/contents/template.xml=sce_sys/livearea/contents/template.xml bin/Release/Hello_World_Vita.vpk

