#include "json/tst_jsonconvertertest.h"

int main(int argc, char** argv)
{
    int status = 0;
    {
        JsonConverterTest tc;
        status |= QTest::qExec(&tc, argc, argv);
    }
    return status;
}
