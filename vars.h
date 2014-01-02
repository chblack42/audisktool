/* 
 *Chuck Black
 */
#ifndef _Namespace_H_
#define _Namespace_H_
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

namespace constants{
int const HELP = 0;
int const RUN = 1;
int const MONITORINTERVAL = 2;
int const NUMOFRECORDS = 3;
int const BLK_READ = 4;
int const BLK_READ_S = 5;
int const KB_READ_S = 6;
int const BLK_WRITE = 7;
int const BLK_WRITE_S = 8;
int const KB_WRITES_S = 9;
int const PRINTCONF = 10;
int const PRINGREPORT = 11;
int const RESETCONF = 12;
int const FILENAMECHNG = 13;
int const EXIT = 14;
std::string const DEFAULT = "1";
}
#endif
