#include "ilibrary.h"

#include <algorithm>
#include <exception>


using namespace BookClub;

namespace
{
    class Library : public ILibrary
    {
        std::vector<Book> m_books;
    public:
        Library() {}

        ~ILibrary() {}

        void AddItem(const Book& i_book) override
        {
            m_items.push_back(i_book);
        }

        void RemoveItem(TFilter i_filter) override
        {
            m_books.erase(std::remove_if(m_books.begin(), m_books.end(), [&i_filter] (const Book& i_book) {
                return i_filter (i_book);
            }));
        }

        const Book& Lookup(TFilter i_filter) const throw (...) override
        {
            auto it = std::find_if(m_books.begin(), m_books.end(), [&i_filter] (const Book& i_book) {
                return i_filter (i_book);
            });
            if (it == m_books.end())
                throw std::exception();
            return *it;
        }

        size_t NumberOfItems() const override
        {
            return m_books.size();
        }
    };
}


ILibraryPtr CreateLibrary()
{
    ILibraryPtr p_library(new Library());
    return std::move(p_library);
}
