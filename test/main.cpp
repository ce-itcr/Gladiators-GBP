#include "default/tst_default.h"

int main(int argc, char** argv)
{
    int status = 0;
    {
        Default tc;
        status |= QTest::qExec(&tc, argc, argv);
    }
    return status;
}
