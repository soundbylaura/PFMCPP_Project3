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
struct Limb{};

struct Person
{
    Limb leftFoot;
    Limb rightFoot;

    int age;
    int height;
    float hairLength;
    float GPA;
    unsigned int SATScore;
    int distanceTraveled;

    void run( int howFast, bool startWithLeftFoot);
    void stepForward();
    int stepSize();
};

void Person::run( int howFast, bool startWithLeftFoot)
{
    if( startWithLeftFoot == true )
    {
        void (distanceTraveled += howFast);
    }
    else
     {
        void (distanceTraveled -= howFast);//illogical but didn't want to copy over from video, makes code work.
    }
}
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
    int numGears = 18;
    float tireAirPressure = 70.0f;
    std::string handlebar = ("Drop" "Flat");
    int bottleHolders = 3;
    int rides = 5;

    void transportPerson();
    void rollDownhill();
    void repairs();
};

void Bicycle::transportPerson(){}
void Bicycle::rollDownhill(){}
void Bicycle::repairs(){}


struct RecordingStudio
{
    int microphones = 28;
    int numOfClients = 33;
    float expenseCatering = 300.0f;
    float expenseInsurance = 1100.0f;
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
        int caclulateTotalFee (int numberOfActualHours = 12, float overtimeRate = 650.50f, int reelsUsed = 4);
    };

    void beginRecordingSession (ControlRoom controlRoomA);
    void startRateClock (bool hasGroupon = true);
    void closeRoom (ControlRoom controlRoomA, bool equipmentOff = true);
    int billClient (ControlRoom controlRoomA, int hoursUsed = 12, int tapesUsed = 3, int woofersBlown = 3);

    void recordAudio();
    void sendInvoice();
    void hostEvent();
};
void RecordingStudio::ControlRoom::bookRoom (bool isRoomBooked, int numberOfTotalClients)
{
    if( isRoomBooked == true )
    {
        void (numberOfTotalClients = 2);
    }
    else
    {
        void (numberOfTotalClients = 0);
    }
}
void RecordingStudio::ControlRoom:: prepareRoom (bool powerOn, bool roomCleaned, int numberOfAssistants, float rateForAssistant)
{
    if( roomCleaned == true )
    {
        void (powerOn == true);
        void (rateForAssistant = 1.1f);
    }
    else
    {
        void (numberOfAssistants = 1);
    }
}
int RecordingStudio::ControlRoom::caclulateTotalFee (int numberOfActualHours, float overtimeRate, int reelsUsed)
{
    if( numberOfActualHours >= 8)
    {
        void (overtimeRate = 2.0f);
    }
    else
    {
        void (reelsUsed = 2);
    }
        {
        return 2;
        }
}
void RecordingStudio::recordAudio(){}
void RecordingStudio::sendInvoice(){}
void RecordingStudio::hostEvent(){}


struct AudioInterface
{
    int audioInputs = 16;
    std::string inputType = ("XLR" "TRS" "MIDI" "Optical");
    std::string enclosureMaterial = ("Metal" "Plastic");
    std::string outputType = ("XLR" "TRS" "MIDI" "Optical" "RCA");
    std::string inputsLocation = ("Front" "Back");

    void receiveAudio();
    float displayLevels();
    void outputAudio();
};
void AudioInterface::receiveAudio(){}
float AudioInterface::displayLevels()
    {
    return 2.2f;
    }
void AudioInterface::outputAudio(){}


struct StereoWidenerAudioPlugin
{
    int GUIElements = 2;
    std::string knobsColors = ("Black" "Gray" "Red");
    float memoryAllocated = 64.0f;
    int fontSizeToolTips = 32;
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

    void captureAudio();
    char textInfo();
    float widenSignal();
};
void StereoWidenerAudioPlugin::MixKnob::getStateInformation(int sizeInBytes, float inputLevel)
{
    if( sizeInBytes == 256)
    {
        void (inputLevel = 2.0f);
    }
    else
    {
        void (inputLevel = 0.0f);
    }
}
void StereoWidenerAudioPlugin::MixKnob::prepareToPlay(double sampleRate, int samplesPerBlock)
{
    if( samplesPerBlock == 44100)
    {
        void (sampleRate = 2);
    }
    else
    {
        void (sampleRate = 0);
    }
}
bool StereoWidenerAudioPlugin::MixKnob::isBypassed(bool customBypassButton, bool nativeBypassButton)
{
    if( customBypassButton == true )
    {
        void (nativeBypassButton == false);
        return 0;
    }
    else
    {
        void (nativeBypassButton == true);
        return 0;
    }
}
void StereoWidenerAudioPlugin::captureAudio(){}
char StereoWidenerAudioPlugin::textInfo()
    {
    return 'g';
    }
float StereoWidenerAudioPlugin::widenSignal()
    {
    return 100.0f;
    }


struct GraphicalUserInterface
{
    int GUIWidth = 10;
    int GUIHeight = 10;
    int freqDialsQuantity = 3;
    std::string freqDialsNames = ("Freq" "Gain" "Q");
    std::string backgroundColor = "Purple";

    float displayInputLevel(); 
    float displayAttenuation();
    float parameterMod();
};

float GraphicalUserInterface::displayInputLevel()
    {
    return 1.0f;
    }
float GraphicalUserInterface::displayAttenuation()
    {
    return 93.5f;
    }
float GraphicalUserInterface::parameterMod()
    {
    return 44.44f;
    }


struct License
{
    std::string bodyText = "You must be this tall to ride this ride.";
    int bodyTextFontSize = 18;
    std::string fileFormat = "PDF";
    std::string bodyTextColor = "black";
    bool isExecuted = true;

    char displayTextBody();
    char website();
    void copyProtection();
};
char License::displayTextBody()
    {
    return 't';
    }


struct Company
{
    std::string companyName = "SBL Plugins";
    std::string companyLocation = "Atlanta";
    int companyEmployees = 1;
    float companyIncome = 0.0f;
    float equipmentCost = 200.25f;

    int createPlugin();
    void authEnable();
    void signContract();
};
int Company::createPlugin()
    {
        return 1;
    }
void Company::authEnable(){}
void Company::signContract(){}


struct SignalProcessor
{
    float numSamples = 256.0f;
    int numChannels = 2;
    std::string type = "Unknown";
    float numBuffer = 2.2f;
    int program = 4;

    void receiveAudio();
    float convertToDecibels();
    void sendAudio();
};
void SignalProcessor::receiveAudio(){}
float SignalProcessor::convertToDecibels()
    {
        return 0;
    }
void SignalProcessor::sendAudio(){}


struct DSPEngine
{
    double gainInputLevel = 0;
    double gainRampDuration = 3482;
    float wetLevel = 33.1f;
    std::string effect = ("Chorus" "Phase" "Flange");
    float gainOutputLevel = -6.4f;

    void createChorus();
    float modifyGain();
    bool outputEnabled();
};


struct EqualizerAudioPlugin
{
    GraphicalUserInterface GUI;
    License license;
    Company company;
    SignalProcessor signalProcessor;
    DSPEngine DSP_Engine;

    float displayFreqLevelChange();
    float freqLevelChange();
    void buildType();
};
float EqualizerAudioPlugin::displayFreqLevelChange()
    {
        return 1.0f;
    }
float EqualizerAudioPlugin::freqLevelChange()
    {
        return 5.0f;
    }
void EqualizerAudioPlugin::buildType(){}
  
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
// end namespace Part1E_Instructions

/*
paste your code below
*/









int main()
{
    std::cout << "good to go!" << std::endl;
}
