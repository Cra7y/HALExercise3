/*
 * formatter.h
 *
 *  Created on: 12/09/2016
 *      Author: phm
 */

#ifndef FORMATTER_H_
#define FORMATTER_H_

// Forward declaration of struct
typedef struct formatter formatter;

struct formatter {
	FILE *fp;
	void (*header)(formatter*, char*);
	void (*body)(formatter*, char*);
	void (*preamble)(formatter*, char*);
	void (*postamble)(formatter*, char*);
	void (*release)(formatter*);
};

void formatter_init(formatter *cthis, void (sub_init)(formatter *cthis, char *pathname), char *pathname);
void formatter_release(formatter *cthis);

#endif /* FORMATTER_H_ */
