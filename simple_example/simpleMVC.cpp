#include <iostream>
#include <string>

using namespace std;


class modelGPIOStates
{
    private:
        bool inputState;
        bool outputState;

    public:
        modelGPIOStates():inputState(0),outputState(0){}
        
        void setInputState(bool userExpectedInput)
        {
            inputState = userExpectedInput;
        }

        void setOutputState(bool userOutput)
        {
            outputState = userOutput;
        }

        bool getInputState()
        {
            return inputState;
        }
        

};

class viewGPIOStates 
{
    public:
        void readInputState(bool currentInputState) const
        {
            cout<<"system input state "<<currentInputState<<endl;
        }
        void readOutputState(bool currentOutputState)
        {
            cout<<"system output state "<<currentOutputState<<endl;
        }

};

class gpiocController
{
    const viewGPIOStates &viewGPIOstates;
    modelGPIOStates &gpioModel;

    public:
        gpiocController(const viewGPIOStates &viewInstanceRef, modelGPIOStates &gpioRefInstanceRef):
        viewGPIOstates{viewInstanceRef},gpioModel{gpioRefInstanceRef}{}
        
        void setUserInput(modelGPIOStates &gpioModel ,bool userInput)
        {
            gpioModel.setInputState(userInput);
        }

        void setUserOutput( modelGPIOStates &gpioModel ,bool userOutput)
        {
            gpioModel.setOutputState(userOutput);
        }

        void readGPIOInputStatus() const 
        {
            cout<<"user requesting GPIO states data"<<endl;
            viewGPIOstates.readInputState(gpioModel.getInputState());
        }

};

int main() 
{
    viewGPIOStates viewInstance;
    modelGPIOStates modelInstance;

    gpiocController controllerInstance(viewInstance,modelInstance);

    controllerInstance.readGPIOInputStatus();


}
