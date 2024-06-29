/*
 Project 3 - Part 3 / 5
 video: Chapter 2 - Part 8
 Constructors tasks

 Create a branch named Part3

 On this new branch:

 0) if you opted to not fill in any of your member functions in part2, 
    fill in ALL of your member functions
    
 1) Add a constructor for each User-Defined-Type.
    The constructor should be the first declaration in your UDT, before all member variables and member functions.
    add a std::cout message in the constructor that prints out the name of the class being constructed.  
    When you run your code, you'll see the order that your objects are created in the program output. 
 
 2) For each User-Defined-Type:
        amend some of the member functions to print out something interesting via std::cout
 
 3) Instantiate 1 or 2 instances of EACH of your user-defined types in the main() function.  
    You should have at least 12 different variables declared in main(), because you have written 12 different types (including the nested types)

 4) For each instantiated UDT: 
        call each of that instance's member functions.
        You're doing this to show that your code doesn't produce warnings when you call the functions that take arguments.
 
 5) add some std::cout statements in main() that print out your UDT's member variable values or values returned from your UDT member functions (if they return values)
 
 After you finish defining each type/function:
 click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 
 example:
 */

#include <iostream>
namespace Example 
{
struct UDT  // my user defined type named 'UDT'
{
    int thing = 0; //a member variable
    UDT();              //1) the constructor
    void printThing();  //the member function
};

//the function definitions are outside of the class
UDT::UDT()
{
    std::cout << "UDT being constructed!" << std::endl; //1) 
}

void UDT::printThing()
{
    std::cout << "UDT::printThing() " << thing << std::endl;  //2) printing out something interesting
}

int main()
{
    UDT foo;              //3) instantiating a UDT named 'foo' in main()
    foo.printThing();     //4) calling a member function of the UDT instance.
    
    //5) a std::cout statement accessing foo's member variable.
    //It also demonstrates a 'ternary expression', which is syntactic shorthand for an 'if/else' expression
    std::cout << "Is foo's member var 'thing' equal to 0? " << (foo.thing == 0 ? "Yes" : "No") << "\n";
    
    return 0;
}
} //end namespace Example

//insert Example::main() into main() of user's repo.




struct Bicycle
{
    Bicycle();
    int numGears = 18;
    float tireAirPressure = 70.0f;

    std::string handlebar = "Flat";
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
    RecordingStudio();
    int microphones = 28;
    int numOfClients = 33;
    float expenseCatering = 300.0f;
    float expenseInsurance = 1100.0f;
    int employees = 8;

    struct ControlRoom
    {
        ControlRoom();
        bool isBooked = false;
        float ratePerHour = 500.0f;
        std::string consoleType = "Analog";
        bool clientHasEngineer = false;
        int hoursBooked = 8;

        void bookRoom( bool isBooked = true, int numberOfClients = 5);
        void prepareRoom( bool powerOn = true, bool roomCleaned = true, int numberOfAssistants = 1, float rateForAssistant = 5.0f);
        float caclulateTotalFee( float numberOfActualHours = 12.0f, float overtimeRate = 650.50f, float reelsUsed = 4.0f);
    };

    void beginRecordingSession( ControlRoom controlRoomA );
    void startRateClock( bool hasGroupon = true);
    void closeRoom( ControlRoom controlRoomA, bool equipmentOff = true);
    int billClient( ControlRoom controlRoomA, int hoursUsed = 12, int tapesUsed = 3, int woofersBlown = 3);

    void recordAudio();
    void sendInvoice();
    void hostEvent();
};

void RecordingStudio::ControlRoom::bookRoom( bool isRoomBooked, int numberOfTotalClients)
{
    if( isRoomBooked == true )
    {
        numberOfTotalClients = 2;
    }
    else
    {
        numberOfTotalClients = 0;
    }
}

void RecordingStudio::ControlRoom::prepareRoom( bool powerOn, bool roomCleaned, int numberOfAssistants, float rateForAssistant)
{
    if( roomCleaned == true )
    {
        powerOn = true;
        rateForAssistant = 1.1f;
    }
    else
    {
        numberOfAssistants = 1;
    }
}

float RecordingStudio::ControlRoom::caclulateTotalFee( float numberOfActualHours, float overtimeRate, float reelsUsed)
{
    if( numberOfActualHours >= 8 )
    {
        overtimeRate = 2.0f;
    }
    else
    {
        reelsUsed = 2;
    }
    return ( overtimeRate * numberOfActualHours) + reelsUsed;  
}

void RecordingStudio::recordAudio(){}
void RecordingStudio::sendInvoice(){}
void RecordingStudio::hostEvent(){}


struct AudioInterface
{
    AudioInterface();
    int audioInputs = 16;
    std::string inputType = "XLR";
    std::string enclosureMaterial = "Metal";
    std::string outputType = "XLR";
    std::string inputsLocation = "Front";

    void receiveAudio();
    float displayLevels();
    void outputAudio();
};

void AudioInterface::receiveAudio(){}
float AudioInterface::displayLevels() { return 2.2f; }
void AudioInterface::outputAudio(){}


struct StereoWidenerAudioPlugin
{
    StereoWidenerAudioPlugin();
    int GUIElements = 2;
    std::string knobsColors = "Black";
    float memoryAllocated = 64.0f;
    int fontSizeToolTips = 32;
    float knobsLocation = 0;

    struct MixKnob
    {
        MixKnob();
        std::string label = "Mix";
        int sliderHeight = 10; 
        int sliderWidth = 2;
        int ticksOnSlider = 50;
        std::string sliderColor = "Black";

        void getStateInformation( int sizeInBytes, float inputLevel);
        void prepareToPlay( double sampleRate, int samplesPerBlock);
        bool isBypassed( bool customBypassButton, bool nativeBypassButton);
    };

    void increaseWetness( MixKnob increase);
    void decreaseWetness( MixKnob decrease);
    void smartMute( int audioInput = 1, float audioOutput = 1.1f);

    void captureAudio();
    char textInfo();
    float widenSignal();
};

void StereoWidenerAudioPlugin::MixKnob::getStateInformation( int sizeInBytes, float inputLevel)
{
    if( sizeInBytes == 256 )
    {
        inputLevel = 2.0f;
    }
    else
    {
        inputLevel = 0.0f;
    }
}
void StereoWidenerAudioPlugin::MixKnob::prepareToPlay( double sampleRate, int samplesPerBlock)
{
    if( samplesPerBlock == 44100 )
    {
        sampleRate = 2;
    }
    else
    {
        sampleRate = 0;
    }
}
bool StereoWidenerAudioPlugin::MixKnob::isBypassed( bool customBypassButton, bool nativeBypassButton)
{
    if( customBypassButton == true )
    {
        nativeBypassButton = false;
    }
    else
    {
        nativeBypassButton = true;
    }
    return true;
}

void StereoWidenerAudioPlugin::captureAudio(){}
char StereoWidenerAudioPlugin::textInfo() { return 'g'; }
float StereoWidenerAudioPlugin::widenSignal() { return 100.0f; }


struct GraphicalUserInterface
{
    GraphicalUserInterface();
    int GUIWidth = 10;
    int GUIHeight = 10;
    int sliderWidth = 40;
    std::string dialName = "Freq"; 
    std::string backgroundColor = "Purple";

    float displayInputLevel(); 
    float displayAttenuation();
    float parameterMod();
};

float GraphicalUserInterface::displayInputLevel() { return 1.0f; }
float GraphicalUserInterface::displayAttenuation() { return 93.5f; }
float GraphicalUserInterface::parameterMod() { return 44.44f; }


struct License
{
    License();
    std::string bodyText = "You must be this tall to ride this ride.";
    int bodyTextFontSize = 18;
    std::string fileFormat = "PDF";
    std::string bodyTextColor = "black";
    bool isExecuted = true;

    char displayTextBody();
    char website();
    void copyProtection();
};

char License::displayTextBody() { return 't'; }
char License::website() { return 'w'; }
void License::copyProtection(){}

struct Company
{
    Company();
    std::string companyName = "SBL Plugins";
    std::string companyLocation = "Atlanta";
    int companyEmployees = 1;
    float companyIncome = 0.0f;
    float equipmentCost = 200.25f;

    void createPlugin();
    void authEnable();
    void signContract();
};

void Company::createPlugin(){}
void Company::authEnable(){}
void Company::signContract(){}


struct SignalProcessor
{
    SignalProcessor();
    float numSamples = 256.0f;
    int numChannels = 2;
    std::string type = "Unknown";
    float numBuffer = 2.2f;
    int program = 4;

    double changeGainToDecibels( double gainLevel ); 
    float processSample( float inputSample ) { return inputSample * 2; }
    float createSilentSample() { return 0.f; }
};

double SignalProcessor::changeGainToDecibels( double gainLevel ) 
{
    return std::pow(10.0, gainLevel / 20.0);
}


struct DSPEngine
{
    DSPEngine();
    float gainInputLevel = 0.0f;
    float gainRampDuration = 3482.0f;
    float wetLevel = 33.1f;
    std::string effect = "Chorus";
    float gainOutputLevel = -6.4f;

    void createChorus();
    float modifyGain();
    bool enableOutput();
};

void DSPEngine::createChorus(){}
float DSPEngine::modifyGain() { return (gainInputLevel + gainOutputLevel); }
bool DSPEngine::enableOutput() { return true; }


struct EqualizerAudioPlugin
{
    EqualizerAudioPlugin();
    GraphicalUserInterface GUI;
    License license;
    Company company;
    SignalProcessor signalProcessor;
    DSPEngine DSP_Engine;

    float displayFreqLevelChange();
    float freqLevelChange();
    void buildAType();
};

float EqualizerAudioPlugin::displayFreqLevelChange() { return 1.0f; }
float EqualizerAudioPlugin::freqLevelChange() { return 5.0f; }
void EqualizerAudioPlugin::buildAType(){}
  
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
    Example::main(); 

    //add your code here: 
    std::cout << "good to go!" << std::endl;
}
