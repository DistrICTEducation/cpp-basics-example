#include "icsvloader.h"

#include <iostream>
#include <fstream>


bool LoadCSV(const std::string& i_file_path, THandleLine i_line_handler)
{
    std::string line;
    std::ifstream csv_file(i_file_path);
    if (csv_file.is_open())
    {
        while (std::getline(csv_file, line) )
        {
            TValues values;
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
