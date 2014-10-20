#ifndef INCLUDE_DRAWABLE_H_
#define INCLUDE_DRAWABLE_H_

#include "vsMathLib.h"
#include "vsResSurfRevLib.h"

#define LEFT_X_LIMIT 17
#define RIGHT_X_LIMIT -4
#define SPEED_INC 0.1f

#define DIR_FRONT 0
#define DIR_BACK 1
#define DIR_LEFT 2
#define DIR_RIGHT 3
#define DIR_UP 4
#define DIR_DOWN 5

namespace domain {

class Drawable {

protected:
	float second_in_game;
	float speed;

public:

	virtual void draw(VSMathLib* core) = 0;
	virtual void tick() = 0;

};
}

#endif
