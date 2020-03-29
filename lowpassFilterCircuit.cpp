#include <cmath>
#include "vec.h"

/* DOCUMENTATION: 

    What is this filter? 

    In order to filter voltage inputs above the critical frequency, I have used a system of 12 first order circuits.
    The output (voltage over the capacitor) is used as the input of the next filter. This could be done through the use 
    of reverse biased diodes, an independent voltage source, or a unity gain amplifer. The later two would probe the 
    voltage over the capacitor and use that as the input for the next system. Because we are limited to 12 initial values,
    we can only tie 11 of these filters attached to an inital RC circuits.

    CALCULATING RC: 

    The RC constant provides some complications. Because our gain of the entire circuit is measured from the last Vout 
    which would be Vo12 (the output of the last voltage) with respect to Vin, our transfer function for the gain would 
    look like:
    
    H(jw) = 1 / (1 + jwRC)^12 

    In order for a frequency to be considered "cutoff", this frequency would have to be above the -3 DB frequency. This 
    is essentially where the gain is equal to sqrt(2)  (b/c -20 log (sqrt(2)) == -3 DB). Thus we can expand the denominator 
    of our transfer fucntion, and solve for the frequency when the magnitude response is -3DB. Rearranging this frequency
    with the given cutoff frequency we get that (wRC) = 0.1212192527871 which we rearrange to get RC with respect to f. This
    step is very important because without it, our corner freqency would be at a freqency much lower than specified. As we
    approach the cutoff frequency, the singal would be almost entirely attenuated (depending on the circuit), exponentially
    increases the error. 


    ISSUES / PONTENTIAL IMPROVEMENTS

    No filter is perfect. Idealy at the cuttoff frequency we would have a discontinuity, where as we approach the frequency
    we have Vin, and at or above the frequency, we ouput 0. In this scenario, at the cuttoff, we have a gain of 0.707 or 
    about root 2, and after this our filter starts to have an attenuating affect where the slope of the gain is -20 db/ decade
    times tweleve as dictated by our transfer fucntion. To improve this, I could make the slope even greater by introducing more 
    filters but given the constraint of 12 initial value problems this was the max that could be done. 


*/
const std::size_t N{ 12 };   // must be <= 12

// Function declarations
vec<N> f( double t, vec<N> y );
double phase( double f );

// Function definitions
vec<N> f( double t, vec<N> y ) {
    const double R{1.0};
    const double C{0.12192527871/(M_PI*R*fc)};

    return vec<N>{  
    y[1]/R/C - y[0]/R/C, 
    y[2]/R/C - y[1]/R/C, 
    y[3]/R/C - y[2]/R/C, 
    y[4]/R/C - y[3]/R/C, 
    y[5]/R/C - y[4]/R/C, 
    y[6]/R/C - y[5]/R/C, 
    y[7]/R/C - y[6]/R/C, 
    y[8]/R/C - y[7]/R/C, 
    y[9]/R/C - y[8]/R/C, 
    y[10]/R/C - y[9]/R/C,
    y[11]/R/C - y[10]/R/C,
    v(t)/R/C - y[11]/R/C
     };
}

// Calculate and return the phase shift of the response
// for a function that has a frequency of 'f'
//  - this likely will depend on the critical frequencey 'fc'
double phase( double f ) {
    // const double R{1.0};
    // const double C{0.12192527871/(M_PI*R*fc)};

    // this simplifies to -12 * arctan(f/fc)
    return -std::atan( f/fc ) * 12;
}
