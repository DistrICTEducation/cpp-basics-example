#include "loadlibrarydata.h"

#include "icsvloader.h"
#include "../model/ilibrary.h"

#include <functional>
#include <vector>
#include <cassert>


using namespace BookClub;

namespace
{
    int _ParseInteger(const std::string& i_integer)
    {
        return atoi(i_integer.c_str());
    }

    Book::ERating _ParseRating(const std::string& i_rating)
    {
        if (i_rating.compare("POOR") == 0)
            return Book::ERating::POOR;
        if (i_rating.compare("AVERAGE") == 0)
            return Book::ERating::AVERAGE;
        if (i_rating.compare("GOOD") == 0)
            return Book::ERating::GOOD;
        if (i_rating.compare("EXCELLENT") == 0)
            return Book::ERating::EXCELLENT;

        return Book::ERating::UNKNOWN;
    }
}

bool LoadLibraryCSVData(ILibrary& io_library, const std::string& i_file_path)
{
    return LoadCSV(i_file_path, [&io_library] (const TValues& i_values) {
        assert(i_values.size() == 4);

        Book book;
        book.m_title = i_values[0];
        book.m_author = i_values[1];
        book.m_rating = _ParseRating(i_values[2]);
        book.m_year = _ParseInteger(i_values[3]);

        io_library.AddItem(book);

        return true;
    });
}
