
/*
using Predicate  = std::function<void (const SmartDevie*)>;   //a function that takes single item as input and returns true or false is called a predicate
//whatever you say about the subject is predicate


    filter smart devices and display details of devices of passing the filter the criteria 



void FilterDevices( Predicate fn, const SmartDevice** devices, const unsigned int size );


#functionalities.cpp

void FilterDevices(Predicate fn, const SmartDevice **devices, const unsigned int size)
{
    bool atleastOneMatchingDeviceFound(false);

    for(unsigned int i = 0; i < size; i++) {
        if ( fn( devices[i]) ) {
            std::cout << *devices[i];
            atleastOneMatchingDeviceFound = true;
        }
    }

    if (!atleastOneMatchingDeviceFound) {
        std::cerr << "No matching instance found\n";
    }
}

#main.cpp

create getter for devicetechnology


before deallocation

FilterDevices(   [](const SmartDevice* s) { return s >price() > 6000.0f; },  devices, 3 );

FilterDevices( 
      [](const SmartDevice* s) { return s >deviceTechnology() == Technology::BLUETOOTH; },  devices, 3
       );
*/