/*
Project 3 - Part 1e / 5
Video:  Chapter 2 Part 5
User-Defined Types

Continue your work on branch Part1

Purpose: The entire purpose of this 5-part project is to get you writing C++ code that compiles and to 
reinforce the syntax habits that C++ requires.  
What you create in this project will be used as the basis of Project 5 in the course.   

************************
Part1 purpose:  Learn to write UDTs

You are going to write 10 UDTs in project3.  
Part1 will be broken up into 5 separate steps
    Part 1a: you will learn to think about an object in terms of its sub-objects.
    Part 1b: you will write 4 un-related UDTs in plain english
    Part 1c: you will write 1 UDT in plain english that will be made of 5 related sub-objects
    Part 1d: you will write plain-english UDTs for the 5 sub-objects that form the UDT defined in Part 1c
    Part 1e: you will convert those 10 plain-english UDTs into code that runs.
************************

Convert your 10 Plain-english UDTs into code.

I recommend compiling after finishing each one and making sure it compiles 
without errors or warnings before moving on to writing the next UDT. 

1) define an empty struct below your plain-english UDT. i.e.:

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

#if false //ignore these #if #endif lines. they're just here to prevent compiler errors.
struct CarWash
{

};
#endif
/*
    - Do this for all 10 UDTs

2) Below your plain-english UDT, Copy your 5 properties & 3 actions into the empty struct body.
    - comment them out.
    - Do this for all 10 UDTs
    
3) declare your member variables and member functions underneath each plain-english comment in your struct's body.
    - give the member variables relevant data types
    - Do this for all 10 UDTs
    - if your functions return something other than 'void', add a comment explaining what is being returned.  see the example code below.
 
4) make the function parameter list for those member functions use some of your User-Defined Types
    - You'll write definitions/implementations for these functions in Project3 Part2
    - you'll call each of these functions in Project3 part3
    - Do this for all 10 UDTs
 
5) make 2 of the 10 user-defined types have a nested class.  
    - this nested class also needs 5 properties and 3 actions.
    - these nested classes are not considered one of your 10 UDTs.
    - this nested class must be related to the class it is nested inside
 
6) your 10th UDT's properties should be instances of your #5-#9 UDTs.   
    - No primitives allowed!
 
7) After you finish defining each type, click the [run] button.  
    Clear up any errors or warnings as best you can. 
    if your code produces a [-Wpadded] warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

/*
 example:  

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

struct CarWash //                                   1) define an empty struct for each of your 10 types.       
{
    //number of vacuum cleaners                     2) copied and commented-out plain-english property
    int numVacuumCleaners = 3; //                   3) member variables with relevant data types.
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car //5)                                 Note that the nested type 'Car' is related to the 'CarWash' 
    {
        //2) member variables with relevant data types.  the names are appropriate for the U.D.T.'s purpose.
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        //3) a member function.  it has multiple arguments, some with default values.
        //the parameter names are related to the work the function will perform.
        void fillTank(float costPerGallon, double fuelAmountInGallons = 2.0, bool requiresDiesel = false);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips); //3) returns the number of miles traveled
    };

    //wash and wax car
    void washAndWaxCar(Car carA); //4) a member function whose parameter is a UDT.
    //charge customer
    float chargeCustomer(float discountPercentage); //3) returns the total amount charged.
    //detail the car interior
    void detailInterior(Car carB);
    
    //5) a member variable whose type is a UDT.
    Car carBeingServiced;  

    /*
    Pay attention to the member functions that take an instance of 'Car'
    Notice that there is a member variable of the same type.

    It makes sense to pass a Car to the function 'washAndWaxCar' because car washes service MANY cars
    However, they only service ONE car at a time.
    the carBeingServiced's value would change every time you wash and wax the car. 

    I see many students who write code emulating this format, but their usage does not make logical sense.  
    Consider the following snippet:

    struct SoccerTeam
    {
        struct Manager
        {
            ...
        };

        // train their skills
        void trainPlayerSkills(Manager managerA);
    
        Manager teamManager;
    };

    It does not make sense to pass in a new Manager whenever you are going to train your team players.
    Soccer teams have ONE manager.

    a much more relevant usage would be adding a member function that hires a new manager:

    struct SoccerTeam
    {
        struct Manager
        {
            ...
        };

        void hireNewManager(Manager newManager);
    
        Manager teamManager;
    };

    We can safely assume that the 'Manager' instance that is being passed in will be replacing the current 'teamManager' variable without looking at any other code.
    This is because the function name and function argument clearly indicate what they are/what they do.

    Your function names and parameter names should make LOGICAL SENSE.
    Readers of your code should be able to INTUITIVELY understand what your function implementations will do without actually seeing the implementations.

    Keep this in mind when you define your UDTs in this project part.
    */
};

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
    int cpu = 1;
//2) GPU 
    int gpu = 2;
//3) RAM 
    int ram = 8;
//4) Display 
    int display = 2;
//5) Keyboard 
    int keyboard = 1;

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
