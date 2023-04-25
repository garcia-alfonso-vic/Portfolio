#ifndef SIMULATION_H
#define SIMULATION_H

#include "../queue/MyQueue.h"
#include <cstdlib>
#include <iomanip>
class Runway
{
    public:
        //CSTOR
        Runway(unsigned int time = 5)
        {
            initial_time = time;
            time_left = 0;
        }
        //function is titled  after a second but could be time 
        void one_second()
        {
            if (is_runway_busy())
                --time_left;
        }
        bool is_runway_busy() const
        {
            return (time_left > 0);
        }
        void start()
        {
            assert(!is_runway_busy());
            time_left = initial_time;
        }
    private:
        unsigned int initial_time;
        unsigned int time_left;
};

class propability
{
    public:
            //CSTOR
            propability(double p = 0.5)
            {
                assert(p >= 0 && "OOPS : propabiltiy is under 0 ");
                assert(p <= 1 && "OOPS : propabiltiy is over 1");
                
                _probability = p;
            }
            // If popability allows, customer has walked in
            bool query() const
            {
                return (rand() < _probability * RAND_MAX);
            }
        private:
            double _probability;
};
class averager
{
    public:
            //CSTOR
            averager() : count(0), sum(0)
            {}
            //MODIFICATION MEMBER FUNCITON
            void next_plane(double value)
            {
                ++count;
                sum += value;
            }
            //CONSTANT MEMEBR FUNCITONS 
            unsigned int how_many_planes() const 
            {
                return count;
            }
            //returns the average of the wait times 
            double average() const
            {
                assert(count > 0);
                return (sum/count);
            }
        private:
            unsigned int count;
            double sum;
};
void simulate_airport(bool debug = true)
{
    //how long it takes for a take off once plane is on the runway 
    unsigned int takeoff_time = 15;      
    //probability of arrival of a plane into the take off line 
    double takeoff_probability = 0.08;
    //how long it takes for a plane to land on the runway in each second
    unsigned int landing_time = 5;       
    //probability of arrival of planes for landing in each second
    double landing_probability = .1;                                    
    //maximum amount of time a plan can stay in  landing queue without crashing
    unsigned int fuel_limit = 20;
    //total time you will run the simulation.
    unsigned int total_time = 1440; // time was originally 1440
    //next plane in the Queue        
    unsigned int next_plane_landing = 0;
    unsigned int next_plane_takeoff = 0;
    bool landing_init = false;
    unsigned int current_second, add_takeoff = 0;
    unsigned int crashed_planes = 0;
    Queue<unsigned int>landing_times;
    Queue<unsigned int>takeoff_times;
    Runway runway;
    propability take_off(takeoff_probability), landing(landing_probability);
    averager average_take_off;
    averager average_landing;
    
    cout<<endl <<"============================================"<<endl;
    if (debug)
    {   
        cout << "n------nSecond: "<< current_second << " ------" << endl;
    }
    //main for loop that simulates a second past
    for (current_second = 1; current_second <= total_time; current_second++)
    {
        if (landing.query())
            landing_times.push(current_second);

        if (  landing_init && (current_second == next_plane_landing + landing_time) )
        {
            takeoff_times.push(current_second);
        }

        if ( (!runway.is_runway_busy()) && ( !landing_times.empty()))
        {
            landing_init = true;
            next_plane_landing = landing_times.front();
            landing_times.pop();

            if (current_second - next_plane_landing > fuel_limit )
            {
                ++crashed_planes;
            }else 
            {
                average_landing.next_plane(current_second - next_plane_landing);
                runway = Runway(landing_time);
                runway.start();
            }
            
        }

        if ((!runway.is_runway_busy()) && landing_times.empty() && (!takeoff_times.empty()))
        {
            next_plane_takeoff = takeoff_times.front();
            if (take_off.query())
            {   
                landing_init = false;
                takeoff_times.pop();
                average_take_off.next_plane(current_second - next_plane_takeoff);
                runway = Runway(takeoff_time);
                runway.start();
            }
        }
        runway.one_second();
    }
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    cout << right << "time to take off" << "\t" << ": " << takeoff_time << endl;
    cout << right << "time to land" << "\t\t" << ": "<< left << landing_time << endl;
    cout << right << "probabilty of landing" << "\t" << ": "<< left << landing_probability << endl;
    cout << right << "probability of takeoff" << "\t" << ": "<< left << takeoff_probability << endl;
    cout << right << "fuel: time to crash" << "\t" << ": "<< left << fuel_limit << endl;
    cout << right << "total simulation time" << "\t" << ": "<< left << total_time << endl;
    cout << endl << endl << endl;
    cout << ". . . . . . . . . . . . . . . . . . . . . . " << endl;

    cout << average_landing.how_many_planes() << " landed" << endl;
    cout << average_take_off.how_many_planes() << " took off";
    cout << crashed_planes << " planes crashed." << endl;
    cout << "Aveage waiting time to land: " << average_landing.average() << endl;
    cout << "Aveage waiting time to takeoff: " << average_take_off.average() << endl;

    // cout << "planese in Landing Queue : " << landing_times.size() << endl;
    // cout << "planes in Takeoff Queue : " << takeoff_times.size() << endl;
     


}
#endif //SIMULATION_H