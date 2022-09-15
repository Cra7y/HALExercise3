#include <stdio.h>
#include <stdlib.h>
#include "formatter.h"

/*
 * TEXT SUB CLASS
 */

void txt_preamble(formatter *cthis, char* string){
	fprintf(cthis->fp, "#### Start File: %s ####\n", string);
}

void txt_postamble(formatter *cthis, char* string){
	fprintf(cthis->fp, "#### End File: %s ####\n", string);
}

void txt_header(formatter *cthis, char* string){
	fprintf(cthis->fp, "===================================================================\n");
	fprintf(cthis->fp, "%s\n", string);
	fprintf(cthis->fp, "===================================================================\n");
	fprintf(cthis->fp, "\n");
}

void txt_release(formatter *cthis) {
  fclose(cthis->fp);
}

struct formatter txt_formatter = 
{
    .header    = txt_header,
    .preamble  = txt_preamble,
    .postamble = txt_postamble,
    .release   = txt_release,
};

void txt_init(formatter *cthis, char *pathname){

  *cthis = txt_formatter;

  /* Open file */
  cthis->fp=fopen(pathname, "w");
  if(cthis->fp <= 0) {
    printf("Invalid file pointer!\n");
    exit(0);
  }

}
