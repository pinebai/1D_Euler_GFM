#ifndef ERROR_H
#define ERROR_H


#include "input.hpp"
#include "data_storage.hpp"
#include <blitz/array.h>


blitz::Array<double,2> get_cellwise_error (
	
	fluid_state_array& fluid1,
	settingsfile& SF
);


void get_density_errornorms (

	blitz::Array<double,2> cellwise_error,
	double& L1error,
	double& Linferror
);


void get_velocity_errornorms (

	blitz::Array<double,2> cellwise_error,
	double& L1error,
	double& Linferror
);


void get_pressure_errornorms (

	blitz::Array<double,2> cellwise_error,
	double& L1error,
	double& Linferror
);


void output_errornorms_to_file (

	fluid_state_array& fluid1,
	settingsfile& SF
);


void output_cellwise_error (

	fluid_state_array& fluid1,
	settingsfile& SF
);



blitz::Array<double,2> get_twofluid_cellwise_error (
	
	fluid_state_array& fluid1,
	fluid_state_array& fluid2,
	levelset_array& ls,
	settingsfile& SF
);


void output_twofluid_errornorms_to_file (

	fluid_state_array& fluid1,
	fluid_state_array& fluid2,
	levelset_array& ls,
	settingsfile& SF
);



void output_twofluid_cellwise_error (

	fluid_state_array& fluid1,
	fluid_state_array& fluid2,
	levelset_array& ls,
	settingsfile& SF
);



void compute_total_U_onefluid (

	fluid_state_array& fluid1,
	blitz::Array<double,1> U0
);


void update_total_U_onefluid (

	blitz::Array<double,1> FL,
	blitz::Array<double,1> FR,
	blitz::Array<double,1> U,
	double dt
);


void output_conservation_errors_to_file (
	
	blitz::Array<double,1> Ut,
	blitz::Array<double,1> U0,
	double t,
	settingsfile& SF
);


void compute_total_U_twofluid (

	fluid_state_array& fluid1,
	fluid_state_array& fluid2,
	levelset_array& ls, 
	blitz::Array<double,1> U0
);

void update_total_U_twofluid (

	blitz::Array<double,1> FL1,
	blitz::Array<double,1> FR1,
	blitz::Array<double,1> FL2,
	blitz::Array<double,1> FR2,
	levelset_array& ls,
	blitz::Array<double,1> U,
	double dt,
	fluid_state_array& fluid1
);



#endif
