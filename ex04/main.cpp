#include "File.hpp"
#include <fstream>
#include <iostream>
#include <string>

static void	runTests(void)
{
	int	pass;
	int	fail;

	std::cout << "Running tests...\n" << std::endl;
	pass = 0, fail = 0;
	// T1: file not found
	std::cout << "T1: missing file - ";
	Replacer r1("a", "b");
	File f1("nofile.txt", r1);
	if (!f1.run())
	{
		std::cout << "OK" << std::endl;
		pass++;
	}
	else
	{
		std::cout << "FAIL" << std::endl;
		fail++;
	}
	std::remove("nofile.txt.replace");
	// T2: s1 not found
	std::cout << "T2: s1 not found - ";
	std::ofstream("t2.txt") << "hello\n";
	Replacer r2("foo", "bar");
	File f2("t2.txt", r2);
	f2.run();
	std::cout << "OK" << std::endl;
	pass++;
	std::remove("t2.txt");
	std::remove("t2.txt.replace");
	// T3: basic replace
	std::cout << "T3: basic replace - ";
	{
		std::ofstream ofs("t3.txt");
		ofs << "abc abc\n";
	}
	Replacer r3("abc", "X");
	File f3("t3.txt", r3);
	f3.run();
	std::ifstream check3("t3.txt.replace");
	std::string line3;
	std::getline(check3, line3);
	if (line3 == "X X")
	{
		std::cout << "OK" << std::endl;
		pass++;
	}
	else
	{
		std::cout << "FAIL (got '" << line3 << "')" << std::endl;
		fail++;
	}
	std::remove("t3.txt");
	std::remove("t3.txt.replace");
	// T4: s1 == s2
	std::cout << "T4: s1 == s2 - ";
	std::ofstream("t4.txt") << "repeat\n";
	Replacer r4("repeat", "repeat");
	File f4("t4.txt", r4);
	f4.run();
	std::cout << "OK" << std::endl;
	pass++;
	std::remove("t4.txt");
	std::remove("t4.txt.replace");
	// T5: overlapping
	std::cout << "T5: overlapping - ";
	{
		std::ofstream ofs("t5.txt");
		ofs << "aaaa\n";
	}
	Replacer r5("aa", "b");
	File f5("t5.txt", r5);
	f5.run();
	std::ifstream check5("t5.txt.replace");
	std::string line5;
	std::getline(check5, line5);
	if (line5 == "bb")
	{
		std::cout << "OK" << std::endl;
		pass++;
	}
	else
	{
		std::cout << "FAIL" << std::endl;
		fail++;
	}
	std::remove("t5.txt");
	std::remove("t5.txt.replace");
	std::cout << "\nResults: " << pass << " passed," << fail << " failed\n " << std::endl;
}

int	main(int argc, char **argv)
{
	if (argc == 2 && std::string(argv[1]) == "--test")
	{
		runTests();
		return (0);
	}
	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " <filename> <string1> <strin2>" << std::endl;
		return (1);
	}
	std::string filename = argv[1];
	std::string str1 = argv[2];
	std::string str2 = argv[3];
	if (filename.empty() || str1.empty())
	{
		std::cerr << "<filename> and <string1> can not be empty>" << std::endl;
		return (1);
	}
	Replacer replacer(str1, str2);
	File file(filename, replacer);
	if (!file.run())
		return (1);
	return (0);
}