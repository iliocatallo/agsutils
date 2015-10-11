#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include "ByteArray.h"
#include "List.h"
#include <stdio.h>
#include <stddef.h>

typedef struct AgsAssembler {
	struct ByteArray obj_b, *obj;
	struct ByteArray data_b, *data;
	struct ByteArray code_b, *code;
	List *export_list, export_list_b;
	List *fixup_list, fixup_list_b;
	List *string_list, string_list_b;
	List *label_list, label_list_b;
	List *label_ref_list, label_ref_list_b;
	List *function_ref_list, function_ref_list_b;
	List *variable_list, variable_list_b;
	List *import_list, import_list_b;
	FILE* in;
} AS;

int AS_open(AS* a, char* fn);
void AS_close(AS* a);
int AS_assemble(AS* a, char* out);

//RcB: DEP "Assembler.c"
#endif
