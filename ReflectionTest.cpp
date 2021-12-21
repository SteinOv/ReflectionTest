#include <rttr/registration>
#include <cmath>
#include "WaypointAspectAPI.h"
#include "WorldAPI.h"

#include <iostream>

using namespace rttr;
using namespace std;

RTTR_REGISTRATION
{
    registration::method("pow", select_overload<double(double, double)>(&pow));

    //registration::method("createObject", &(WorldAPI::createObject));
    //registration::method("createPlayer", &(WorldAPI::createPlayer));
    //registration::method("createWaypoint", &(WaypointAspectAPI::createWaypoint));


    
    registration::class_<WorldAPI>("WorldAPI")
        .method("createObject", &WorldAPI::createObject)
        .method("createPlayer", &WorldAPI::createPlayer);

    registration::class_<WaypointAspectAPI>("WaypointAspectAPI")
        .constructor()
        .method("createWaypoint", &WaypointAspectAPI::createWaypoint);


    
}

int main()
{/**/
    std::cout << "Hello World!\n";
    
    variant return_value;

    return_value = type::invoke("pow", { 9.0, 2.0 });
    if (return_value.is_valid() && return_value.is_type<double>()) {
        std::cout << return_value.get_value<double>() << std::endl; // 81
    }

    // option 2
    method meth = type::get_global_method("pow");
    if (meth) // check if the function was found
    {
        return_value = meth.invoke({}, 9.0, 3.0); // invoke with empty instance
        if (return_value.is_valid() && return_value.is_type<double>())
            std::cout << return_value.get_value<double>() << std::endl; // 729
    }

    type waypointAspectAPIReference = type::get_by_name("WaypointAspectAPI");

    variant waypointAspectAPI = waypointAspectAPIReference.create();
    waypointAspectAPIReference.invoke("createWaypoint", waypointAspectAPI, {5});

    method meth2 = waypointAspectAPIReference.get_method("createWaypoint");
    meth2.invoke(waypointAspectAPI, { 6 });

    /*
    WaypointAspectAPI waypointAspectAPI();
    type class_type = type::get_by_name("WaypointAspectAPI");

    method meth2 = type::get_by_name("WaypointAspectAPI").get_method("print_value");
    meth2.invoke(waypointAspectAPI);

    // option 1
    class_type.invoke("createWaypoint", waypointAspectAPI, {5});
    // option 2
    //method createPlayer = class_type.get_method("createWaypoint");
    //createPlayer.invoke(waypointAspectAPI, {6});

    /*
    return_value = type::invoke("createObject", { 5 });

    return_value = type::invoke("createPlayer", { 10 });

    cout << return_value.is_valid() << endl;

    if (return_value.is_valid() && return_value.is_type<int>()) {
        std::cout << "getPlayer returned: " + return_value.get_value<int>() << std::endl;
    }
    /**/


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
