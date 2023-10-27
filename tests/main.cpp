#include "assure.h"

int main(int argc, char* arg[])
{
    bool result = assure::AssureSession::getInstance().excute();
    return result ? 0 : 1;
}
