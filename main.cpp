/*
 Project 3 - Part 5 / 5
 video: Chapter 2 - Part 10
 Scope and Lifetime tasks
 
Create a branch named Part5

 video covered:
    variable scope and lifetime relative to { }
    while loops
    for loops()
 
 tasks
 
 1) add some new member functions to EACH of your types. 
 
 2) inside these new member functions, use while() and for() loops to do something interesting 
         a) example: have a loop that modifies a member variable of some object created outside the loop.
         b) when that member variable reaches a certain threshold, return it mid-loop.
         c) maybe use function parameters to control the starting value of that member variable or control the threshold
         
 3) call those new member functions in main()
 
 4) use std::cout statements to print out information about what your loops did.
    Your code should produce a lot of console output now.

 5) Remember to use pre-increment/decrement in your loops. 
 You can learn why post-increment/decrement is not ideal here:
 https://en.cppreference.com/w/cpp/language/operator_incdec 
 
 6) click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

#include <iostream>
#include <cmath>
namespace Example 
{
struct Bar 
{ 
    int num = 0; 
    Bar(int n) : num(n) { } 
};
struct Foo
{
    Bar scopeLifetimeFunc( int threshold, int startingVal ) //1), 2c) 
    {
        Bar bar(startingVal);                //2a)
        while( bar.num < threshold )         //2a) 
        { 
            ++bar.num;                    //2a), 5)
            std::cout << "  increasing bar.num: " << bar.num << std::endl; //4)
            if( bar.num >= threshold )       //2b)
                return bar;
        }
        
        return Bar {-1}; //if your startingValue >= threshold, the while loop never runs
    }
};

int main()
{
    Foo foo;
    auto bar = foo.scopeLifetimeFunc(3, 1);        //3) 
    
    std::cout << "bar.num: " << bar.num << std::endl;     //4) 
    return 0;
}
}

//call Example::main() in main()





struct Bicycle
{
    Bicycle(); 
    int numGears = 21;
    float tireAirPressure { 70.0f }; //a member variable that IS initialized in-class
    std::string handlebar = "Flat"; //a member variable that IS initialized in-class
    int bottleHolders = 2;
    int rides = { 5 }; //a member variable that IS initialized in-class

    struct Spokes
    {
        Spokes();
        int maxNumSpokes = 8;
        int minNumSpokes = 0;

        void repairSpokes( int spokeNumber );  //NTS: new member function added for S&L task

    };

    void transportPerson();
    void rollDownhill();
    void makeRepairs()
    {
        std::cout << "Make repairs after this many rides: " << rides << std::endl;
    }
};

Bicycle::Bicycle()
{
    std::cout << "Bicycle" << std::endl;
}

Bicycle::Spokes::Spokes()
{
    std::cout << "Spokes" << std::endl;
}

void Bicycle::transportPerson()
{
    std::cout << "A constructor's job is to set up the initial values of the member variables. " <<std::endl; 
}

void Bicycle::rollDownhill()
{
    std::cout << "Roll downhill initial ppi: " << tireAirPressure << ". Required bottle holders: " << bottleHolders << std::endl; //making a member function use initialized member variables via std::cout
}

void Bicycle::Spokes::repairSpokes( int spokeNumber )
{
    while( spokeNumber < 8)
    { 
        ++spokeNumber;
        std::cout << "You are on spoke number: " << spokeNumber << std::endl;
        if( spokeNumber >= maxNumSpokes )
            std::cout << "All spokes fixed." << std::endl;
    } 
}

struct RecordingStudio
{
    RecordingStudio();
    int microphones = 28;
    int numOfClients = 33;
    float expenseCatering { 300.0f };
    float expenseInsurance = 1100.0f;
    int employees {8};
    int discount;

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
        int addOutboardGear(); //NTS: new member function added for S&L task

    };

    void beginRecordingSession( ControlRoom controlRoomA);
    void startRateClock( bool hasGroupon);
    void closeRoom( ControlRoom controlRoomA, bool equipmentOff = true);
    int billClient( ControlRoom controlRoomA, int hoursUsed = 12, int tapesUsed = 3, int woofersBlown = 3);

    void recordAudio()
    {
         std::cout << "Max number of mics allowed: " << microphones << std::endl;   
    }
    void sendInvoice();
    void hostEvent();
    void repairBrokenEquipment(); //NTS: new member function added for S&L task
    void deliverMasterTapes(); //NTS: new member function added for S&L task
};

RecordingStudio::ControlRoom::ControlRoom()
{
   std::cout << "ControlRoom" << std::endl; 
}

RecordingStudio::RecordingStudio()
{
    std::cout << "RecordingStudio" << std::endl;
}

void RecordingStudio::beginRecordingSession( ControlRoom controlRoomA)
{
    controlRoomA.isBooked = false;
}

void RecordingStudio::startRateClock( bool hasGroupon)
{
    if( hasGroupon == false )
        discount = 0;  
}

void RecordingStudio::closeRoom( ControlRoom controlRoomA, bool equipmentOff)
{
    if( equipmentOff == true )
        controlRoomA.isBooked = false;
}

int RecordingStudio::billClient(ControlRoom controlRoomA, int hoursUsed, int tapesUsed, int woofersBlown)
{
    hoursUsed = 4;
    tapesUsed = 4;
    woofersBlown = 4;
    controlRoomA.isBooked = false;

    return hoursUsed + tapesUsed + woofersBlown;
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

void RecordingStudio::sendInvoice(){}
void RecordingStudio::hostEvent()
{
    std::cout << "After the compiler allocates the space required by the type, it calls a special function called the constructor." << std::endl;
}


struct AudioInterface
{
    AudioInterface();
    int audioInputs;
    std::string inputType = "XLR";
    std::string enclosureMaterial = "Metal";
    std::string outputType = "XLR";
    std::string inputsLocation = "Front";

    void receiveAudio()
    {
        std::cout << "Method 1: init member variabies inside the contstructor body." << std::endl;
    }
    float displayLevels();
    void outputAudio();
    void getNumInputs();
    bool turnOnPhantomPower(); //NTS: new member function added for S&L task
    bool turnOnLineInput(); //NTS: new member function added for S&L task
};

AudioInterface::AudioInterface() : audioInputs(16)
{
    std::cout << "Audio Interface" << std::endl;
}

float AudioInterface::displayLevels() { return 2.2f; }
void AudioInterface::outputAudio()
{
    std::cout << "Primitives do not have built-in constructors." << std::endl;
}
void AudioInterface::getNumInputs()
{
    std::cout << "Audio inputs: " << audioInputs << std::endl;
}


struct StereoWidenerAudioPlugin
{
    StereoWidenerAudioPlugin();
    int interfaceElements;
    std::string knobsColors = "Black";
    float memoryAllocated { 64.0f };
    int fontSizeToolTips;
    float knobsLocation { 0.0f };

    struct MixKnob
    {
        MixKnob();
        std::string label = "Mix";
        int sliderHeight = 10; 
        int sliderWidth = 2;
        int ticksOnSlider;
        std::string sliderColor = "Black";

        void getStateInformation( int sizeInBytes, float inputLevel);
        void prepareToPlay( double sampleRate, int samplesPerBlock);
        bool getBypassState( bool customBypassButton, bool nativeBypassButton);
        void calculateTickMarks();
        void changeKnobColor(); //NTS: new member function added for S&L task
        bool useSaturation(); //NTS: new member function added for S&L task

    };

    void increaseWetness( MixKnob increase);
    void decreaseWetness( MixKnob decrease);
    void engageSmartMute( int audioInput = 1, float audioOutput = 1.1f);

    void captureAudio();
    char addTextInfo();
    float widenSignal();
    int showPluginWindow(); //NTS: new member function added for S&L task
    int getPluginWindowSize(); //NTS: new member function added for S&L task

};

StereoWidenerAudioPlugin::MixKnob::MixKnob() : ticksOnSlider(80)
{
    std::cout << "MixKnob" << std::endl;
}

StereoWidenerAudioPlugin::StereoWidenerAudioPlugin() : fontSizeToolTips(18)
{
    std::cout << "StereoWidenerAudioPlugin" << std::endl;
}

void StereoWidenerAudioPlugin::increaseWetness( MixKnob increase)
{
    increase.ticksOnSlider = 50;
}

void StereoWidenerAudioPlugin::decreaseWetness( MixKnob decrease)
{
    decrease.ticksOnSlider = 10;
}

void StereoWidenerAudioPlugin::engageSmartMute( int audioInput, float audioOutput)
{
    audioInput = 2;
    audioOutput = 5.1f;
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
bool StereoWidenerAudioPlugin::MixKnob::getBypassState( bool customBypassButton, bool nativeBypassButton)
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
char StereoWidenerAudioPlugin::addTextInfo() { return 't'; }
float StereoWidenerAudioPlugin::widenSignal() { return 100.0f; }
void StereoWidenerAudioPlugin::MixKnob::calculateTickMarks()
{
    std::cout << "Ticks number: " << ticksOnSlider << std::endl;
}


struct GraphicalUserInterface
{
    GraphicalUserInterface();
    int windowWidth;
    int windowHeight;
    int sliderWidth = 40;
    std::string dialName = "Freq"; 
    std::string backgroundColor = "Purple";

    void showDisplayInputLevel(); 
    int showDisplayAttenuation();
    float addParameterMod();
    int increaseSliderWidth(); //NTS: new member function added for S&L task
    int decreaseFontSize();  //NTS: new member function added for S&L task
    
};

GraphicalUserInterface::GraphicalUserInterface() : windowWidth(50), windowHeight(50)
{
    std::cout << "GraphicalUserInterface" << std::endl;
}

void GraphicalUserInterface::showDisplayInputLevel()
{ 
    std::cout << "The constructor name is the same name as the UDT." << std::endl;
}
int GraphicalUserInterface::showDisplayAttenuation()
{
    std::cout << "Display changed to: " << windowWidth << " x " << windowHeight << std::endl;
    return 34;
}
float GraphicalUserInterface::addParameterMod() { return 44.44f; }


struct License
{
    License();
    std::string bodyText = "You must be this tall to ride this ride.";
    int bodyTextFontSize { 18 };
    std::string fileFormat = "PDF";
    std::string bodyTextColor = "black";
    bool isExecuted { true };

    char displayTextBody();
    char designWebsite();
    void enableCopyProtection();
    void changeTextBodySize(); //NTS: new member function added for S&L task
};

License::License()
{
    std::cout << "License" << std::endl;
}

char License::displayTextBody() { return 't'; }
char License::designWebsite() { return 'w'; }
void License::enableCopyProtection()
{
    std::cout << "If no constructor is written, the compiler uses the Implicit Constructor." << std::endl;
    std::cout << "The correct font size is: " << bodyTextFontSize << std::endl;
}


struct Company
{
    Company();
    std::string companyName = "SBL Plugins";
    std::string companyLocation = "Atlanta";
    int companyEmployees;
    float companyIncome = 0.0f;
    float equipmentCost = 200.25f;

    void createPlugin();
    void authEnable();
    void signContract();
    int hireNewEngineers(); //NTS: new member function added for S&L task
    float buyNewVideoMonitor(); //NTS: new member function added for S&L task
};

Company::Company() : companyEmployees(1)
{
    std::cout << "Company" << std::endl;
}

void Company::createPlugin(){}
void Company::authEnable()
{
    std::cout << "Number of employees authorized: " << companyEmployees << std::endl;
}
void Company::signContract()
{
    std::cout << "We write constructors with (); to indicate it's a declaration." << std::endl;
}


struct SignalProcessor
{
    SignalProcessor();
    float numSamples { 256.0f };
    int numChannels = 2;
    std::string type = "Unknown";
    float numBuffer = 2.2f;
    int program = 2;

    double changeGainToDecibels( double gainLevel );
    float processSample( float inputSample ) { return inputSample * 2; }
    void savePreset();
    void getNumSamples();
    int getNumChannels(); //NTS: new member function added for S&L task
    void startProgram(); //NTS: new member function added for S&L task

};

SignalProcessor::SignalProcessor() : program(4)
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

void SignalProcessor::getNumSamples()
{
    std::cout << "Number of samples available: " << numSamples << std::endl;
}


struct DSPEngine
{
    DSPEngine();
    float gainInputLevel { 0.0f} ;
    float gainRampDuration = 3482.0f;
    float wetLevel = 0.0f;
    std::string effect = "Chorus";
    float gainOutputLevel { -6.4f} ;

    void createChorus();
    float modifyGain();
    bool enableOutput();
    float showGainOutputLevel();
    float increaseWetLevel(); //NTS: new member function added for S&L task
    float decreaseGainRampDuration(); //NTS: new member function added for S&L task
};

DSPEngine::DSPEngine() : wetLevel(100)
{
    std::cout << "DSPEngine" << std::endl;
}

void DSPEngine::createChorus()
{
    std::cout << "Don't forget to define your functions after you declare them. Use verbs (not nouns) for functions." << std::endl;
}
float DSPEngine::modifyGain() { return (gainInputLevel + gainOutputLevel); }
bool DSPEngine::enableOutput() { return true; }
float DSPEngine::showGainOutputLevel()
{
    std::cout << "Gain out: " << gainOutputLevel << std::endl;
    return gainOutputLevel;
}


struct EqualizerAudioPlugin
{
    EqualizerAudioPlugin();
    int IDnumber;
    GraphicalUserInterface interface;
    License license;
    Company company;
    SignalProcessor signalProcessor;
    DSPEngine DSP_Engine;

    float displayFreqLevelChange();
    float freqLevelChange();
    void buildAType();
    void addIdentification();
};

EqualizerAudioPlugin::EqualizerAudioPlugin() : IDnumber(8)
{
    std::cout << "EqualizerAudioPlugin" << std::endl;
}

float EqualizerAudioPlugin::displayFreqLevelChange() { return 1.0f; }
float EqualizerAudioPlugin::freqLevelChange() { return 5.0f; }
void EqualizerAudioPlugin::buildAType()
{
    std::cout << "A constructor is a Special Member Function that every UDT has." << std::endl;
}
void EqualizerAudioPlugin::addIdentification()
{
    std::cout << "Registration number: " << IDnumber << std::endl;
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
    Example::main();

    Bicycle purple; //Note to self: I am instantiating a UDT named 'purple' in the main()
    purple.transportPerson(); //Note to self:  I am calling the member functions of the UDT instance
    purple.rollDownhill();
    purple.makeRepairs();
    // purple.repairSpokes( 0 );

    Bicycle::Spokes wheel;
    wheel.repairSpokes ( 0 );

    std::cout << "Is purple's member variable 'rides' equal to 5? " << (purple.rides == 5 ? " Yes" : " No") << "\n" << std::endl;


    RecordingStudio soundbylaura;//Note to self: Creates an instance of the RecordingStudio struct named soundbylaura.
    RecordingStudio::ControlRoom controlRoomB;//Note to self: Creates an instance of the nested RecordingStudio::ControlRoom struct named controlRoomB.

    controlRoomB.bookRoom( true, 5);
    controlRoomB.prepareRoom( true, true, 1, 5.0f); 
    controlRoomB.caclulateTotalFee( 12.0f, 650.50f, 4.0f);
    //Note to self: Don't forget, calling functions that have arguments here expect direct values, not type declarations.

    std::cout << "Is the room being prepped?" << (controlRoomB.isBooked == true ? " Yes" : " No") << "\n" << std::endl;   

    soundbylaura.beginRecordingSession( controlRoomB);
    soundbylaura.startRateClock( true);
    soundbylaura.closeRoom( controlRoomB, true);
    soundbylaura.billClient( controlRoomB, 12, 3, 3);

    soundbylaura.hostEvent();
    soundbylaura.recordAudio();
    soundbylaura.sendInvoice();

    std::cout << "Are we hosting an event today:" << (soundbylaura.employees == 0 ? " Yes" : " No") << "\n" << std::endl;

    
    AudioInterface studio1810C;
    studio1810C.outputAudio();
    studio1810C.receiveAudio();
    studio1810C.displayLevels();
    studio1810C.getNumInputs();

    std::cout << "The type of audio output is: " << (studio1810C.outputType) << "\n " << std::endl;

    
    StereoWidenerAudioPlugin SBLWide;
    StereoWidenerAudioPlugin::MixKnob mix;
    
    SBLWide.captureAudio();
    SBLWide.addTextInfo();
    SBLWide.widenSignal();

    SBLWide.increaseWetness( mix);
    SBLWide.decreaseWetness( mix);
    SBLWide.engageSmartMute( 1, 1.1f);

    std::cout << "This knob color should be: " << (SBLWide.knobsColors) << "\n" << std::endl;

    mix.getStateInformation(int (256), float (0.0f));
    mix.prepareToPlay( 44100.0, 256.0f);
    mix.getBypassState( false, false);
    mix.calculateTickMarks();

    std::cout << "The name of this knob should be: " << (mix.label) << "\n" << std::endl;

    
    GraphicalUserInterface darkMode;
    darkMode.showDisplayInputLevel();
    darkMode.showDisplayAttenuation();
    darkMode.addParameterMod();

    std::cout << "In dark mode the background is: " << (darkMode.backgroundColor) << "\n" << std::endl;

    
    License EULA;
    EULA.enableCopyProtection();
    EULA.displayTextBody();
    EULA.designWebsite();

    std::cout << "Is copy protection enabled? " << (EULA.isExecuted == true ? "Yes" : "No") << "\n" << std::endl;

    
    Company SBL;
    SBL.signContract();
    SBL.createPlugin();
    SBL.authEnable();

    std::cout << "The number of employees creating a plugin is: " << (SBL.companyEmployees) << "\n" << std::endl;

    
    SignalProcessor comp;
    comp.savePreset();
    comp.changeGainToDecibels( 0.0); 
    comp.processSample( 1.1f);
    comp.getNumSamples();

    std::cout << "Your saved preset name is: " << (comp.type) << "\n" << std::endl;

    
    DSPEngine optimum;
    optimum.createChorus();
    optimum.modifyGain();
    optimum.enableOutput();
    optimum.showGainOutputLevel();

    std::cout << "Wet level: " << (optimum.wetLevel) << "\n" << std::endl;

    
    EqualizerAudioPlugin fancEQ;
    fancEQ.buildAType();
    fancEQ.displayFreqLevelChange();
    fancEQ.freqLevelChange();
    fancEQ.addIdentification();

    std::cout << "Made by: " << (fancEQ.company.companyName) << "\n" << std::endl;

    std::cout << "good to go!" << std::endl;
}
