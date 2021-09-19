#include <iostream>
#include <cmath>
using namespace std;

class swimmingPool
{
private:
int length; //variable to store length of the pool (in feet)
int width; //variable to store width of the pool (in feet)
int depth; //variable to store depth of the pool (in feet)
int partial; //variable to store the amount of water (if any) currently in the pool
double gallons; //variable to store the gallons the pool holds (l * w * d * 7.5 = g)
int timeFill; //(when calculated) stores the time needed to fill the pool
int timeDrain; //(when calculated) stores the time needed to drain the pool
int gph; //stores the power of the pump used
int differenceFill; //stores the difference between gallons and partial
public:
void gallonsCalc(double); //Calculates the gallons in the pool
void gpmFill(int, double); //Calculates time to fill pool
void gpmDrain(int, double); //Calculates time to drain pool
void fillRemaining(int, double); //Calculates the gallons left to be filled (if partial > 0)
void drainRemaining(int, double); //Calculates the gallons left to be drained
};

//gallons = length * width * depth * 7.5
//partial is entered manually to show if any water is already in the pool.
// If there is, the amount in the pool will be subtracted from the
// product of the above equation.

int main()
{
swimmingPool newPool;

int length;
int width;
int depth;
double gallons;
int partial;
int timeFill;
int timeDrain;
int gph;
int differenceFill;
cout << "Please enter the length, width, and average depth of your pool: " << endl;
cin >> length >> width >> depth;

newPool.gallonsCalc();

cout << "Your pool holds " << gallons << " of water." << endl;
cout << "Please enter the gallons per hour of the pump "
<< "used to fill / empty your pool: " << endl;
cin >> gph;

newPool.gpmFill();
newPool.gpmDrain();

cout << "It will take about " << timeFill
<< " hours to fill your pool." << endl;
cout << "It will take about " << timeDrain
<< " hours to empty your pool." << endl;

cout << "If your pool has been partially filled, please "
<< "enter how many: " << endl;
cin >> partial;

if (partial > gallons)
cout << "Invalid input.";
else if (partial < 0)
cout << "Invalid input.";
else{
newPool.fillRemaining();
}
cout << "The amount of water needed to fill your pool is "
<< differenceFill << "." << endl;
}

void swimmingPool::gallonsCalc(double gallons)
{
gallons = length * width * depth * 7.5;
}

void swimmingPool::gpmFill(int timeFill, double gallons)
{
//time = gallons * GPH (fill)
timeFill = gallons * gph;

}

void swimmingPool::gpmDrain(int timeDrain, double gallons)
{
//time = gallons / GPH (drain)
timeDrain = gallons / gph;

}

void swimmingPool::fillRemaining(int partial, double gallons)
{
//Difference between max capacity(gallons) and what has been filled(partial)
if (partial > 0)
differenceFill = gallons - partial;
else
differenceFill = gallons;
}

void swimmingPool::drainRemaining(int partial, double gallons)
{
//For the purposes of drain, trying to get gallons to 0
//capacity = rate * time, rate = capacity / time, time = capacity / rate
//capacity = gallons, time = timeFill, rate = gph
//gallons = gph * timeFill, gph = gallons / time, time = gallons / gph

int counterDrain = 0;
while(gallons > 0)
{
gallons = gallons - gph;
counterDrain++;
}
}