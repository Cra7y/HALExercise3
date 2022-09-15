#include <stdio.h>
#include <stdlib.h>
#include "formatter.h"

/*
 * HTML SUB CLASS
 */

void html_preamble(formatter *cthis, char* string){
	char html_start[]= {"<!DOCTYPE html>"};
	char html_header_start[]={"<HEAD>\n<TITLE>\n"};
	char html_header_end[]={"</TITLE>\n</HEAD>\n"};
	char html_body_start[]={"<BODY>\n"};

	fprintf(cthis->fp, "%s", html_start);
	fprintf(cthis->fp, "%s", html_header_start);
	fprintf(cthis->fp, "%s\n", string);
	fprintf(cthis->fp, "%s", html_header_end);
	fprintf(cthis->fp, "%s", html_body_start);
}

void html_postamble(formatter *cthis, char* string){
	char html_body_end[]={"</BODY>\n"};
	char html_end[]={"</HTML>\n"};
	fprintf(cthis->fp, "%s", html_body_end);
	fprintf(cthis->fp, "%s", html_end);
}


void html_header(formatter *cthis, char* string){
	fprintf(cthis->fp, "<H1>%s</H1>\n", string);
}

void html_body(formatter *cthis, char* string){
	fprintf(cthis->fp, "<p>%s</p>\n", string);
}

void html_release(formatter *cthis) {
  fclose(cthis->fp);
}

const struct formatter html_formatter = 
{
    .header    = html_header,
    .preamble  = html_preamble,
	.body	   = html_body,
    .postamble = html_postamble,
    .release   = html_release,
};


void html_init(formatter *cthis, char *pathname){

  *cthis = html_formatter;

  /* Open file */
  cthis->fp=fopen(pathname, "w");
  if(cthis->fp <= 0) {
    printf("Invalid file pointer!\n");
    exit(0);
  }

}
