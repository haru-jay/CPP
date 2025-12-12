#include "sed.hpp"

int main(int argc, char *argv[])
{
	if (argc != 4 || !argv[1] || !argv[2] || !argv[3])
	{
		std::cerr << "Parameter error" << std::endl;
		return 1;
	}
	std::string file_name = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	if (file_name.empty() || s1.empty())
	{
		std::cerr << "Parameter is empty" << std::endl;
		return 1;
	}
	std::string file_contents = "";
	std::string tmp;
	std::ifstream open_file(file_name.c_str());
	std::ofstream make_file((file_name + ".replace").c_str());
	
	if(open_file.is_open())
	{
		while (std::getline(open_file, tmp))
		{
			size_t pos = 0;
			while ((pos = tmp.find(s1, pos)) != std::string::npos)
			{
				tmp.erase(pos, s1.length());
				tmp.insert(pos, s2);
				pos += s2.length();
			}
			file_contents += tmp + '\n';
		}
		if (!file_contents.empty())
			file_contents.erase(file_contents.length() - 1);
		if (make_file.is_open())
			make_file << file_contents;
		open_file.close();
		make_file.close();
	}
	return 0;
}