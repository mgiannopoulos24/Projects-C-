#include "terrain.h"

Terrain::Terrain(std::string name) : name(name), content('.') {}

std::ostream& operator<<(std::ostream& os, const Terrain& t) {
    os << t.content;
    return os;
}
