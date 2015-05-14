#include "model/ilibrary.h"
#include "view/createlibraryui.h"
#include "utilities/loadlibrarydata.h"


int main()
{
    BookClub::ILibraryPtr p_library = BookClub::CreateLibrary();
    LoadLibraryCSVData(*p_library.get(), "data.csv");
    CreateLibraryUI(*p_library.get());
    return 0;
}

