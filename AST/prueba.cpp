#include "prueba.h"
#include "json.hpp"
#include "fstream"
#include "client.cpp"

using json = nlohmann::json;

prueba::prueba()
{

}
string prueba::called(){

    json J;
    J["type"] = "char";
    J["value"] = "strings";
    J["label"] = "Numerod";
    J["size"] = 1;
    J["countr"] = 1;
    Execute(J.dump());

}
