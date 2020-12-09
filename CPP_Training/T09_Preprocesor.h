#ifndef T09_PREPROCESOR_H
#define T09_PREPROCESOR_H

#define DEBUG 0

#include <iostream>

//nemashe zadaci od ovoj del
void zadaca09_01()
{

#if DEBUG

    std::cout << "DEBUG:" << std::endl;

    std::cout << "__LINE__ = " << __LINE__ << std::endl
              << "__FILE__ = " << __FILE__ << std::endl
              << "__DATE__ = " << __DATE__ << std::endl
              << "__TIME__ = " << __TIME__ << std::endl
              << "__TIMESTAMP__ = " << __TIMESTAMP__ << std::endl;
#else

    std::cout << "RELEASE:" << std::endl;

    std::cout << "__LINE__ = " << __LINE__ << std::endl
              << "__FILE__ = " << __FILE__ << std::endl
              << "__DATE__ = " << __DATE__ << std::endl
              << "__TIME__ = " << __TIME__ << std::endl
              << "__TIMESTAMP__ = " << __TIMESTAMP__ << std::endl;
#endif


}

#endif // T09_PREPROCESOR_H
