#include <operatorequal.h>

bool operator==(Personnage const& a, Personnage const& b)
{
    return a.equal(b);
}
