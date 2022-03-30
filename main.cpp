 /*
 Project 3 - Part 2 / 5
 Video: Chapter 2 Part 6
 Implementations tasks
 
Create a branch named Part2

 tasks
 0) delete all of the plain english pseudo-code you added in Part1.
   don't forget to remove the blank lines left behind after you remove your comments
   - you should be left with only your UDTs.
*/
// example:
// if you had something like this at the end of Part1e:
/*
Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#include <iostream>
#include <string>
namespace Part1eVersion 
{
struct CarWash        
{
    //number of vacuum cleaners                     
    int numVacuumCleaners = 3; 
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(float costPerGallon, double fuelAmountInGallons = 2.0, bool requiresDiesel = false);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar( Car car ); 
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}

//this is what I want to see after the code is cleaned up: 
namespace Part2Version
{
struct CarWash        
{
    int numVacuumCleaners = 3; 
    int numEcoFriendlyCleaningSupplies = 20;     
    float waterUsedPerWeek = 200.f;            
    float profitPerWeek = 495.95f;               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    void washAndWaxCar( Car car ); 
    float chargeCustomer(float discountPercentage);
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}
  /*
    The above snippet is just an example showing you how to clean up your code.  
    Do not put your cleaned up code into a namespace like I have done here.

 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below.
 */





 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
    If you have 'unused parameter' warnings, you aren't using one of your function parameters in your implementation.
    Solution: use the parameter in your implementation.

    If you have 'shadows a field of <classname>' warnings, a local variable in the function has the same name as a class member.  
    This local variable could also be a function parameter with the same name as the class member.
    Solution: change the local variable's name so it is different from the class member variable's name.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */


/*
Thing 1) Car Workshop
5 properties: 
    1) number of employees (int)
    2) number of cars to repair (int)
    3) number of parts available (int)
    4) amount of profit made from repairs (float)
    5) number of calls received that day (int)
3 things it can do:
    1) repair car engines
    2) repair car tires
    3) change car windshield
 */
struct CarWorkshop
{
//1) number of employees (int)
    int numEmployees = 10;
//2) number of cars to repair (int)
    int numCarsToRepais = 20;
//3) number of parts available (int)
    int numParts = 200;
//4) amount of profit made from repairs (float)
    float profit = 2000.453f;
//5) number of calls received that day (int)
    int numCalls = 35;

    struct Car // nested type
//Car in "CarWorkshop"
    {
        bool needsNewTires = false;
        bool isTruck = false;
        std::string manufacturer = "Peugeot";
        int numParts = 3;
        std::string model = "2008";
      
        void breakdown(std::string repairType, bool needsNewTires, int newTires);
        void cleanCar(bool detailInterior, bool needsWax, bool hardCleanOutside);
        void loyalClient(int numRepairTimes, float loyalDiscount);
    };
//1) repair car engines
    void repairEngine(Car carA);
//2) repair car tires
    void repairTires(Car carB);
//3) change car windshield
    bool changeWindshield(bool newWindshield);

    Car carIsBeingRepaired;
};
/*
Thing 2) Library
5 properties:
    1) number of books (int)
    2) number of clients (int)
    3) number of employees (int)
    4) number of loans (int)
    5) number of tables (int)
3 things it can do:
    1) lend books
    2) research data base
    3) read books
 */
struct Library
{
//1) number of books (int)
    int numBooks = 2000;
//2) number of clients (int)
    int numClients = 235;
//3) number of employees (int)
    int numEmployees = 6;
//4) number of loans (int)
    int loans = 47;
//5) number of tables (int)
    int tables = 40;

//1) lend books
    void newBookLendRegister();
//2) research data base
    void researchBookInDataBase();
//3) read books
    void readBook();
};
/*
Thing 3) Music Studio
5 properties:
    1) number of instruments (int)
    2) number of input channels (int)
    3) number of speakers (int)
    4) number of tracks recorded (int)
    5) number of engineers (int)
3 things it can do:
    1) record vocals
    2) mix music
    3) use plugins
 */
struct MusicStudio
{
//1) number of instruments (int)
    int numInstruments = 10;
//2) number of input channels (int)
    int numInputChannels = 48;
//3) number of speakers (int)
    int numSpeakers = 6;
//4) number of tracks recorded (int)
    int numTracksRecorded = 150;
//5) number of engineers (int)
    int numEngineers = 2;
    struct Band
    {    
        bool realDrums = false;
        std::string bandName = "Hunt The Dinosaur";
        std::string singleName = "What's your fantasy?";
        bool realBass = false;
        int numGuitars = 5;

        void recordDrums(int numToms, int numMics, int numChannels);
        void recordSong(std::string trackOrder, int trackCount, float sampleRate);
        void band(int numMembers, int epTracks, float pricePerHour);
    };
    
//1) record vocals
    void vocalRecording(Band bandB);
//2) mix music
    void mixMusic(Band bandA);
//3) use plugins   
    bool usePlugins(bool fullAnalog);

    Band isBandRecording;
};
/*
Thing 4) Audio Interface
5 properties:
    1) number of inputs (int)
    2) number of outputs (int)
    3) sample rate (float)
    4) brand (std::string)
    5) weight (float)
3 things it can do:
    1) record instruments
    2) reproduce sound
    3) set gain 
*/
struct AudioInterface
{
//1) number of inputs (int)
    int inputs = 8;
//2) number of outputs (int)
    int outputs = 8;
//3) sample rate (float)
    float sampleRate = 44.1f;
//4) brand (std::string)
    std::string brand = "Antelope";
//5) weight (float)
    float weight = 3.65f;

//1) record instruments
    void recordInstruments();
//2) reproduce sound
    void reproduceSound();
//3) set gain 
    void setGain();
};
/*
Thing 5) CPU
5 properties:
    1) Number of cores (int)
    2) Number of threads (int)
    3) Clock speed (float)
    4) Cache (int)
    5) TDP (int)
3 things it can do:
    1) calculations
    2) run programs
    3) i/o operations
*/
struct CPU 
{
//1) Number of cores (int)
    int cores = 8;
//2) Number of threads (int)
    int threads = 16;
//3) Clock speed (float)
    float clockSpeed = 2.5f;
//4) Cache (int)
    int cache = 16;
//5) TDP (int)
    int TDP = 500;

//1) calculations
    void doCalculations();
//2) run programs
    void runProgram();
//3) i/o operations
    void iOOperations();
};
/*
Thing 6) GPU
5 properties:
    1) Boost clock (float)
    2) Item weight (float)
    3) Cuda cores (double)
    4) Ram size (int)
    5) brand (sdt::string)
3 things it can do:
    1) Video editing
    2) Machine Learning
    3) 3D rendering
*/
struct GPU 
{
//1) Boost clock (float)
    float boostClock = 3.9f;
//2) Item weight (float)
    float weight = 2.5f;
//3) Cuda cores (double)
    double cudaCores = 10787583859;
//4) Ram size (int)
    int ramSize = 16;
//5) brand (sdt::string)
    std::string brand = "MSI";

//1) Video editing
    void videoEditing();
//2) Machine Learning
    void machineLearning();
//3) 3D rendering
    void threeDRendering();
};
/*
Thing 7) RAM
5 properties:
    1) Memory speed (double)
    2) Memory Size (int)
    3) brand (std::string)
    4) length (float)
    5) Voltage (float)
3 things it can do:
    1) Load applications
    2) Edit a spreadsheet
    3) Browsing internet
*/
struct RAM 
{
//1) Memory speed (double)
    double memorySpeed = 300494950303;
//2) Memory Size (int)
    int memorySize = 8;
//3) brand (std::string)
    std::string brand = "Corsair";
//4) length (float)
    float length = 1.56f;
//5) Voltage (float)
    float voltage = 49.6f;

//1) Load applications
    void loadAppliaction();
//2) Edit a spreadsheet
    void editSpreadsheet();
//3) Browsing internet
    void browseInternet();
};
/*
Thing 8) Display
5 properties:
    1) number of pixels (int)
    2) screen size (int)
    3) brightness (int)
    4) refresh rate (int)
    5) response time (int)
3 things it can do:
    1) reproduce image
    2) display information
    3) display video graphics
*/
struct Display
{
//1) number of pixels (int)
    int numPixels = 200;
//2) screen size (int)
    int screenSize = 27;
//3) brightness (int)
    int brightness = 500;
//4) refresh rate (int)
    int refreshRate = 75;
//5) response time (int)
    int responseTime = 1;

//1) reproduce image
    void reproduceImage();
//2) display information
    void displayInfo();
//3) display video graphics
    void displayVideoGraphics();
};
/*
Thing 9) motherboard
5 properties:
    1) number of inputs (int)
    2) brand (std::string)
    3) number of pci slots (int)
    4) Ram Memory size (int)
    5) item weight (float)
3 things it can do:
    1) allows parts to communicate
    2) select boot drive
    3) change bios settings
*/
struct Motherboard
{
//1) number of inputs (int)
    int numInputs = 20;
//2) brand (std::string)
    std::string brand = "MSI";
//3) number of pci slots (int)
    int numPCISlots = 2;
//4) Ram Memory size (int)
    int ramSize = 8;
//5) item weight (float)
    float weight = 2.45f;

//1) allows parts to communicate
    void allowCommunication();
//2) select boot drive
    void selectBootDrive();
//3) change bios settings
    void biosSettings();
};
/*
Thing 10) Computer
5 properties:
    1) CPU 
    2) GPU 
    3) RAM 
    4) Display 
    5) Keyboard 
3 things it can do:
    1) create plugins
    2) mix music
    3) browse the internet
*/
struct Computer
{
//1) CPU
    CPU cpu;
//2) GPU 
    GPU gpu;
//3) RAM 
    RAM ram;
//4) Display 
    Display display;
//5) Motherboard 
    Motherboard motherboard;

//1) create plugins
    void createPlugin();
//2) mix music
    void mixMusic();
//3) browse the internet
    void browseInternet();
};
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{
    std::cout << "good to go!" << std::endl;
}
