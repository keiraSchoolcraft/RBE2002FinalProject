#ifndef SPEED_CONTROLLER
#define SPEED_CONTROLLER

#include <Romi32U4.h>
#include <Position_estimation.h>
#include <vector>
using namespace std;

class SpeedController: public Position
{
    private:
        const float Kp = 0.5; //Adapt the parameters until your robot moves at the speed you command it to drive
        const float Ki = 0.2; 
        float E_left = 0; 
        float E_right = 0;
        int counts = 8; //assignment

    public:
        void Init(void);
        void Run(float, float); //speed left, speed right
        boolean Turn(int,int); //degrees, direction of rotation: 0->left, 1->right
        boolean Straight(int, int); //speed, duration
        boolean Curved(int,int,int); //speed left, speed right, duration
        void Stop(void);
        void setEfforts(int, int);

        vector<vector<float>> waypoints;
};

#endif