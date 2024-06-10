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
 If your code produces -Wconversion warnings, do NOT use static_cast<> to solve the warnings.  
 Casting has not been covered yet.
 Change your code so that no warnings are produced WITHOUT using casting.
 This usually means you have to use identical types for all variables used in an expression that is producing that conversion warning.
 */

struct Bicycle
{

    //number of gears (int)
    int numGears = 18;
    //amount of air required in tires in PSI (float)
    float tireAirPressure = 70.0f;
    //type of handlebars (std::string)
    std::string handlebar = ("Drop" "Flat");
    //number of water bottle holders (int)
    int bottleHolders = 3;
    //number of times used per week (int)
    int rides = 5;

    //3 things it can do:
    // transport a person
    void transportPerson();

    // roll down a hill
    void rollDownhill();

    // need repairs
    void repairs();
};
/*

Thing 2) Recording Studio

*/
struct RecordingStudio
{

    //number of microphones (int)
    int microphones = 28;
    //number of clients (int)
    int numOfClients = 33;
    //cost of food needed per week (float)
    float expenseCatering = 300.0f;
    //cost of business insurance (float)
    float expenseInsurance = 1100.0f;
    //number of employees (int)
    int employees = 8;

    struct ControlRoom
    {
        bool isBooked = false;
        float ratePerHour = 500.0f;
        std::string consoleType = "Analog";
        bool clientHasEngineer = false;
        int hoursBooked = 8;

        void bookRoom (bool isBooked = true, int numberOfClients = 5);
        void prepareRoom (bool powerOn = true, bool roomCleaned = true, int numberOfAssistants = 1, float rateForAssistant = 5.0f);
        int caclulateTotalFee (int numberOfActualHours = 12, float overtimeRate = 650.50f, int tapesUsed = 4);
    };

    void beginRecordingSession (ControlRoom controlRoomA);

    void startRateClock (bool hasGroupon = true);

    void closeRoom (ControlRoom controlRoomA, bool equipmentOff = true);

    int billClient (ControlRoom controlRoomA, int hoursUsed = 12, int tapesUsed = 3, int woofersBlown = 3);

    //3 things it can do:
    // record audio
    void recordAudio();

    // send invoices to clients
    void sendInvoice();

    // host events
    void hostEvent();
};
/*

Thing 3) Audio Interface

*/
struct AudioInterface
{

    //number of inputs (int)
    int audioInputs = 16;
    //types of inputs (std::string)
    std::string inputType = ("XLR" "TRS" "MIDI" "Optical");
    //types of enclosure material (std::string)
    std::string enclosureMaterial = ("Metal" "Plastic");
    //types of outputs (std::string)
    std::string outputType = ("XLR" "TRS" "MIDI" "Optical" "RCA");
    //locations of inputs (std::string)
    std::string inputsLocation = ("Front" "Back");

    //3 things it can do:
    // receive audio signals
    void receiveAudio();

    // display signal levels
    float displayLevels(); //return is displayed for user

    // output audio signals
    void outputAudio();
};
/*

Thing 4) Stereo Widener Audio Plugin

*/
struct StereoWidenerAudioPlugin
{

    //number of GUI elements (int)
    int GUIElements = 2;
    //color of interface elements (std::string)
    std::string knobsColors = ("Black" "Gray" "Red");
    //amount of memory required (float)
    float memoryAllocated = 64.0f;
    //font size of tool tips (int)
    int fontSizeToolTips = 32;
    //location of interface elements within GUI (float)
    float knobsLocation = 0;

    struct MixKnob
    {
        std::string label = "Mix";
        int sliderHeight = 10; 
        int sliderWidth = 2;
        int ticksOnSlider = 50;
        std::string sliderColor = "Black";

        void getStateInformation (int sizeInBytes, float inputLevel);
        void prepareToPlay (double sampleRate, int samplesPerBlock);
        bool isBypassed (bool customBypassButton, bool nativeBypassButton);

    };

    void increaseWetness (MixKnob increase);
    void decreaseWetness (MixKnob decrease);
    void smartMute (int audioInput = 1, float audioOutput = 1.1f);

    //3 things it can do:
    // capture audio signal
    void captureAudio();

    // display text descriptions
    char textInfo(); //return is displayed for user

    // widen audio signal
    float widenSignal(); //return is related to function parameter
};
/*

Thing 5) Graphical User Interface

*/
struct GraphicalUserInterface
{

    //width in cm (int)
    int GUIWidth = 10;
    //height in cm (int)
    int GUIHeight = 10;
    //number of frequency selector dials (int)
    int freqDialsQuantity = 3;
    //names of frequency selector dials (std::string)
    std::string freqDialsNames = ("Freq" "Gain" "Q");
    //color of background (std::string)
    std::string backgroundColor = "Purple";

    //3 things it can do:
    // display input level
    float displayInputLevel(); //return is displayed for user

    // display attenuation level(s) of frequency band(s)
    float displayAttenuation(); //return is displayed for user

    // allow user to modify parameters
    float parameterMod(); //return is related to function parameter
};
/*

Thing 6) License

*/
struct License
{

    //text (std::string)
    std::string bodyText = "You must be this tall to ride this ride.";
    //font size (int)
    int bodyTextFontSize = 18;
    //format (std::string)
    std::string fileFormat = "PDF";
    //text color (std::string)
    std::string bodyTextColor = "black";
    //executed (bool)
    bool isExecuted = true;

    //3 things it can do:
    // provide information
    char displayTextBody(); //return is displayed for user

    // link to manufacturer website
    char website(); //return is actionable by user

    // not be copied
    void copyProtection();
};
/*

Thing 7) Company

*/
struct Company
{

    //name (std::string)
    std::string companyName = "SBL Plugins";
    //location (std::string)
    std::string companyLocation = "Atlanta";
    //number of employees (int)
    int companyEmployees = 1;
    //amount of income per year (float)
    float companyIncome = 0.0f;
    //cost of office equipment (float)
    float equipmentCost = 200.25f;

    //3 things it can do:
    // create plugins
    int createPlugin(); //return is related to function parameter

    // set authorization methods
    void authEnable();

    // sign legal agreements
    void signContract();
};
/*

Thing 8) Signal Processor

*/
struct SignalProcessor
{

    //samples (float)
    float numSamples = 256.0f;
    //channels (int)
    int numChannels = 2;
    //type (std::string)
    std::string type = "Unknown";
    //buffer (float)
    float numBuffer = 2.2f;
    //program (int)
    int program = 4;

    //3 things it can do:
    // receive audio
    void receiveAudio();

    // convert raw audio level to decibels
    float convertToDecibels(); //return is related to function parameter

    // send audio
    void sendAudio();
};
/*

Thing 9) DSP Engine

*/
struct DSPEngine
{

    //value of incoming gain (double)
    double gainInputLevel = 0;
    //duration of gain ramp (double)
    double gainRampDuration = 3482;
    //amount of effect (float)
    float wetLevel = 33.1f;
    //name of effect (std::string)
    std::string effect = ("Chorus" "Phase" "Flange");
    //value of output level (float)
    float gainOutputLevel = -6.4f;

    // 3 things it can do:
    // create a chorus effect
    void createChorus();

    // modify gain level
    float modifyGain(); //return is related to function parameter

    // disable output
    bool outputEnabled(); //return is related to function parameter
};
/*

Thing 10) Equalizer Audio Plugin

*/
struct EqualizerAudioPlugin
{

    //Graphical User Interface
    GraphicalUserInterface GUI;
    //license
    License license;
    //company
    Company company;
    //signal processor
    SignalProcessor signalProcessor;
    //DSP engine
    DSPEngine DSP_Engine;

    // 3 things it can do:
    // display changes to frequency level
    float displayFreqLevelChange(); //return is displayed for user

    // attenuate audio frequency level
    float freqLevelChange(); //return is related to function parameter

    // accomodate multiple hosts
    void buildType();
};

  
/*
=================
Part 1e - Step 18: Commit
=================
Now that you've made changes, make a commit!
Be sure to make the commit message meaningful.
*/

/*
=================
Part 1e - Step 19: Request a review
=================
*/
} // end namespace Part1E_Instructions

/*
paste your code below
*/









int main()
{
    std::cout << "good to go!" << std::endl;
}
