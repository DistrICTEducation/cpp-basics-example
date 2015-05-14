#pragma once

#include <functional>
#include <string>
#include <vector>


typedef std::vector<std::string> TValues;
typedef std::function<bool (TValues)> THandleLine;

/**
 * @brief LoadCSV
 * @param i_file_path     : the target file path
 * @param i_line_handler  : the callback method for each line parsed
 * @return
 */
bool LoadCSV(const std::string& i_file_path, THandleLine i_line_handler);
