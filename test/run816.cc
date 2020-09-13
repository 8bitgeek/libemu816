//==============================================================================
//                                          .ooooo.     .o      .ooo   
//                                         d88'   `8. o888    .88'     
//  .ooooo.  ooo. .oo.  .oo.   oooo  oooo  Y88..  .8'  888   d88'      
// d88' `88b `888P"Y88bP"Y88b  `888  `888   `88888b.   888  d888P"Ybo. 
// 888ooo888  888   888   888   888   888  .8'  ``88b  888  Y88[   ]88 
// 888    .o  888   888   888   888   888  `8.   .88P  888  `Y88   88P 
// `Y8bod8P' o888o o888o o888o  `V88V"V8P'  `boood8'  o888o  `88bod8'  
//                                                                    
// A Portable C++ WDC 65C816 vm  
//------------------------------------------------------------------------------
// Copyright (C),2016 Andrew John Jacobs
// All rights reserved.
//
// This work is made available under the terms of the Creative Commons
// Attribution-NonCommercial-ShareAlike 4.0 International license. Open the
// following URL to see the details.
//
// http://creativecommons.org/licenses/by-nc-sa/4.0/
//------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include <string.h>
#include <time.h>
#include <vm816.h>

//==============================================================================
// Memory Definitions
//------------------------------------------------------------------------------

// On Windows/Linux create a 512Kb RAM area - No ROM.
#define	RAM_SIZE	(512 * 1024)
#define MEM_MASK	(512 * 1024L - 1)

bool trace = false;

vm816 vm;


//==============================================================================

// Initialise the vm
inline void setup()
{
	vm.setMemory(MEM_MASK, RAM_SIZE, NULL);
}

//==============================================================================
// S19/28 Record Loader
//------------------------------------------------------------------------------

uint32_t toNybble(char ch)
{
	if ((ch >= '0') && (ch <= '9')) return (ch - '0');
	if ((ch >= 'A') && (ch <= 'F')) return (ch - 'A' + 10);
	if ((ch >= 'a') && (ch <= 'f')) return (ch - 'a' + 10);
	return (0);
}

uint32_t toByte(string &str, int &offset)
{
	uint32_t	h = toNybble(str[offset++]) << 4;
	uint32_t	l = toNybble(str[offset++]);

	return (h | l);
}

uint32_t toWord(string &str, int &offset)
{
	uint32_t	h = toByte(str, offset) << 8;
	uint32_t	l = toByte(str, offset);

	return (h | l);
}

uint32_t toAddr(string &str, int &offset)
{
	uint32_t	h = toByte(str, offset) << 16;
	uint32_t	m = toByte(str, offset) << 8;
	uint32_t	l = toByte(str, offset);

	return (h | m | l);
}

void load(char *filename)
{
	ifstream	file(filename);
	string	line;

	if (file.is_open()) {
		cout << ">> Loading S28: " << filename << endl;

		while (!file.eof()) {
			file >> line;
			if (line[0] == 'S') {
				int offset = 2;

				if (line[1] == '1') {
					uint32_t count = toByte(line, offset);
					uint32_t addr = toWord(line, offset);
					count -= 3;
					while (count-- > 0) {
						vm.setByte(addr++, toByte(line, offset));
					}
				}
				else if (line[1] == '2') {
					uint32_t count = toByte(line, offset);
					uint32_t addr = toAddr(line, offset);
					count -= 4;
					while (count-- > 0) {
						vm.setByte(addr++, toByte(line, offset));
					}
				}
			}
		}
		file.close();
	}
	else
		cerr << "Failed to open file" << endl;

}

//==============================================================================
// Command Handler
//------------------------------------------------------------------------------

int main(int argc, char **argv)
{
	int	index = 1;

	setup();

	while (index < argc) {
		if (argv[index][0] != '-') break;

		if (!strcmp(argv[index], "-t")) {
			trace = true;
			++index;
			continue;
		}

		if (!strcmp(argv[index], "-?")) {
			cerr << "Usage: emu816 [-t] s19/28-file ..." << endl;
			return (1);
		}

		cerr << "Invalid: option '" << argv[index] << "'" << endl;
		return (1);
	}

	if (index < argc)
		do {
			load(argv[index++]);
		} while (index < argc);
	else {
		cerr << "No S28 files specified" << endl;
		return (1);
	}

	timespec start, end;

	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);

	vm.reset(trace);
	vm.run();

	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);

	double secs = (end.tv_sec + end.tv_nsec / 1000000000.0)
		    - (start.tv_sec + start.tv_nsec / 1000000000.0);

	double speed = vm.cycles() / secs;

	cout << endl << "Executed " << vm.cycles() << " in " << secs << " Secs";
	cout << endl << "Overall CPU Frequency = ";
	if (speed < 1000.0)
		cout << speed << " Hz";
	else {
		if ((speed /= 1000.0) < 1000.0)
			cout << speed << " KHz";
		else
			cout << (speed /= 1000.0) << " Mhz";
	}
	cout << endl;

	return(0);
}