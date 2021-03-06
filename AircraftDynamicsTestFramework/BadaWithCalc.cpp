// ****************************************************************************
// NOTICE
//
// This is the copyright work of The MITRE Corporation, and was produced
// for the U. S. Government under Contract Number DTFAWA-10-C-00080, and
// is subject to Federal Aviation Administration Acquisition Management
// System Clause 3.5-13, Rights In Data-General, Alt. III and Alt. IV
// (Oct. 1996).  No other use other than that granted to the U. S.
// Government, or to those acting on behalf of the U. S. Government,
// under that Clause is authorized without the express written
// permission of The MITRE Corporation. For further information, please
// contact The MITRE Corporation, Contracts Office, 7515 Colshire Drive,
// McLean, VA  22102-7539, (703) 983-6000. 
//
// Copyright 2018 The MITRE Corporation. All Rights Reserved.
// ****************************************************************************

#include "aaesim/BadaWithCalc.h"
#include "public/AircraftCalculations.h"
#include "utility/constants.h"
#include <cstdlib>

using namespace std;

BadaWithCalc::BadaWithCalc(void)
{
    cout << "BadaWithCalc.cpp: Implement this class!" << endl;
    ac_mass = mass.m_ref;   // default
}

BadaWithCalc::~BadaWithCalc(void)
{
}

/**
 * getAircraftParameters() does two things:
 *
 * 1.  Loads the data files by calling init(), if not already done.
 * 2.  Sets ac_mass based on the percentile.
 */
void BadaWithCalc::getAircraftParameters(string aircraft_type, double mass_percentile)
{
// INPUTS:
//   aircraft type
// OUTPUTS:
//   struct ac:
//       ac.mass, ac.ref_mass: kg
//       ac.S: m^2
//       ac.__.cd0,cd2,gear: unitless
//       ac.__.Vstall: kts (CAS)


}


// Gets configuration when flying trajectory 

//-----------------
// INPUTS:
//   ac: aircraft parameter structure
//   Calibrated air speed, V_cas: kts
//   alt: altitude in meters.
//   altAtFAF: altitude at FAF (or
//   last waypoint) in meters.
// OUTPUTS:
//   cd0,cd2,gear: drag coefficients for the specific configuration
void BadaWithCalc::getConfig(
    Units::Speed V_cas, /** [in] Calibrated airspeed in knots */
        Units::Length alt,         /** [in] Altitude in meters */
        Units::Length altAtFAF,    /** [in] Altitude at final approach fix in meters */
    int modeLast,       /** [in] previous flap configuration (0-3) */
        double &cd0,        /** [out] parasitic drag coefficient */
        double &cd2,        /** [out] induced drag coefficient */
        double &gear,       /** [out] landing gear drag coefficient */
        int &mode           /** [out] flap configuration (0-3):
            0=cruise, 1=approach, 2=landing, 3=gear down */)
{

}



// Gets configuration for trajectory building.

//-----------------
// INPUTS:
//   ac: aircraft parameter structure
//   Calibrated air speed, V_cas: kts
//   alt: altitude in meters.
//   altAtFAF: altitude at FAF (or
//   last waypoint) in meters.
// OUTPUTS:
//   cd0,cd2,gear: drag coefficients for the specific configuration
void BadaWithCalc::getConfigTrajGen(
	Units::Speed V_cas,     /** [in] Calibrated airspeed in knots */
        double alt,             /** [in] Altitude in meters */
        Units::Length altAtFAF, /** [in] Altitude at final approach fix */
        double &cd0,            /** [out] parasitic drag coefficient */
        double &cd2,            /** [out] induced drag coefficient */
        double &gear,           /** [out] landing gear drag coefficient */
        int &mode           	/** [out] flap configuration (0-3):
            0=cruise, 1=approach, 2=landing, 3=gear down */)
{

}

// Configures Aircraft is extra drag is needed and speed is less than max configuration speed

//-----------------
// INPUTS:
//   ac: aircraft parameter structure
//   Calibrated air speed, V_cas: kts
//   alt: altitude in meters.
//   altAtFAF: altitude at FAF (or
//   last waypoint) in meters.
// OUTPUTS:
//   mode: configuration
void BadaWithCalc::getConfigForDrag(
    Units::Speed V_cas, /** [in] Calibrated airspeed in knots */
        double alt,         /** [in] Altitude in meters */
        double altAtFAF,    /** [in] Altitude at final approach fix in meters */
        int modeLast,       /** [in] previous flap configuration (0-3) */
        int &mode           /** [out] flap configuration (0-3):
            0=cruise, 1=approach, 2=landing, 3=gear down */)
{
	
}


// gets maximum aircraft thrust, takes input as altitude in Meters
double BadaWithCalc::getMaxThrust(Units::Length h, int mode, string type)
{
	double Tmax = 0;

	return Tmax;
}

void BadaWithCalc::setFlapsSpeeds(string acType) {

}


BadaWithCalc& BadaWithCalc::operator=(const BadaWithCalc &obj)
{

	// Generic = operator.
	//
	// obj:BadaWithCalc object to set with.
	// returns this object with new values.

	if (this != &obj)
	{
		this->Bada::operator=(obj);

		this->ac_mass = obj.ac_mass;
		this->flapsSpeeds = obj.flapsSpeeds;
	}

	return *this;

}


bool BadaWithCalc::operator==(const BadaWithCalc &obj) const
{

  bool match = this->Bada::operator==(obj);

  match = match && (this->ac_mass == obj.ac_mass);

  match = match && (this->flapsSpeeds.VappMin == obj.flapsSpeeds.VappMin);
  match = match && (this->flapsSpeeds.VappMax == obj.flapsSpeeds.VappMax);
  match = match && (this->flapsSpeeds.VlndMin == obj.flapsSpeeds.VlndMin);
  match = match && (this->flapsSpeeds.VlndMax == obj.flapsSpeeds.VlndMax);
  match = match && (this->flapsSpeeds.VgearMin == obj.flapsSpeeds.VgearMin);
  match = match && (this->flapsSpeeds.VgearMax == obj.flapsSpeeds.VgearMax);

  return match;

}


bool BadaWithCalc::operator!=(const BadaWithCalc &obj) const
{

  // Generic not equals operator.
  //
  // obj:comparison object.
  // returns true if obj doesn't match.
  //         false if obj matches.

  return !this->operator==(obj);

}
