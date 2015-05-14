#pragma once

#include <string>


namespace BookClub
{
    struct Book
    {
        enum ERating
        {
            UNKNOWN     = 0,
            POOR        = 1,
            AVERAGE     = 2,
            GOOD        = 3,
            EXCELLENT   = 4
        };

        std::string m_title;
        std::string m_author;
        ERating     m_rating;
        int         m_year;
    };
}
