#ifndef INCLUDE_LIGHTMANAGER_H_
#define INCLUDE_LIGHTMANAGER_H_

#include <string.h>
#include <stdio.h>
#include "vsShaderLib.h"
#include "vsMathLib.h"
#include "frog.h"

#define MAX_LIGHTS 8

#define DIR_LIGHT 1
#define POINT_LIGHT 2
#define SPOT_LIGHT 0
#define MINING_HELM_SPOT 3



struct Light{
	int l_type;				//one of the above types
	
	float l_amb[4];			//light color
	float l_dif[4];
	float l_spec[4];
		
	float l_pos[4];			//used for pointlight cone vertex; 		used for spotlight; 
	float l_dir[4];			//used for pointlight cone basecenter;	used for directionallight;	
	float l_spot_cut;		//used for pointlight cone cut;
};


class LightManager {
private:
	int n_lights;
	int n_spots;
	int n_dirs;
	int n_points;
	bool lights_on;
	Light lights[MAX_LIGHTS];
	VSShaderLib* shader;
	domain::Frog* frog;


public:
	LightManager();
	void init(VSShaderLib* shader, domain::Frog* frog);
	void addLight(float l_spot[4]);
	void addLight(float l_spot[4], float l_dir[4], float l_cut);
	void addLight(float l_dir[4], float l_cut);
	void setLightColor(int light_num, float amb[4], float dif[4], float spec[4]);
	void drawLight(VSMathLib* core);
	void lightsOff();
	void lightsOn();
	inline bool isOn(){return lights_on;}
	inline int getNumLights(){return n_lights;}

private:
	void processSpotLight(int n, Light* l, VSMathLib* core);
	void processDirLight(int n, Light* l, VSMathLib* core);
	void processPointLight(int n, Light* l, VSMathLib* core);
	void processMiningLight(int n, Light* l, VSMathLib* core);
};


#endif
