#ifndef POOL_H
#define POOL_H
#include <fstream>

using namespace std;
bool readPool(char* filename, float pool[20][10]);

void printPool(ofstream& fileOut, float pool[20][10]);

void findFaulty(float pool[20][10]);

#endif
