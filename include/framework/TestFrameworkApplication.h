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

#pragma once
#include "public/AircraftState.h"
#include "public/AircraftIntent.h"
#include "framework/IMSpeedCommandFile.h"
#include "loader/Loadable.h"
#include "public/Guidance.h"
#include "public/SimulationTime.h"
#include "framework/TestFrameworkDynamics.h"
#include <string>
#include <vector>
#include <map>

class TestFrameworkApplication : public Loadable
{
 public:
  TestFrameworkApplication (void);
  ~TestFrameworkApplication (void);

  Guidance update(const SimulationTime &simTime,
		  TestFrameworkDynamics &dynamics,
		  AircraftState state_in,
		  Guidance guidance_in);

  bool load(DecodedStream *input);

  // Conditionals
  bool is_loaded();

private:

  // Interval Management classes
  IMSpeedCommandFile mIMSpeedCommandFile;

  //Input Data
  std::string application_type;

  bool loaded;

};
