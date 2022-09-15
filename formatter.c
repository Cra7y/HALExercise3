/*
 * formatter.c
 *
 *  Created on: 12/09/2016
 *      Author: phm
 */
#include <stdio.h>
#include <stdlib.h>
#include "formatter.h"

/*
 * CLASS CONSTRUCTOR AND DESCTRUCTOR
 */
void formatter_init(formatter *cthis, void (sub_init)(formatter *cthis, char *pathname), char *pathname){

  /* Sub-Class Init */
  sub_init(cthis, pathname);

}

void formatter_release(formatter *cthis){
  /* Sub-Class Release */
  cthis->release(cthis);
}
