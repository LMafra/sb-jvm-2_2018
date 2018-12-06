#pragma once
#include <cstdint>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <string>
#include "UsingUs.h"
#include "ClassFileStructures/ClassFile.hpp"
#include  "VMGlobals.hpp"

bool condjavaclass(char* classname);
bool condnotprintln(char* methodname);
int ammountofparams(char* descriptor);
bool namescomp(CONSTANT_Utf8_info & nametry, char* metname);
method_info * findmethodinclass(Instance * inst,char* metname);

void instance_frame_loader_interpreter(int indexname, 
			int indextype, int indexclass,
			Instance * inst, cat1 * args);

void instance_frame_loader(
		int index, Instance * inst, cat1 * args);
#include "frameloader.cpp"