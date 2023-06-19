.PHONY: all
all: fast std cdecl

.PHONY: fast
fast: fastcall.out
	objdump fastcall.out -d > out
	csplit out '/^.* <sum_prod>:/'
	csplit xx01 '/Disassembly of section .fini:/'
	rm xx01 out
	mv xx00 fastdiss

.PHONY: std
std: stdcall.out
	objdump stdcall.out -d > out
	csplit out '/^.* <sum_prod>:/'
	csplit xx01 '/Disassembly of section .fini:/'
	rm xx01 out
	mv xx00 stddiss

.PHONY: cdecl
cdecl: cdecl.out
	objdump cdecl.out -d > out
	csplit out '/^.* <sum_prod>:/'
	csplit xx01 '/Disassembly of section .fini:/'
	rm xx01 out
	mv xx00 cdecldiss

.PHONY: clean
clean:
	@rm a.out diss 2>/dev/null || true

