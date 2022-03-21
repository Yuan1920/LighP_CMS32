#ifndef __CXN4016_H
#define __CXN4016_H
#include "public.h"


#define CXN4016_DATA_IO  GPIO2->DO_f.P6
#define CXN4016_BUSY_IO  GPIO2->DI_f.P5

void CXN4016_INIT(void);
void Line_1A_CXN4( unsigned char SB_DATA);


#endif



