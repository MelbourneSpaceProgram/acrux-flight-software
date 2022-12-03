## Instructions to run

### Setup code
1. clone repo
2. open in vscode
3. build/start dev container

### Compiling
1. `cd Ref`
2. `fprime-util purge FreeRTOS-stm`
3. `fprime-util generate FreeRTOS-stm`
4. `fprime-util build FreeRTOS-stm`

### Flashing build
2. copy build output from `Ref/build-artifcats/bin/Ref.bin`
3. install stlink-tools
4. connect board to usb
5. `st-info --probe` to validate connection
6. `st-flash write Ref.bin 0x8000000`
