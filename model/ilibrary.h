#pragma once

#include "book.h"

#include <vector>
#include <functional>
#include <memory>


namespace BookClub
{
    struct ILibrary;
    typedef std::unique_ptr<ILibrary> ILibraryPtr;

    struct ILibrary
    {
        typedef std::function<bool (const Book&)> TFilter;

        /**
         * \brief Adds the new book to the library.
         * @param i_book the book to be added.
         */
        virtual void AddItem(const Book& i_book) = 0;

        /**
         * \brief Removes all the books from the library that match the filter.
         * @param i_filter
         */
        virtual void RemoveItem(TFilter i_filter) = 0;

        /**
         * \brief Find the first book in the library that matches the filter.
         * @param  i_filter
         * @return the item matching the filter.
         */
        virtual const Book& Lookup(TFilter i_filter) const throw (...) = 0;

        /**
         * @brief NumberOfItems
         * @return the number of items in the library
         */
        virtual size_t NumberOfItems() const = 0;

        virtual ~ILibrary() {}
    };

    /**
     * @brief CreateLibrary
     * @return an ILibrary instance.
     */
    ILibraryPtr CreateLibrary();
}
