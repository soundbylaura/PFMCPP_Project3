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
#include <cmath>
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

Bicycle::Bicycle()
{
    std::cout << "Bicycle" << std::endl;
}

void Bicycle::transportPerson()
{
    std::cout << "A constructor's job is to set up the initial values of the member variables. " <<std::endl; 
}

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

    void beginRecordingSession( ControlRoom controlRoomA);
    void startRateClock( bool hasGroupon = true);
    void closeRoom( ControlRoom controlRoomA, bool equipmentOff = true);
    int billClient( ControlRoom controlRoomA, int hoursUsed = 12, int tapesUsed = 3, int woofersBlown = 3);

    void recordAudio();
    void sendInvoice();
    void hostEvent();
};

RecordingStudio::ControlRoom::ControlRoom()
{
   std::cout << "ControlRoom" << std::endl; 
}

RecordingStudio::RecordingStudio()
{
    std::cout << "RecordingStudio" << std::endl;
}

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
    std::cout << "Constructors give us a way to set up the values of member variables with valid values." << std::endl;
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
void RecordingStudio::hostEvent()
{
    std::cout << "After the compiler allocates the space required by the type, it calls a special function called the constructor." << std::endl;
}


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

AudioInterface::AudioInterface()
{
    std::cout << "AudioInterface" << std::endl;
}

void AudioInterface::receiveAudio(){}
float AudioInterface::displayLevels() { return 2.2f; }
void AudioInterface::outputAudio()
{
    std::cout << "Primitives do not have built-in constructors." << std::endl;
}


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

StereoWidenerAudioPlugin::MixKnob::MixKnob()
{
    std::cout << "MixKnob" << std::endl;
}

StereoWidenerAudioPlugin::StereoWidenerAudioPlugin()
{
    std::cout << "StereoWidenerAudioPlugin" << std::endl;
}

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
    std::cout << "Writing the name of the Type with (); creates the constructor." << std::endl;
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

void StereoWidenerAudioPlugin::captureAudio()
{
    std::cout << "Constructors don't have a return type, not even VOID." << std::endl;
}
char StereoWidenerAudioPlugin::textInfo(){ return 'g'; }
float StereoWidenerAudioPlugin::widenSignal() { return 100.0f; }


struct GraphicalUserInterface
{
    GraphicalUserInterface();
    int GUIWidth = 10;
    int GUIHeight = 10;
    int sliderWidth = 40;
    std::string dialName = "Freq"; 
    std::string backgroundColor = "Purple";

    void displayInputLevel(); 
    float displayAttenuation();
    float parameterMod();
};

GraphicalUserInterface::GraphicalUserInterface()
{
    std::cout << "GraphicalUserInterface" << std::endl;
}

void GraphicalUserInterface::displayInputLevel()
{ 
    std::cout << "The constructor name is the same name as the UDT." << std::endl;
}
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

License::License()
{
    std::cout << "License" << std::endl;
}

char License::displayTextBody() { return 't'; }
char License::website() { return 'w'; }
void License::copyProtection()
{
    std::cout << "If no constructor is written, the compiler uses the Implicit Constructor." << std::endl;
}


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

Company::Company()
{
    std::cout << "Company" << std::endl;
}

void Company::createPlugin(){}
void Company::authEnable(){}
void Company::signContract()
{
    std::cout << "We write constructors with (); to indicate it's a declaration." << std::endl;
}


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
    void savePreset();
};

SignalProcessor::SignalProcessor()
{
    std::cout << "SignalProcessor" << std::endl;
}

double SignalProcessor::changeGainToDecibels( double gainLevel ) 
{
    return std::pow(10.0, gainLevel / 20.0);
}

void SignalProcessor::savePreset()
{
    std::cout << "Step-in is a function in X-code to see how your code changes as it runs." << std::endl;
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

DSPEngine::DSPEngine()
{
    std::cout << "DSPEngine" << std::endl;
}

void DSPEngine::createChorus()
{
    std::cout << "Using a constructor prevents member variables from returning garbage values." << std::endl;
}
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

EqualizerAudioPlugin::EqualizerAudioPlugin()
{
    std::cout << "EqualizerAudioPlugin" << std::endl;
}

float EqualizerAudioPlugin::displayFreqLevelChange() { return 1.0f; }
float EqualizerAudioPlugin::freqLevelChange() { return 5.0f; }
void EqualizerAudioPlugin::buildAType()
{
    std::cout << "A constructor is a Special Member Function that every UDT has." << std::endl;
}
  
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

{
    Bicycle purple; //Note to self: I am instantiating a UDT named 'purple' in the main()
    purple.transportPerson(); //Note to self:  I am calling the member functions of the UDT instance
    purple.rollDownhill();
    purple.repairs();

    std::cout << "Is purple's member variable 'rides' equal to 5? " << (purple.rides == 5 ? " Yes" : " No") << "\n" << std::endl;
}

{
    RecordingStudio soundbylaura;//Note to self: Creates an instance of the RecordingStudio struct named soundbylaura.
    RecordingStudio::ControlRoom controlRoomB;

    controlRoomB.bookRoom( true, 5);
    controlRoomB.prepareRoom( true, true, 1, 5.0f); 
    controlRoomB.caclulateTotalFee( 12.0f, 650.50f, 4.0f);
    //Note to self: Don't forget, calling functions that have arguments here expect direct values, not type declarations.

    std::cout << "Is the room being prepped?" << (controlRoomB.isBooked == true ? " Yes" : " No") << "\n" << std::endl;   

    // soundbylaura.beginRecordingSession( controlRoomB);
    // soundbylaura.startRateClock( true);
    // soundbylaura.closeRoom( controlRoomB, true);
    // soundbylaura.billClient( controlRoomB, 12, 3, 3);

    soundbylaura.hostEvent();
    soundbylaura.recordAudio();
    soundbylaura.sendInvoice();

    std::cout << "Are we hosting an event today:" << (soundbylaura.employees == 0 ? " Yes" : " No") << "\n" << std::endl;
}

{
    AudioInterface studio1810C;
    studio1810C.outputAudio();
    studio1810C.receiveAudio();
    studio1810C.displayLevels();

    std::cout << "The type of audio output is: " << (studio1810C.outputType) << "\n " << std::endl;
}

{
    StereoWidenerAudioPlugin SBLWide;
    SBLWide.captureAudio();
    SBLWide.textInfo();
    SBLWide.widenSignal();

    // void increaseWetness( MixKnob increase);
    // void decreaseWetness( MixKnob decrease);
    // void smartMute( int audioInput = 1, float audioOutput = 1.1f);

    std::cout << "This knob color should be: " << (SBLWide.knobsColors) << "\n" << std::endl;
}

{
    StereoWidenerAudioPlugin::MixKnob mix;
    mix.getStateInformation(int (256), float (0.0f));
    mix.prepareToPlay( 44100.0, 256.0f);
    mix.isBypassed( false, false);

    std::cout << "The name of this knob should be: " << (mix.label) << "\n" << std::endl;
}

{
    GraphicalUserInterface darkMode;
    darkMode.displayInputLevel();
    darkMode.displayAttenuation();
    darkMode.parameterMod();

    std::cout << "In dark mode the background is: " << (darkMode.backgroundColor) << "\n" << std::endl;
}

{
    License EULA;
    EULA.copyProtection();
    EULA.displayTextBody();
    EULA.website();

    std::cout << "Is copy protection initiated? " << (EULA.isExecuted == true ? "Yes" : "No") << "\n" << std::endl;
}

{
    Company SBL;
    SBL.signContract();
    SBL.createPlugin();
    SBL.authEnable();

    std::cout << "The number of employees creating a plugin is: " << (SBL.companyEmployees) << "\n" << std::endl;
}

{
    SignalProcessor comp;
    comp.savePreset();
    comp.changeGainToDecibels( 0.0); 
    comp.processSample( 1.1f);

    std::cout << "Your saved preset name is: " << (comp.type) << "\n" << std::endl;
}

{
   DSPEngine optimum;
    optimum.createChorus();
    optimum.modifyGain();
    optimum.enableOutput();

    std::cout << "Wet level: " << (optimum.wetLevel) << "\n" << std::endl;
}

{
    EqualizerAudioPlugin fancEQ;
    fancEQ.buildAType();
    fancEQ.displayFreqLevelChange();
    fancEQ.freqLevelChange();

    std::cout << "Made by: " << (fancEQ.company.companyName) << "\n" << std::endl;
}
    std::cout << "good to go!" << std::endl;
}
