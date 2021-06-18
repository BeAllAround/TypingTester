#include <stdio.h> 
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>
#include <math.h>
#include <fcntl.h>
#include <string.h>

#define WINVER 0x0500
void pressAndRelease(INPUT, int, int);
void setUpKeyboard(INPUT*);


typedef struct{
	char hF;
	int iF;
}Key;

typedef struct{
	char first;
	char second;
}Map;

typedef struct{
	Key*data;
	int length;
}Array;

typedef struct{
	Map*data;
	int length;
}map;

Key newKey(char hF, int iF){
    Key __;
    __.hF = hF;
    __.iF = iF;
    return __;
}

Map newMap(char first, char second){
    Map __;
    __.first = first;
    __.second = second;
    return __;
}

Array newArray(void){
    Array __;
    __.data = (Key*)malloc(1000);
    __.length = 0;
    return __;
}

map new_map(void){
    map __;
    __.data = (Map*)malloc(1000);
    __.length = 0;
    return __;
}