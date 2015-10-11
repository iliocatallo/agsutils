#ifndef DATAFILE_H
#define DATAFILE_H

#include "File.h"
#include "Script.h"

typedef struct AgsGameData {
	size_t fontcount;
	size_t cursorcount;
	size_t charactercount;
	size_t inventorycount;
	size_t viewcount;
	size_t dialogcount;
	int hasdict;
} AGD;

typedef struct AgsDataFile {
	AF f_b;
	AF *f;
	char* dir;
	int version;
	size_t globalvarcount;
	AGD game;
	size_t scriptcount;
	size_t scriptstart;
	size_t scriptend;
	ASI globalscript;
	ASI dialogscript;
	ASI scripts[50];
} ADF;

void ADF_init(ADF* a, char* dir);
int ADF_open(ADF* a);
void ADF_close(ADF* a);

ASI* ADF_open_objectfile(ADF* a, char* fn);
ASI* ADF_get_script(ADF* a, size_t index);
ASI* ADF_get_global_script(ADF* a);
ASI* ADF_get_dialog_script(ADF* a);
size_t ADF_get_scriptcount(ADF* a);


//RcB: DEP "DataFile.c"
#endif
