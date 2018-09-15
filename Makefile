binary = motors
optimize = s
flags = $(CFLAGS) -mmcu=$(mcu) -D$(partno-define) -DF_CPU=$(f-cpu) -O$(optimize)
partno-define = __AVR_ATmega328P__
f-cpu = 16000000UL
mcu = atmega328p
partno = m328p
programmer-id = arduino
port = /dev/ttyUSB0
objects = $(patsubst src/%.c, .building/%.o, $(wildcard src/*.c))
deps = $(patsubst src/%.c, .building/%.d, $(wildcard src/*.c))

CC = avr-gcc

$(binary): $(objects)
	$(CC) $(flags) -o $(binary) $(objects)

.building/%.o: src/%.c
	$(CC) $(flags) -MMD -c $< -o $@

-include $(deps)

.PHONY: upload
upload: $(binary)
	sudo avrdude -c$(programmer-id) -p$(partno) -P$(port) \
		-Uflash:w:$(binary):e

.PHONY: view_asm
view_asm: $(binary)
	@avr-objdump -d $(binary) | less

.PHONY: clean
clean:
	$(RM) $(binary) $(objects) $(deps)
