#pragma once

#include <string>

namespace BookClub
{
    struct ILibrary;
}

/**
 * @brief LoadLibraryData
 * @param io_library    : the library
 * @param i_file_path   : the target file path
 * @return whether or not the data was successfully loaded.
 */
bool LoadLibraryCSVData(BookClub::ILibrary& io_library, const std::string& i_file_path);
