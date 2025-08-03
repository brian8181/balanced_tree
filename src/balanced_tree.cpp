//    File:    makefile
//    Date:    Sun Dec 15 05:46:02 PM CST 2024
// Version:    0.0.1

#include <stdlib.h>
#include <unistd.h>         /* for STDIN_FILENO */
#include <sys/select.h>     /* for pselect   */
#include <getopt.h>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "bash_color.hpp"
#include "tree.hpp"
#include "node.hpp"

using std::string;
using std::stringstream;
using std::vector;
using std::cout;
using std::cerr;
using std::endl;

const string VERSION_STRING = "0.0.1";
const int DEFAULT_ARGC = 0;
const unsigned short VERBOSE          = 0x01;
const unsigned short DEFAULTS         = 0x00;
const unsigned short FIELDS           = 0x02;
unsigned short options = DEFAULTS;
char DELIMITER = ',';

#ifdef DEBUG
	#define log_(s) log(s)
	#else
	#define log_(s) // log
#endif

static struct option long_options[] =
{
        {"verbose", no_argument, 0, 'v'},
        {"help", no_argument, 0, 'h'},
        {"version", no_argument, 0, 'r'},
};

unsigned short OPTION_FLAGS = DEFAULTS;

void log(string s)
{
	cout << s << endl;
}

void print_version()
{
	cout << VERSION_STRING << endl;
}

void print_help()
{
	cout	<< endl
			<< FMT_BOLD      << FMT_FG_GREEN << "Usage: " << FMT_RESET << endl
			<< FMT_BOLD      << /*~ "${APP_NAME}"         << ~*/ FMT_RESET << " "
			<< FMT_FG_BLUE   << "[-hvr][...]"             << FMT_RESET << " "
         												  <<  endl << endl;
}

int parse_options(int argc, char* argv[])
{
	int opt = 0;
	int option_index = 0;
	optind = 0;
	while ((opt = getopt_long(argc, argv, "hv ", long_options, &option_index)) != -1)
	{
		switch (opt)
		{
			case 'h':
				print_help();
			case 'v':
				print_version();
				return 0;
		}
	}

	if (argc < DEFAULT_ARGC) // not correct number of args
	{
		cerr << "Expected argument after options, -h for help" << endl;
		return -1;
	}

	string path = argv[0];   // get exe file path
	cout << argv[0] << endl;

	// node<int> root;
	// root.set_value(20);
	// node<int> n1;
	// n1.set_value(20);
	// node<int> n2;
	// n2.set_value(6);
	// node<int> n3;
	// n3.set_value(21);
	// tree<int> t;
	// t.insert(&root);
	// t.insert(&n1);

	// std::list<node<int>*> nodes;
	// t.get_all( nodes );

	// std::list<node<int>*>::iterator end = nodes.end();
	// for(std::list<node<int>*>::iterator iter = nodes.begin(); iter != end; ++iter)
	// {
	// 	std::cout << (*iter)->get_value() << endl;
	// }

	vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41 };
	tree<int> t(v);


	// stringstream ss;
	// ss << "Boo! - " << " file:" << __FILE__ << " line:" << __LINE__ << endl;
	// string s = ss.str();
	// log_(s);

	// comment

	return 0;
}



int stdin_ready (int filedes)
{
	// initialize the file descriptor set
	fd_set set;
	FD_ZERO(&set);
	FD_SET(filedes, &set);
#ifndef CYGWIN
	// declare/initialize timespec
	struct timespec timeout = { .tv_sec = 0 };
	return pselect(filedes + 1, &set, NULL, NULL, &timeout, NULL);
#else
	// declare/initialize timeout
	struct timeval timeout = { .tv_sec = 0 };
	return select(filedes + 1, &set, NULL, NULL, &timeout);
#endif
}


int main(int argc, char* argv[])
{
	try
	{
		if(stdin_ready(STDIN_FILENO))
		{
			std::string buffer;
			std::cin >> buffer;
			// add piped buffer to end of argv
			char* argvtmp[sizeof(char*) * argc+1];
			memcpy(argvtmp, argv, sizeof(char*) * argc);
			argvtmp[argc] = &buffer[0];
			argv = argvtmp;
			++argc;
		}
		return parse_options(argc, argv);
	}
	catch(std::logic_error& ex)
	{
	 	std::cout << ex.what() << std::endl;
	}
}
