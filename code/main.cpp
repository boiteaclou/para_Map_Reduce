
#include "MRUtilities.h"
#include "MRWFiles.h"
#include "FileReader.h"
#include "types.h"

int main(int argc, char* argv[])
{
    ifstream f_dtata(argv[1]);
    files_data f_d;

    f_dtata >> f_d.nb_files >> f_d.path;

    f_d.files.resize(f_d.nb_files);
    unsigned i = 0;
    while (f_dtata >> f_d.files[i]) { if (i == (f_d.nb_files - 1)) break; ++i; }
    f_d.files.resize(f_d.nb_files);

    f_dtata.close();

    mr_w_files mr_w(f_d);
    map<string, unsigned> m_p;

    mr_w.start(m_p, thread::hardware_concurrency());

}
