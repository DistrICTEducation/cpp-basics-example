#include "icsvloader.h"

#include <iostream>
#include <fstream>


namespace
{
    const char* g_delimiter = ",";

    void _StringSplit(const std::string& i_string_to_split, const std::string& i_delimiter, std::vector<std::string>& o_tokens)
    {
        size_t pos = 0;
        std::string string_to_split(i_string_to_split);
        std::string token;
        while ((pos = string_to_split.find(i_delimiter)) != std::string::npos)
        {
            token = string_to_split.substr(0, pos);
            o_tokens.push_back(token);
            string_to_split.erase(0, pos + i_delimiter.length());
        }
    }
}

bool LoadCSV(const std::string& i_file_path, THandleLine i_line_handler)
{
    std::string line;
    std::ifstream csv_file(i_file_path);
    if (csv_file.is_open())
    {
        while (std::getline(csv_file, line) )
        {
            TValues values;
            _StringSplit(line, g_delimiter, values);
            if (! i_line_handler(values))
                return false;
        }
        csv_file.close();
        return true;
    }
    else
    {
        return false;
    }
}
