.PHONY: clean


SOURCE=main.c
TARGET=boot64.efi

CFLAGS= -ffreestanding \
	-fno-strict-aliasing \
	-fno-stack-protector \
	-fno-stack-check \
	-fno-addrsig \
	-fno-common \
	-fshort-wchar \
	-fno-asynchronous-unwind-tables \
	-fno-plt \
	-fdirect-access-external-data \
	-nostdlib \
	-Wall \
	-Wextra \
	-Werror


$(TARGET): $(SOURCE)
	clang $(SOURCE) $(CFLAGS) -std=c17 --target=x86_64-windows -c -o boot64.o
	lld-link -subsystem:efi_application -entry:efi_main boot64.o -out:boot64.efi
	rm boot64.o


clean:
	rm -f $(TARGET)
